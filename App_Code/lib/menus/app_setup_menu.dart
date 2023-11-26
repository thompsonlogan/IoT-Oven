import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:provider/provider.dart';
import 'package:spectrum_mobile_app/menus/login_menu.dart';
import 'login_menu.dart';
import '../login_controller.dart';
import 'device_registration_menu.dart';

class AppSetupMenu extends StatelessWidget {
  GoogleSignInProvider signInProvider = GoogleSignInProvider();

  @override
  Widget build(BuildContext context) => ChangeNotifierProvider(
        create: (context) => signInProvider,
        child: Scaffold(
          body: StreamBuilder(
            stream: FirebaseAuth.instance.authStateChanges(),
            builder: (context, snapshot) {
              if (snapshot.connectionState == ConnectionState.waiting) {
                return const Center(child: CircularProgressIndicator());
              } else if (snapshot.hasData) {
                return DeviceRegistrationMenu();
              } else if (snapshot.hasError) {
                return const Center(child: Text('Something Went Wrong!'));
              } else {
                return LoginMenu();
              }
            },
          ),
        ),
      );
}
