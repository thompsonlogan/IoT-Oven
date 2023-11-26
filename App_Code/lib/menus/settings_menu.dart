import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';
import 'package:connectivity_plus/connectivity_plus.dart';
import 'package:network_info_plus/network_info_plus.dart';
import '../main.dart';
import '../themes.dart';
import 'dart:async';
import 'dart:developer' as developer;
import 'dart:io';

class SettingsMenu extends StatefulWidget {
  @override
  State<StatefulWidget> createState() => _SettingsMenuState();
}

class _SettingsMenuState extends State<SettingsMenu> {
  final List<String> _themes = [
    'Spectrum',
    'Light',
    'Dark',
  ];
  final Connectivity myConnectivity = Connectivity();
  final NetworkInfo _networkInfo = NetworkInfo();
  String _connectionStatus = 'Unknown';

  int _index = Themes.values.indexOf(myTheme);
  int _temp = 150;
  int _timer = 0;
  bool isChecked = false;

  @override
  Widget build(BuildContext context) {
    Color getColor(Set<MaterialState> states) {
      const Set<MaterialState> interactiveStates = <MaterialState>{
        MaterialState.pressed,
        MaterialState.hovered,
        MaterialState.focused
      };

      if (states.any(interactiveStates.contains)) {
        return Colors.blue;
      }
      return getTertiaryColor(myTheme);
    }

    return Column(
      children: [
        Container(
          margin: const EdgeInsets.fromLTRB(10.0, 50.0, 10.0, 10.0),
          child: RichText(
            text: TextSpan(
                style: TextStyle(
                    fontWeight: FontWeight.bold,
                    color: getSecondaryColor(myTheme)),
                children: <TextSpan>[
                  TextSpan(
                      text: 'Theme: ',
                      style: TextStyle(color: getSecondaryColor(myTheme))),
                ]),
          ),
        ),
        Container(
          margin: const EdgeInsets.fromLTRB(10.0, 5.0, 10.0, 10.0),
          child: Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                    primary: getTertiaryColor(myTheme)),
                onPressed: () {
                  if (_index > 0) {
                    setState(() {
                      _index--;
                      app.changeTheme(getTheme(_index));
                    });
                    return;
                  }

                  if (_index == 0) {
                    setState(() {
                      _index = _themes.length - 1;
                    });
                  }
                  app.changeTheme(getTheme(_index));
                },
                child: Text('<-',
                    style: TextStyle(color: getSecondaryColor(myTheme))),
              ),
              Text(getTheme(_index).toString().replaceAll("Themes.", ""),
                  style: TextStyle(color: getSecondaryColor(myTheme))),
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                    primary: getTertiaryColor(myTheme)),
                onPressed: () {
                  if (_index < _themes.length - 1) {
                    setState(() {
                      _index++;
                      app.changeTheme(getTheme(_index));
                    });

                    return;
                  }

                  if (_index >= _themes.length - 1) {
                    setState(() {
                      _index = 0;
                    });
                  }
                  app.changeTheme(getTheme(_index));
//runApp(MyApp());
                },
                child: Text('->',
                    style: TextStyle(color: getSecondaryColor(myTheme))),
              ),
            ],
          ),
        ),
        Container(
          margin: const EdgeInsets.fromLTRB(10.0, 50.0, 10.0, 10.0),
          child: Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              Checkbox(
                  checkColor: getSecondaryColor(myTheme),
                  fillColor: MaterialStateProperty.resolveWith(getColor),
                  value: isChecked,
                  onChanged: (bool? value) {
                    setState(() {
                      isChecked = value!;
                    });
                  }),
              Text("Allow Push Notifications",
                  style: TextStyle(color: getSecondaryColor(myTheme))),
            ],
          ),
        ),
        Container(
            margin: const EdgeInsets.fromLTRB(10.0, 50.0, 10.0, 10.0),
            child: Row(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                ElevatedButton(
                  style: ElevatedButton.styleFrom(
                      primary: getTertiaryColor(myTheme)),
                  onPressed: () {
                    if (_timer > 0) {
                      setState(() {
                        _timer -= 30;
                      });
                    }
                  },
                  child: Text('<-',
                      style: TextStyle(color: getSecondaryColor(myTheme))),
                ),
                Text(
                    "Notify me " +
                        timerToTimeLeft() +
                        " Minutes \nbefore timer is finished",
                    textAlign: TextAlign.center,
                    style: TextStyle(color: getSecondaryColor(myTheme))),
                ElevatedButton(
                  style: ElevatedButton.styleFrom(
                      primary: getTertiaryColor(myTheme)),
                  onPressed: () {
                    if (_timer < 300) {
                      setState(() {
                        _timer += 30;
                      });
                    }
                  },
                  child: Text('->',
                      style: TextStyle(color: getSecondaryColor(myTheme))),
                )
              ],
            )),
        Container(
          margin: const EdgeInsets.fromLTRB(10.0, 40.0, 10.0, 10.0),
          child: Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                    primary: getTertiaryColor(myTheme)),
                onPressed: () {
//Pressed Code Here
                },
                child: Text('Connect Google Account',
                    style: TextStyle(color: getSecondaryColor(myTheme))),
              ),
            ],
          ),
        ),
        Container(
          margin: const EdgeInsets.fromLTRB(10.0, 40.0, 10.0, 10.0),
          child: Row(
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                    primary: getTertiaryColor(myTheme)),
                onPressed: () {
                  _initNetworkInfo();
                  openDialog();
                },
                child: Text('Connect Toaster To Wifi',
                    style: TextStyle(color: getSecondaryColor(myTheme))),
              ),
            ],
          ),
        )
      ],
    );
  }

  String timerToTimeLeft() {
    int h, m, s;

    m = _timer ~/ 60;
    s = _timer - (m * 60);

    String minutesLeft =
        m.toString().length < 2 ? "0" + m.toString() : m.toString();

    String secondsLeft =
        s.toString().length < 2 ? "0" + s.toString() : s.toString();

    return "$minutesLeft:$secondsLeft";
  }

  Future openDialog() => showDialog(
        context: context,
        builder: (context) => AlertDialog(
            title: Text("Connect Toaster to " + _connectionStatus),
            content: TextField(
                decoration:
                    InputDecoration(hintText: "Enter Your WIFI Password")),
            actions: [
              TextButton(
                child: Text("Submit"),
                onPressed: () {
                  sendDataToToaster();
                },
              )
            ]),
      );

  void sendDataToToaster() {}

  Themes getTheme(int i) {
    if (i == 0) return Themes.Spectrum;
    if (i == 1)
      return Themes.Light;
    else
      return Themes.Dark;
  }

  Future<void> _initNetworkInfo() async {
    String? wifiName;

    try {
      if (!kIsWeb && Platform.isIOS) {
        var status = await _networkInfo.getLocationServiceAuthorization();
        if (status == LocationAuthorizationStatus.notDetermined) {
          status = await _networkInfo.requestLocationServiceAuthorization();
        }
        if (status == LocationAuthorizationStatus.authorizedAlways ||
            status == LocationAuthorizationStatus.authorizedWhenInUse) {
          wifiName = await _networkInfo.getWifiName();
          print("Here 1!");
        } else {
          wifiName = await _networkInfo.getWifiName();
          print("Here 2!");
        }
      } else {
        wifiName = await _networkInfo.getWifiName();
        print("Here 3!");
      }
    } on PlatformException catch (e) {
      developer.log('Failed to get Wifi Name', error: e);
      wifiName = 'Failed to get Wifi Name';
    }

    setState(() {
      _connectionStatus = 'Wifi Name: $wifiName';
    });
  }
}
