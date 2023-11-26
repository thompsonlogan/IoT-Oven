import 'package:flutter/material.dart';
import 'package:google_sign_in/google_sign_in.dart';
import 'package:spectrum_mobile_app/menus/app_setup_menu.dart';
import 'package:spectrum_mobile_app/menus/menu_export.dart';
import 'package:firebase_core/firebase_core.dart';
import 'themes.dart';

MyApp app = MyApp();
void main() async {
  WidgetsFlutterBinding.ensureInitialized();
  await Firebase.initializeApp();

  runApp(app);
}

Themes myTheme = Themes.Spectrum;

class MyApp extends StatefulWidget {
  _MyAppState appState = _MyAppState();
  @override
  State<StatefulWidget> createState() => appState;
  void changeTheme(Themes theme) {
    appState.changeTheme(theme);
  }
}

class _MyAppState extends State<MyApp> {
  String _currentBody = "Login";

  //Temp var, user auth should be seperated into more classes
  final signIn = GoogleSignIn();

  @override
  Widget build(BuildContext context) => MaterialApp(
        theme: ThemeData(scaffoldBackgroundColor: getPrimaryColor(myTheme)),
        home: Scaffold(
          resizeToAvoidBottomInset: false,
          appBar: AppBar(
            title: Text('My Spectrum Toaster',
                style: TextStyle(color: getSecondaryColor(myTheme))),
            backgroundColor: getPrimaryColor(myTheme),
          ),
          body: getCurrentBody(),
          bottomNavigationBar: BottomAppBar(
            color: getPrimaryColor(myTheme),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                ButtonBar(
                  children: [
                    ElevatedButton(
                      style: ElevatedButton.styleFrom(
                          primary: getTertiaryColor(myTheme)),
                      onPressed: () {
                        if (_currentBody != "Main Menu") {
                          setState(() {
                            _currentBody = "Main Menu";
                          });
                        }
                      },
                      child: Text('Main Menu',
                          style: TextStyle(color: getSecondaryColor(myTheme))),
                    ),
                    ElevatedButton(
                      style: ElevatedButton.styleFrom(
                          primary: getTertiaryColor(myTheme)),
                      onPressed: () {
                        if (_currentBody != "Recipes") {
                          setState(() {
                            _currentBody = "Recipes";
                          });
                        }
                      },
                      child: Text('Recipes',
                          style: TextStyle(color: getSecondaryColor(myTheme))),
                    ),
                    ElevatedButton(
                      style: ElevatedButton.styleFrom(
                          primary: getTertiaryColor(myTheme)),
                      onPressed: () {
                        if (_currentBody != "Settings") {
                          setState(() {
                            _currentBody = "Settings";
                          });
                        }
                      },
                      child: Text('Settings',
                          style: TextStyle(color: getSecondaryColor(myTheme))),
                    ),
                    ElevatedButton(
                      style: ElevatedButton.styleFrom(
                          primary: getTertiaryColor(myTheme)),
                      onPressed: () {
                        if (_currentBody != "Login") {
                          setState(() {
                            _currentBody = "Login";
                          });
                        }
                      },
                      child: Text('Login',
                          style: TextStyle(color: getSecondaryColor(myTheme))),
                    ),
                  ],
                ),
              ],
            ),
            elevation: 0,
          ),
        ),
      );

  void rebuildAllChildren() {
    void rebuild(Element el) {
      el.markNeedsBuild();
      el.visitChildren(rebuild);
    }
    //(context as Element).visitChildren(rebuild);
  }

  Widget getCurrentBody() {
    if (_currentBody == "Main Menu") {
      return MainMenu();
    } else if (_currentBody == "Recipes") {
      return RecipeMenu(); //Return recipe widget
    } else if (_currentBody == "Settings") {
      return SettingsMenu(); //Return settings widget
    } else if (_currentBody == "Login") {
      return AppSetupMenu(); //Return login widget
    } else {
      return MainMenu(); //Default: Return main menu widget
    }
  }

  void changeTheme(Themes theme) {
    myTheme = theme;
    app.appState.setState(() {
      ThemeData(scaffoldBackgroundColor: getPrimaryColor(myTheme));
    });
  }
}
