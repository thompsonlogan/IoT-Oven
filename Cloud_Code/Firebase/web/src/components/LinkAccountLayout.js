/*
* The component that is presented to the user, prompting them to link their
* account with the Google Assistant, allowing them to use it to interact
* with their device.
*/
function LinkAccountLayout(props) {
    const auth = props.auth;
    const here = new URL(window.location.href);
    const searchParams = here.searchParams;

    return (
        <div className='link-account'>
            <h1>Link Spectrum Brands with Google</h1>
            <p>Signed in as {auth.currentUser.email}.</p>
            <p>Review Google's <a href="https://policies.google.com">Privacy Policy</a>.</p>
            <p>You may unlink <a href="https://myaccount.google.com/">here</a>.</p>
            <button onClick={async () => await props.logOut(auth)}>Cancel</button>
            <button onClick={async () => {
                let next = new URL(searchParams.get('redirect_uri'));
                let code = await generateAuthCode(auth, searchParams).then(c => code = c);
                let state = searchParams.get('state');

                next.searchParams.append('code', code);
                next.searchParams.append('state', state);

                window.location.href = next.toString();
            }}>Agree and Link</button>
        </div>
    );
}

/*
 * Generates an authorization code for the specified user request.
 */
function generateAuthCode(auth, searchParams) {
    const allowedRedirects = [
        'https://oauth-redirect.googleusercontent.com',
        'https://oauth-redirect-sandbox.googleusercontent.com',
        'https://developers.google.com'
    ];

    // Verify the request contains the necessary parameters
    if (!searchParams.has('client_id')
        || !searchParams.has('response_type')
        || !searchParams.has('redirect_uri')
        // Client id matches expected value
        || searchParams.get('client_id') !== "google_spectrumbrands_identifier"
        // Client is requesting an authorization code
        || searchParams.get('response_type') !== 'code'
        // Client requests a redirect to a known host
        || !allowedRedirects.some((element, _index, _array) => searchParams.get('redirect_uri').startsWith(element))) {
        console.error('Invalid Link Request');
        return "";
    }

    return auth.currentUser.getIdToken();
}

export default LinkAccountLayout;
