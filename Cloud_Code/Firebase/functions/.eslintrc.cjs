module.exports = {
  root: true,
  env: {
    es6: true,
    node: true,
    mocha: true,
  },
  extends: [
    "eslint:recommended",
    "google",
    "plugin:mocha/recommended"
  ],
  parserOptions: {
    "ecmaVersion": "latest",
    "sourceType": "module",
  },
  rules: {
    "quotes": [ "error", "double" ],
    "object-curly-spacing": [ "warn", "always" ],
    "max-len": 0,
    "valid-jsdoc": 0,
    "require-jsdoc": 0,
    "camelcase": 0,
    "linebreak-style": 0,
    "no-unused-vars": 0,
    "no-invalid-this": 0,
  },
};
