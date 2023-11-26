import SignInLayout from './SignInLayout';
import LinkAccountLayout from './LinkAccountLayout';
import { useEffect, useState } from 'react';
import { onAuthStateChanged } from "firebase/auth";

/*
* The component that determines which layout to display, based on the if the
* user is currently signed in or not.
*/
function SignInScreen(props) {
    const auth = props.auth;
    const [isSignedIn, setIsSignedIn] = useState(false); // Local signed-in state.
    
    // Listen to the Firebase Auth state and set the local state.
    useEffect(() => {
        const unregisterAuthObserver = onAuthStateChanged(auth, user => setIsSignedIn(!!user));
        return () => unregisterAuthObserver(); // Make sure we un-register Firebase observers when the component unmounts.
    }, [auth]);

    return !isSignedIn ? <SignInLayout auth={auth} /> : <LinkAccountLayout auth={auth} logOut={props.logOut}/>;
}

export default SignInScreen;
