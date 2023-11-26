import StyledFirebaseAuth from 'react-firebaseui/StyledFirebaseAuth';
import { GoogleAuthProvider } from "firebase/auth";

const uiConfig = {
    // Popup signin flow rather than redirect flow.
    signInFlow: 'popup',
    // Display Google as auth provider.
    signInOptions: [
        GoogleAuthProvider.PROVIDER_ID
    ],
    callbacks: {
        // Avoid redirects after sign-in.
        signInSuccessWithAuthResult: () => false,
    },
};

/*
* The component that is first presented to the user, prompting them to sign in.
*/
function SignInLayout(props) {
    const auth = props.auth;

    return (
        <div className='sign-in'>
            <h1>Smart Toaster Oven Account Link</h1>
            <div className='sign-in-box'>
                <p>Sign into your Google account to link your Smart Toaster Oven with Google Assistant.</p>
                <StyledFirebaseAuth uiConfig={uiConfig} firebaseAuth={auth} />
            </div>
        </div>
    );
}

export default SignInLayout;
