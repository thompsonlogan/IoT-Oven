import 'dart:async';
import 'dart:convert' show utf8;
import 'package:flutter_blue/flutter_blue.dart';

class TargetDeviceManager {
  final String SERVICE_UUID = "4fafc201-1fb5-459e-8fcc-c5c9c331914b";
  final String CHARACTERISTIC_UUID = "beb5483e-36e1-4688-b7f5-ea07361b26a8";
  final String READFROM_UUID = "2f5c9894-aad6-11ec-b909-0242ac120002";
  final String TARGET_DEVICE_NAME = "Spectrum Brands Toaster";

  FlutterBlue flutterBlue = FlutterBlue.instance;
  late StreamSubscription<ScanResult> scanSubscription;

  BluetoothDevice? target;
  BluetoothCharacteristic? characteristic;
  BluetoothCharacteristic? readingCharacteristic;

  //Scans for nearby devices, attempts to find target device by device name
  //then attempts connection
  void ScanAndConnect(String ssid, String pass) async {
    List<BluetoothDevice> connectedDevices = await flutterBlue.connectedDevices;
    connectedDevices.forEach((device) {
      if (device.name == TARGET_DEVICE_NAME) {
        print("already connected Toaster Device found!");
        target = device;
        _discoverServices();
        writeData(ssid + "," + pass);
        return;
      }
    });
    if (target == null) {
      print("Scanning Now!");
      scanSubscription = flutterBlue.scan().listen((scanResult) {
        if (scanResult.device.name.contains(TARGET_DEVICE_NAME)) {
          scanSubscription?.cancel();
          print("Found Target Device!");
          target = scanResult.device;
          _connectToTargetDevice(ssid, pass);
          flutterBlue.stopScan();
          return;
        } else {
          print("Toaster Device Not Found!");
          return;
        }
      });
    }
  }

  //connects to the targeted device
  void _connectToTargetDevice(ssid, pass) async {
    if (isConnected()) {
      return;
    }
    print("Connecting to target device!");
    await target?.connect();
    print("Device Connected!");
    _discoverServices();
    writeData(ssid + "," + pass);
  }

  void _disconnectFromTargetDevice() {
    if (isConnected()) {
      return;
    }
    //target?.disconnect();
    print("Disconnected from target device!");
  }

  void _discoverServices() async {
    print("Discovering Services!");
    if (isConnected()) {
      return;
    }
    List<BluetoothService>? services = await target?.discoverServices();
    services?.forEach((service) {
      if (service.uuid.toString() == SERVICE_UUID) {
        service.characteristics.forEach((characteristics) {
          if (characteristics.uuid.toString() == CHARACTERISTIC_UUID) {
            characteristic = characteristics;
            print("${target?.name} Is Ready!");
          }
          if (characteristics.uuid.toString() == READFROM_UUID) {
            readingCharacteristic = characteristics;
            print("${target?.name} Is Ready!");
            readData();
          }
        });
      }
    });
  }

  //Writes, encodes, and sends a string of data to the connected device through bluetooth
  void writeData(String data) async {
    if (characteristic == null) {
      return;
    }
    List<int> dataBytes = utf8.encode(data);
    await characteristic?.write(dataBytes);
    print("Data written!");
  }

  //Reads and decodes a sent characteristic to the device through bluetooth
  void readData() async {
    print("Reading data!");
    if (readingCharacteristic == null) {
      print("reading characteristic null!");
    }
    String msg = utf8.decode(await readingCharacteristic!.read());
    print(msg.toString() + " This is a message");
  }

  //whether or not the manager has a device found
  bool isConnected() {
    return (target == null);
  }

  void dispose() {
    scanSubscription?.cancel();
    _disconnectFromTargetDevice();
  }
}
