import jwt from "jsonwebtoken";
import sinon from "sinon";
import { auth, firestore } from "../admin.js";
import { expect } from "chai";
import { token } from "../index.js";
import "dotenv/config";

const EXPECTED_CLIENT_ID = process.env.JWT_AUDIENCE;
const EXPECTED_CLIENT_SECRET = process.env.JWT_CLIENT_SECRET;

// TOKEN HTTP ENDPOINT UNIT TESTS
describe("Token HTTP endpoint tests", function () {
    // Values to hold the response of actual calls to the token HTTP endpoint
    let actualResponseCode = -1;
    let actualResponse = {};

    // Prepare HTTP response
    const res = {
        send: (obj) => {
            actualResponse = obj;
        },
        status: (code) => {
            actualResponseCode = code;
            return res;
        }
    };

    // Prevent console from creating output during tests
    before(function () {
        sinon.stub(console, "log");
        sinon.stub(console, "error");
    });

    after(function () {
        sinon.restore();
    });

    // Reset response code and value before each test
    beforeEach(function () {
        actualResponseCode = -1;
        actualResponse = {};
    });

    // Request - Client ID Missing
    it("should fail if the request is missing a Client ID", async function () {
        // Prepare HTTP request
        const req = {
            body: {
                client_secret: EXPECTED_CLIENT_SECRET,
                grant_type: "authorization_code",
                refresh_token: {}
            }
        };

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');
    });

    // Request - Invalid Client ID
    it("should fail if the request contains an invalid Client ID", async function () {
        // Prepare HTTP request
        const req = {
            body: {
                client_id: "id",
                client_secret: EXPECTED_CLIENT_SECRET,
                grant_type: "authorization_code",
                refresh_token: {}
            }
        };

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');
    });

    // Request - Client Secret Missing
    it("should fail if the request is missing a Client Secret", async function () {
        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                grant_type: "authorization_code",
                refresh_token: {}
            }
        };

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');
    });

    // Request - Invalid Client Secret
    it("should fail if the request contains an invalid Client Secret", async function () {
        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                client_secret: "secret",
                grant_type: "authorization_code",
                refresh_token: {}
            }
        };

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');
    });

    // Request - Grant Type Missing
    it("should fail if the request is missing a Grant Type", async function () {
        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                client_secret: EXPECTED_CLIENT_SECRET,
                refresh_token: {}
            }
        };

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');
    });

    // Request - Invalid Grant Type
    it("should fail if the request contains an invalid Grant Type", async function () {
        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                client_secret: EXPECTED_CLIENT_SECRET,
                grant_type: "grant",
                refresh_token: {}
            }
        };

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');
    });

    // Authorization Code - Invalid User ID Token
    it("should fail if the authorization code is invalid", async function () {
        sinon.stub(auth, "verifyIdToken").withArgs("some_code").rejects();

        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                client_secret: EXPECTED_CLIENT_SECRET,
                code: "some_code",
                grant_type: "authorization_code",
                refresh_token: {}
            }
        };

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');

        // Restore stubs
        auth.verifyIdToken.restore();
    });

    // Authorization Code - Missing Code
    it("should fail if the authorization code is missing", async function () {
        sinon.stub(auth, "verifyIdToken").withArgs("").rejects();

        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                client_secret: EXPECTED_CLIENT_SECRET,
                grant_type: "authorization_code",
                refresh_token: {}
            }
        };

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');

        // Restore stubs
        auth.verifyIdToken.restore();
    });

    // Authorization Code - Success
    it("should succeed if passed a valid authorization code", async function () {
        // Prepare stubs
        sinon.stub(auth, "verifyIdToken").withArgs("some_code").resolves({ uid: 123 });
        sinon.stub(auth, "getUser").withArgs(123).resolves({ uid: 456 });
        sinon.stub(jwt, "sign")
            .onFirstCall().returns({
                sub: 456,
                aud: EXPECTED_CLIENT_ID
            })
            .onSecondCall().returns({
                sub: 456,
                aud: EXPECTED_CLIENT_ID,
                expiresIn: "1h"
            });
        sinon.stub(jwt, "verify").returns({
            sub: 456,
            aud: EXPECTED_CLIENT_ID
        });
        sinon.stub(firestore, "doc").withArgs("users/456").returns({
            set: (refresh_token) => sinon.stub().resolves()
        });

        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                client_secret: EXPECTED_CLIENT_SECRET,
                code: "some_code",
                grant_type: "authorization_code",
                refresh_token: { aud: "incorrect_audience" }
            }
        }

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(200);
        expect(actualResponse).to.have.property('token_type', "Bearer");
        expect(actualResponse).to.have.property('access_token').to.have.property('sub', 456);
        expect(actualResponse).to.have.property('access_token').to.have.property('aud', EXPECTED_CLIENT_ID);
        expect(actualResponse).to.have.property('access_token').to.have.property('expiresIn', "1h");
        expect(actualResponse).to.have.property('refresh_token').to.have.property('sub', 456);
        expect(actualResponse).to.have.property('refresh_token').to.have.property('aud', EXPECTED_CLIENT_ID);
        expect(actualResponse).to.have.property('expires_in', 3600);

        // Restore stubs
        auth.verifyIdToken.restore();
        auth.getUser.restore();
        jwt.sign.restore();
        jwt.verify.restore();
        firestore.doc.restore();
    });

    // Refresh Token - Invalid "aud" (Client ID/Audience)
    it("should fail if the refresh token contains the incorrect client ID/audience", async function () {
        // Prepare stubs
        sinon.stub(jwt, "verify").returns({
            sub: 123,
            aud: "wrong_audience"
        });

        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                client_secret: EXPECTED_CLIENT_SECRET,
                grant_type: "refresh_token",
                refresh_token: `{ aud: "incorrect_audience", sub: 123 }`
            }
        };

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');

        // Restore stubs
        jwt.verify.restore();
    });

    // Refresh Token - Missing "aud" (Client ID/Audience)
    it("should fail if the refresh token is missing a client ID/audience", async function () {
        // Prepare stubs
        sinon.stub(jwt, "verify").returns({
            sub: 123
        });

        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                client_secret: EXPECTED_CLIENT_SECRET,
                grant_type: "refresh_token",
                refresh_token: `{ aud: "incorrect_audience", sub: 123 }`
            }
        };

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');

        // Restore stubs
        jwt.verify.restore();
    });

    // Refresh Token - Invalid "sub" (User ID/Subject)
    it("should fail if the refresh token contains the incorrect user ID/subject", async function () {
        // Prepare stubs
        sinon.stub(jwt, "verify").returns({
            sub: 999,
            aud: EXPECTED_CLIENT_ID
        });
        sinon.stub(auth, "getUser").withArgs(999).rejects();

        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                client_secret: EXPECTED_CLIENT_SECRET,
                grant_type: "refresh_token",
                refresh_token: `{ sub: 999 }`
            }
        };

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');

        // Restore stubs
        jwt.verify.restore();
        auth.getUser.restore();
    });

    // Refresh Token - Missing "sub" (User ID/Subject)
    it("should fail if the refresh token is missing a user ID/subject", async function () {
        // Prepare stubs
        sinon.stub(jwt, "verify").returns({
            aud: EXPECTED_CLIENT_ID
        });
        sinon.stub(auth, "getUser").withArgs().rejects();

        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                client_secret: EXPECTED_CLIENT_SECRET,
                grant_type: "refresh_token",
                refresh_token: `{ aud: ${EXPECTED_CLIENT_ID} }`
            }
        };

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');

        // Restore stubs
        jwt.verify.restore();
        auth.getUser.restore();
    });

    // Refresh Token - User Token and Requested Token Mismatch
    it("should fail if the user's token and request token do not match", async function () {
        // Prepare stubs
        sinon.stub(jwt, "verify").returns({
            sub: 123,
            aud: EXPECTED_CLIENT_ID
        });
        sinon.stub(auth, "getUser").withArgs(123).resolves({ uid: 456 });
        sinon.stub(firestore, "doc").returns({
            get: sinon.stub().resolves({
                data: sinon.stub().returns({
                    refresh_token: {
                        sub: -1,
                        aud: "wrong_audience"
                    }
                })
            })
        });


        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                client_secret: EXPECTED_CLIENT_SECRET,
                grant_type: "refresh_token",
                refresh_token: `{ aud: EXPECTED_CLIENT_ID }`
            }
        }

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');

        // Restore stubs
        jwt.verify.restore();
        auth.getUser.restore();
        firestore.doc.restore();
    });

    // Refresh Token - Missing Token
    it("should fail if the refresh token is missing", async function () {
        // Prepare stubs
        sinon.stub(jwt, "verify").withArgs("").throws();

        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                client_secret: EXPECTED_CLIENT_SECRET,
                grant_type: "refresh_token"
            }
        };

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(400);
        expect(actualResponse).to.have.property('error', 'invalid_grant');

        // Restore stubs
        jwt.verify.restore();
    });

    // Refresh Token - Success
    it("should succeed if passed a valid refresh token", async function () {
        // Prepare stubs
        sinon.stub(jwt, "verify")
            .onFirstCall().returns({
                sub: 123,
                aud: EXPECTED_CLIENT_ID
            })
            .onSecondCall().returns({
                sub: 123,
                aud: EXPECTED_CLIENT_ID
            });
        sinon.stub(auth, "getUser").withArgs(123).resolves({ uid: 456 });
        sinon.stub(firestore, "doc").withArgs("users/456").returns({
            get: sinon.stub().resolves({
                data: sinon.stub().returns({
                    refresh_token: {
                        sub: 123,
                        aud: EXPECTED_CLIENT_ID
                    }
                })
            })
        });
        sinon.stub(jwt, "sign").returns({
            sub: 123,
            aud: EXPECTED_CLIENT_ID,
            expiresIn: "1h"
        });

        // Prepare HTTP request
        const req = {
            body: {
                client_id: EXPECTED_CLIENT_ID,
                client_secret: EXPECTED_CLIENT_SECRET,
                grant_type: "refresh_token",
                refresh_token: {
                    sub: 123,
                    aud: EXPECTED_CLIENT_ID
                }
            }
        }

        // Trigger the token HTTP endpoint with the predefined request and response
        await token(req, res);

        // Assert results
        expect(actualResponseCode).to.equal(200);
        expect(actualResponse).to.have.property('token_type', "Bearer");
        expect(actualResponse).to.have.property('access_token').to.have.property('sub', 123);
        expect(actualResponse).to.have.property('access_token').to.have.property('aud', EXPECTED_CLIENT_ID);
        expect(actualResponse).to.have.property('access_token').to.have.property('expiresIn', "1h");
        expect(actualResponse).to.have.property('expires_in', 3600);

        // Restore stubs
        jwt.verify.restore();
        auth.getUser.restore();
        firestore.doc.restore();
        jwt.sign.restore();
    });
});
