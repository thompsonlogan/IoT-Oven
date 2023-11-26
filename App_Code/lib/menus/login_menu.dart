import 'package:flutter/material.dart';
import 'package:font_awesome_flutter/font_awesome_flutter.dart';
import 'package:provider/provider.dart';
import 'package:spectrum_mobile_app/main.dart';
import '../login_controller.dart';
import '../themes.dart';

class LoginMenu extends StatelessWidget {
  LoginMenu({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) => Container(
        alignment: Alignment.center,
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Container(
              alignment: Alignment.center,
              margin: const EdgeInsets.fromLTRB(10.0, 0.0, 10.0, 10.0),
              child: Column(
                children: [
                  ElevatedButton.icon(
                    icon: FaIcon(FontAwesomeIcons.google,
                        color: getSecondaryColor(myTheme)),
                    style: ElevatedButton.styleFrom(
                      //background color property is named primary. Use our theme's tertiary.
                      primary: getTertiaryColor(myTheme),
                      //color of the foreground (text)
                      onPrimary: getSecondaryColor(myTheme),
                      minimumSize: const Size(double.infinity, 50),
                    ),
                    label: const Text('Sign In With Google'),
                    onPressed: () {
                      final provider = Provider.of<GoogleSignInProvider>(
                          context,
                          listen: false);
                      provider.googleLogin();
                    },
                  )
                ],
              ),
            ),
          ],
        ),
      );

  Widget buildWelcomeText() {
    return RichText(
        text: const TextSpan(
      text: 'Already have an account? ',
      children: [
        TextSpan(
            text: 'Log In',
            style: TextStyle(decoration: TextDecoration.underline)),
      ],
    ));
  }
}
