import React from 'react';
import SignInScreen from './SignInScreen';
import { initializeApp } from 'firebase/app';
import { getAuth, signOut } from "firebase/auth";

const logo = "/logo.png";

const app = initializeApp({
  apiKey: "AIzaSyCPjgAjNJZJ06JT5BlzcZ9awOEzqVgqQW8",
  authDomain: "spectrum-brands-main-project.firebaseapp.com",
  projectId: "spectrum-brands-main-project",
  storageBucket: "spectrum-brands-main-project.appspot.com",
  messagingSenderId: "722831468219",
  appId: "1:722831468219:web:7dcf270b2319f3d167ab9e",
  measurementId: "G-084SS01EK1"
});

const auth = getAuth(app);

function App() {  
  return (
    <div className="root">
      <img src={logo} alt="Spectrum Brands Logo" />
      <SignInScreen auth={auth} logOut={signOut} />
    </div>
  );
}

export default App;
