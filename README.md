# F21-S22-SpectrumBrands
This repository contins the project files for the 2021-2022 Software Senior Project (Section 1) Smart Toaster Oven.

## File Structure
- `App_Code`: Contains the project files for the mobile app used to control the toaster oven.
- `Cloud_Code`: Contains the project files for the cloud infrastructure.
    - `/Firebase`: Contains the files that utilize features in Firebase.
        - `/functions`: Contains the individual cloud functions that are hosted in the cloud. These are developed with NodeJS and uses NPM to manage modules. See the Firebase NodeJS Setup documentation for more information.
        - `/web`: Contains the files needed to host the webapp used for the Google Assistant account linking process. This was developed with NodeJS and React.js. The OAuth and Account Linking documentation describes how this webapp is used.
    - `/esp32-lwmqttv2`: Contains the files used on the ESP32 for connecting it to IoT Core, enabling communication with the device.
- `Embedded_Code`: Contains the project files used on the physical device.
    - `/ConnectedToasterOven`: The Source folder contains the files used on the board to operate the toaster oven.

## Build Instructions
First, clone the repository into a local directory.
- If working on the mobile app: follow the setup instructions in the documentation. Files are setup for development in Android Studio.
- If working on the cloud code: ensure that NodeJS is installed. From within the `Cloud_Code/Firebase/functions` directory, run `npm install`. Additionally, from within the `Cloud_Code/Firebase/web` directory, run `npm install`. Further setup instructions can be found in the documentation. The existing code was developed in Visual Studio Code.
- If working on the hardware: you can modify the Nuvoton board in Keil uVision IDE and the ESP32 in Arduino IDE.
