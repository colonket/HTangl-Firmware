# HTangl Firmware

This is an edited version of the HayBox firmware created by [Haystack](https://github.com/JonnyHaystack)

Many features have been removed/added/modified to make the firmware more 
straightforward to use on HTangl controllers as well as the DIDIY.

Guide is incomplete, still need to add instructions for remapping, please go to the [HTangl Discord](https://discord.gg/yAeFsbCDpv) if you need help using this firmware


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