import 'dart:convert';
import 'package:connectivity_plus/connectivity_plus.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:cloud_functions/cloud_functions.dart';
import 'package:flutter/material.dart';
import 'package:provider/provider.dart';
import 'package:network_info_plus/network_info_plus.dart';
import '../main.dart';
import '../target_device_manager.dart';
import '../themes.dart';
import '../login_controller.dart';

class DeviceRegistrationMenu extends StatelessWidget {
  DeviceRegistrationMenu({Key? key}) : super(key: key);

  late TextEditingController controller = TextEditingController();

  final myConnectivity = Connectivity();
  final _networkInfo = NetworkInfo();
  final user = FirebaseAuth.instance.currentUser!;
  final fbFunctions = FirebaseFunctions.instance;

  TargetDeviceManager tdm = TargetDeviceManager();

  String _connectionStatus = 'Unknown';
  String? wifiName;

  @override
  Widget build(BuildContext context) {
    _initNetworkInfo();

    return Column(
      children: [
        buildTopMargin(),
        buildProfileIcon(),
        buildTopMargin(),
        buildLogoutButton(context),
        Container(
          margin: const EdgeInsets.fromLTRB(10.0, 40.0, 10.0, 10.0),
          child: Column(
            children: [
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  ElevatedButton(
                    style: ElevatedButton.styleFrom(
                        primary: getTertiaryColor(myTheme)),
                    onPressed: () {
                      openConnectivityDialog(context);
                    },
                    child: Text('Connect Toaster To Wifi',
                        style: TextStyle(color: getSecondaryColor(myTheme))),
                  ),
                ],
              ),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  ElevatedButton(
                    style: ElevatedButton.styleFrom(
                        primary: getTertiaryColor(myTheme)),
                    onPressed: () {
                      _registerDevice();
                    },
                    child: Text('Register Device',
                        style: TextStyle(color: getSecondaryColor(myTheme))),
                  ),
                ],
              ),
            ],
          ),
        ),
      ],
    );
  }

  Widget buildProfileIcon() {
    return Column(
      mainAxisSize: MainAxisSize.min,
      children: [
        CircleAvatar(
          backgroundImage: NetworkImage(user.photoURL!),
          radius: 100,
        ),
        Container(
          margin: const EdgeInsets.fromLTRB(0.0, 10.0, 0.0, 0.0),
          child: Column(
            children: [
              Text(
                user.displayName!,
                textAlign: TextAlign.center,
              ),
              Text(
                user.email!,
              ),
            ],
          ),
        ),
      ],
    );
  }

  Widget buildLogoutButton(BuildContext context) {
    return ActionChip(
      avatar: const Icon(Icons.logout),
      label: const Text("Logout"),
      onPressed: () {
        final provider =
            Provider.of<GoogleSignInProvider>(context, listen: false);
        provider.googleLogout();
      },
    );
  }

  // Adds 80 px margin from the top of the page
  Widget buildTopMargin() {
    return Container(
      margin: const EdgeInsets.fromLTRB(0, 80, 0, 0),
    );
  }

  Future<void> _registerDevice() async {
    try {
      HttpsCallable callable = fbFunctions.httpsCallable("registerDevice");

      //String deviceId = 'id-c60fa2e0-7cbf-4b46-a613-becacbd3d036';

      String deviceId = "Embedded_Demo";

      String publicKey =
          '-----BEGIN PUBLIC KEY-----\nMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEbfYAF/6m4Gbe+WQdIj/6P1r3tKyv\nbzGProJOE4XqxrYV5ODddigYIQ/hexK75Y4ohWKP5z6rFLm8XYxhPBi4FA==\n-----END PUBLIC KEY-----\n';
      String deviceName = 'DerekTestDevice';

      final resp = await callable.call(<String, String>{
        "publicKey": publicKey,
        "deviceId": deviceId,
        "deviceName": deviceName,
      });

      // TODO: If response is non-error, print out a success notice
    } catch (ex) {
      // TODO: Handle error here
      String errorMessage = ex.toString();
      // TODO: Remove temporary logging
      print(errorMessage);
    }
  }

  Future<String?> openResponseDialog(context, response) {
    return showDialog<String>(
        context: context,
        builder: (context) => AlertDialog(
              title: Text("Device Registration Was"),
            ));
  }

  // Bluetooth connectivity methods
  Future<String?> openConnectivityDialog(context) => showDialog<String>(
        context: context,
        builder: (context) => AlertDialog(
            title: Text("Connect Toaster to " + _connectionStatus),
            content: TextField(
              decoration: InputDecoration(hintText: "Enter Your WIFI Password"),
              controller: controller,
            ),
            actions: [
              TextButton(
                child: Text("Submit"),
                onPressed: () {
                  sendDataToToaster(controller.text);
                },
              )
            ]),
      );

  void sendDataToToaster(String pass) {
    tdm.ScanAndConnect(_connectionStatus, pass);
  }

  Future<void> _initNetworkInfo() async {
    // GRABS NAME OF WIFI
    wifiName = await _networkInfo.getWifiName();
    _connectionStatus = '$wifiName';

    @override
    void dispose() {
      controller.dispose();
      tdm.dispose();
    }
  }
}
