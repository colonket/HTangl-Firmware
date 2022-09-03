# HTangl Firmware

This is an edited version of the HayBox firmware created by [Haystack](https://github.com/JonnyHaystack)

Many features have been removed/added/modified to make the firmware more straightforward to use on HTangl controllers as well as the DIDIY.

## How to update DIDIY V0/V1

1. Go to the [releases section](https://github.com/HTangl/HTangl-Firmware/releases) and download the latest uf2 file that correlates to your DIDIY board version, if your board doesn’t have a version number you have a V0. You do not need to download the source code zip file.

2. Enter the BOOTSEL mode by holding the Start button while plugging your board into a PC. You should see a USB drive show up named "RPI-RP2”. Note for V0 owners, if this is your first time updating you will need to hold the C-Right button instead of Start, the V0 boards originally shipped with the Pico-Rectangle firmware which uses a different button to get into BOOTSEL.

3. Drag and drop the uf2 file you downloaded in step 1 onto the RPI-RP2 drive. The board will disconnect and then reconnect to your PC, The RPI-RP2 drive should disappear and your board is now updated. 

## How to update HTangl Proto/V1/V2

Before you can update you need to install [Visual Studio Code](https://code.visualstudio.com/), this is a program that will both allow you to edit the firmware as well as upload new firmware to your board. After installing VSCode you will also need to install the [PlatformIO plugin](https://platformio.org/install/ide?install=vscode).

Special note, if you are using a Windows version older than 10 you will need to manually install the [Arduino drivers](https://www.arduino.cc/en/software). Download the "Windows Zip file" under the download options section. Unzip the folder and then follow [this guide](https://docs.arduino.cc/tutorials/generic/DriverInstallation) to install the drivers.

1. Go to the [releases section](https://github.com/HTangl/HTangl-Firmware/releases) and download the latest source code zip file. Unzip the file then right click on the folder and select “Open with Code”. If you don’t see that option in the right click menu open VSCode and click “File” then “Open Folder” then navigate to the HTangl Firmware folder.

2. In the small blue bar at the bottom click on the folder icon with the text “Default (Htangl-Firmware)” next to it. A drop down box will appear at the top and you’ll need to select the environment that correlates to your controller version. The folder icon at the bottom should now display whatever environment you selected. If this is your first time updating you will see a message that says “rebuilding IntelliSense index”, this means that VSCode is downloading required files. This can take some time as the files needed are about 3.5 GB big. Be patient and let it download, it usually takes about 5-10 minutes.

3. Plug your controller in and set it aside face up, don’t want any buttons held down. Do not touch the controller during the upload process, if it somehow gets unplugged while writing it is possible to brick the Arduino. Click on the arrow button in the blue bar at the bottom, it’s the one between the check mark and garbage icons. This will start the upload process and a lot of text will start to display in the terminal at the bottom. The upload process only takes a few seconds and when it’s done you should see a message that lists the environment you chose along with a green “SUCCESS” status.

If the firmware upload failed ask for help in the tech-support channel on discord.

If it succeeded your controller is updated and ready to use, you can close out of VSCode.  

## How to remap button assignments

### Prerequisites

Remapping buttons requires editing and flashing firmware to your controller, this is a fairly straight forward process but does require some set up.

Start by installing [Visual Studio Code](https://code.visualstudio.com/), this is a program that will both allow you to edit the firmware as well as upload new firmware to your controller. After installing VSCode you will also need to install the [PlatformIO plugin](https://platformio.org/install/ide?install=vscode).

If you have a DIDIY you will also need to install [Git](https://git-scm.com/download/win). Grab the standalone installer and leave everything set to default options, there are quite a few steps but you can just skip through them all.

If you have an HTangl and are using a Windows version older than 10 you will need to manually install the [Arduino drivers](https://www.arduino.cc/en/software). Download the "Windows Zip file" under the download options section. Unzip the folder and then follow [this guide](https://docs.arduino.cc/tutorials/generic/DriverInstallation) to install the drivers.

You will now need the latest version of the firmware. Go to the [releases section](https://github.com/HTangl/HTangl-Firmware/releases) and download the latest source code zip file. Unzip the file once it's done downloading.

### Remapping

Please note that remapping will change the button assignments for all game modes. While it is possible to remap only a single game mode it is much more complicated and I generally recommend against trying to do so unless you have some coding experience.

1. Right click on the HTangl-Firmware folder and select “Open with Code”. If you don’t see that option in the right click menu open VSCode and click “File” then “Open Folder” and navigate to the HTangl-Firmware folder.

2. In VSCode navigate to the config.cpp file for your controller, this file is located under "config/(controller)/config.cpp". Scroll down to the "GpioButtonMapping" section where all the buttons are listed along with their correlating pin numbers.

3. You change button mappings by changing the pin number assignments for each button. Reference the picture for you controller in the "Remapping Pictures" folder inside the main HTangl-Firmware folder. As an example, let's say you have a DIDIY V1 and you want to move the R button to the top row index finger. You would check the picture to see what pin number is assigned to top row index (Pin 3 for DIDIY V1) then you would change the pin number next to "InputState::r" to 3. You would then need to reassign the button that was originally on pin 3 (B for DIDIY V1). An easy way to figure out pin assignments for a remap is to edit the remapping picture for your controller, simply draw in whatever layout you want without moving/changing the pin numbers in the picture and then use your edited picture as a reference for what pin numbers to assign to each button. Once you're done editing the pin assignments make sure to save your changes by pressing ctrl+S or clicking on File then Save.

4. The last step is uploading the now edited firmware to your controller. This process is different depending on what controller you have. For HTangl follow steps 2 and 3 of the "How to update HTangl Proto/V1/V2" section above. For DIDIY continue to step 5.

5. In the small blue bar at the bottom click on the folder icon with the text “Default (Htangl-Firmware)” next to it. A drop down box will appear at the top and you’ll need to select the environment that correlates to your controller version. The folder icon at the bottom should now display whatever environment you selected. If this is your first time uploading firmware you will see a message that says “rebuilding IntelliSense index”, this means that VSCode is downloading required files. This can take some time as the files needed are about 3.5 GB big. Be patient and let it download, it usually takes about 5-10 minutes.

6. Click on the check mark in the blue bar at the bottom, the terminal should open and start scrolling text rapidly. Once the process is complete you should see a message that says "SUCCESS", if you get a "FAILED" message instead take a screenshot of the terminal text and ask for help in the [HTangl Discord](https://discord.gg/yAeFsbCDpv). Now you need to grab the "firmware.uf2" you just created, it'll be in the main HTangl-Firmware folder under ".pio/build/(controller)/firmware.uf2". Now scroll back up to the "How to update DIDIY V0/V1" section of this guide and follow steps 2 and 3 to upload your new firmware to your controller.
