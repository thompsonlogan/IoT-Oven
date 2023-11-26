import 'dart:core';

import 'package:flutter/material.dart';
import 'package:spectrum_mobile_app/models/device_parameters.dart';
import '../themes.dart';
import '../main.dart';
import 'package:cloud_functions/cloud_functions.dart';

class MainMenu extends StatefulWidget {
  @override
  State<StatefulWidget> createState() => _MainMenuState();
}

class _MainMenuState extends State<MainMenu> {
  /// NOTE: Not all ConnectTOFunctions correlate to fulfillment intents
  /// TODO: Add limits to temperature and time based on function
  ///   Possibly create a class to integrate
  final List<String> _functions = [
    'No Preheat',
    'Bake',
    'Air Fry',
    'Toast',
    'Bagel',
    'Pizza',
    'Broil',
    'Roast',
    'Warm',
    'Reheat',
    'Off',
  ];

  int _index = 0;
  int _temp = 150;
  int _timer = 0;

  final fbFunctions = FirebaseFunctions.instance;

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        Container(
          margin: const EdgeInsets.fromLTRB(10.0, 40.0, 10.0, 10.0),
          child: RichText(
            text: TextSpan(
                style: TextStyle(
                    fontWeight: FontWeight.bold,
                    color: getSecondaryColor(myTheme)),
                children: <TextSpan>[
                  TextSpan(
                      text: 'Functions',
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
                    });
                    return;
                  }

                  if (_index == 0) {
                    setState(() {
                      _index = _functions.length - 1;
                    });
                  }
                },
                child: Text('<-',
                    style: TextStyle(color: getSecondaryColor(myTheme))),
              ),
              Text(_functions[_index],
                  style: TextStyle(color: getSecondaryColor(myTheme))),
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                    primary: getTertiaryColor(myTheme)),
                onPressed: () {
                  if (_index < _functions.length - 1) {
                    setState(() {
                      _index++;
                    });
                    return;
                  }

                  if (_index >= _functions.length - 1) {
                    setState(() {
                      _index = 0;
                    });
                  }
                },
                child: Text('->',
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
                  if (_temp > 150) {
                    setState(() {
                      _temp -= 5;
                    });
                  }
                },
                child: Text('<-',
                    style: TextStyle(color: getSecondaryColor(myTheme))),
              ),
              Text(_temp.toString(),
                  style: TextStyle(color: getSecondaryColor(myTheme))),
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                    primary: getTertiaryColor(myTheme)),
                onPressed: () {
                  if (_temp < 450) {
                    setState(() {
                      _temp += 5;
                    });
                  }
                },
                child: Text('->',
                    style: TextStyle(color: getSecondaryColor(myTheme))),
              )
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
                    if (_timer > 0) {
                      setState(() {
                        _timer -= 30;
                      });
                    }
                  },
                  child: Text('<-',
                      style: TextStyle(color: getSecondaryColor(myTheme))),
                ),
                Text(timerToTimeLeft(),
                    style: TextStyle(color: getSecondaryColor(myTheme))),
                ElevatedButton(
                  style: ElevatedButton.styleFrom(
                      primary: getTertiaryColor(myTheme)),
                  onPressed: () {
                    if (_timer < 3600) {
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
                  _updateDeviceConfig();
                  _getDeviceState();
                },
                child: Text('Submit',
                    style: TextStyle(color: getSecondaryColor(myTheme))),
              ),
              ElevatedButton(
                style: ElevatedButton.styleFrom(
                    primary: getTertiaryColor(myTheme)),
                onPressed: () {
                  _cancelCurrentOperation();
                  _getDeviceState();
                },
                child: Text('Cancel',
                    style: TextStyle(color: getSecondaryColor(myTheme))),
              ),
            ],
          ),
        ),
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

  Future<void> _updateDeviceConfig() async {
    try {
      HttpsCallable callable = fbFunctions.httpsCallable("updateDeviceConfig");

      String deviceId = _getDeviceID();

      // TODO: Match firebase database parameters
      List<String> paramNames = [
        'currentCookingMode',
        'timerRemainingSec',
        'temperatureSetpointCelsius',
        'on',
        'start',
      ];
      List<String> paramValues = [
        _functions[_index].toUpperCase(),
        _timer.toString(),
        toCelsius(_temp).toString(),
        true.toString(),

        /// <--
        true.toString(),

        /// <-- Yes, I did this on purpose
      ];

      Map<String, String> config = Map.fromIterables(paramNames, paramValues);

      final resp = await callable.call(<String, dynamic>{
        "deviceId": deviceId,
        "config": config,
      });
    } catch (e) {
      //TODO: handle error
      print(e.toString());
    }
  }

  Future<void> _cancelCurrentOperation() async {
    try {
      HttpsCallable callable = fbFunctions.httpsCallable("updateDeviceConfig");

      String deviceId = _getDeviceID();

      List<String> paramNames = [
        'on',
        'start',
      ];

      List<String> paramValues = [
        false.toString(),
        false.toString(),
      ];

      Map<String, String> config = Map.fromIterables(paramNames, paramValues);

      final resp = await callable.call(<String, dynamic>{
        "deviceId": deviceId,
        "config": config,
      });
    } catch (e) {
      //TODO: handle error
      print(e.toString());
    }
  }

  Future<void> _getDeviceState() async {
    try {
      HttpsCallable callable = fbFunctions.httpsCallable("getDeviceState");
      String deviceId = _getDeviceID();

      final resp = await callable.call(<String, dynamic>{
        "deviceId": deviceId,
      });

      final deviceParams = DeviceParameters.fromJson(resp.data);

      int newIndex = _functions.indexOf(deviceParams.state.currentCookingMode);
      int newTemp = toFahrenheit(deviceParams.state.temperatureSetpointCelsius);

      setState(() {
        _timer = deviceParams.state.timerRemainingSec;
        _temp = newTemp;
        _index = newIndex;
      });
    } catch (e) {
      print(e.toString());
      //TODO: handle error
    }
  }

  Future<void> _listAllDevices() async {
    try {
      HttpsCallable callable = fbFunctions.httpsCallable("listAllDevices");

      final resp = await callable.call();

      //TODO: Utilize response
      final temp = resp.data;
    } catch (e) {
      //TODO: handle error
    }
  }
  /*
  * 'No Preheat',
    'Bake',
    'Air Fry',
    'Toast',
    'Bagel',
    'Pizza',
    'Broil',
    'Roast',
    'Warm',
    'Reheat',*/

  /*
    TODO: Finish implementation to either store on mobile using
      Shared preferences or by fetching it with _listAllDevices()
      And basing it on owner ID + currently selected device?
  */
  String _getDeviceID() {
    return 'Embedded_Demo';
  }

  int toCelsius(int fTemp) {
    int cTemp = ((fTemp - 32.0) * (5.0 / 9.0)).round();
    return cTemp;
  }

  int toFahrenheit(int cTemp) {
    int fTemp = (cTemp * (9.0 / 5.0)).round() + 32;
    return fTemp;
  }
}
