# arduino-raspi-puredata-synth
https://youtu.be/tXrLTHSiED0
## What you'll need
Assemble all the materials first before starting.
### For the Arduino
- Arduino Uno
- Push button
- 1x 12k Ohm resistor
- 3 different coloured wires

### For the Raspberry Pi
- Wifi capable Raspberry Pi (e.g. Pi 3+ or Pi Zero W)
- 8GB (or larger) SD Card

### Optional sound output
Skip these items if you have one of the larger models of Raspberry Pi with onboard sound output.
- Breadboard
- 2x 0.033 uF capacitors
- 2x 10 uF capacitors
- 2x 270 Ohm resistors
- 2x 150 Ohm resistors
- 1x 
- 3x different coloured wires

### Other items
- Laptop or computer to program Arduino
- HDMI screen for Pi
- Keyboard + mouse for Pi

## Assembling and programming

### Arduino
A simulation and diagram of the arduino component is available [here](https://www.tinkercad.com/things/bW9I5fx90pV-fabulous-inari/editel?sharecode=yTXhoPcXfTzqndEQc5T8qA19RDbD8awFQE3I4zT66-s=). 

- Download the [Arduino project file](https://github.com/lachlangordon/arduino-raspi-puredata-synth/blob/master/sensor_synth.ino) and open with the Arduino IDE
- Connect your Arduino to your computer and download the code to the device.
- Connect the button as shown in the Tinkercad link.

### Raspberry Pi
- Start by installing NOOBS on the SD card. Follow the instructions on the [Raspberry Pi website](https://www.raspberrypi.org/documentation/installation/noobs.md). Select Raspbian for your operating system.
- Once the installation is complete, we're going to start installing Pure Data. Open a terminal and run the following commands:
```
sudo apt-get update
sudo apt-get install puredata
sudo apt-get install pd-comport
```
- Installing the PD_Arduino package is a little trickier. Open the web browser on your Pi and [download the .zip from GitHub]. Once complete, extract the contents to `/usr/lib/pd/extra/`.
- Enable your new Pure Data packages.
  - Open Pure Data from the Audio tab.
  - Go to `File > Preferences > Path ..`
  - Select 'New' button and add the paths for your Purde Data packages. They should be `/usr/lib/pd/extra/comport` and `/usr/lib/pd/extra/PD_Arduino`.
- Download the [.pd file in this repository](https://github.com/lachlangordon/arduino-raspi-puredata-synth/blob/master/squarewaver.pd) and put it in your user Home (`/home/pi`).
- Configure Pure Data to start headless when you boot your Pi.
  - Create a new Bash script called `/home/pi/bin/pd_start`:
  ```
  pd -nogui /home/pi/squarewaver.pd &
  ```
  - Enable the script to run with `/home/pi/bin/pd_start`
  - To run the script at startup add the following line to `/etc/rc.local`:
  ```
  /home/pi/bin/pd_start
  ```
  
  ### Starting the synth
  - Unplug your monitor, mouse, keyboard from the Raspberry Pi.
  - Connect the sound output to an appropriate device.
  - Connect the Arduino to your Pi via the USB port.
  - Reboot your Pi.
  - Once the Pi has booted, you should be able to get sound out by pressing the button connected to the Arduino.
  
### Sound output from Raspberry Pi
This is an optional step and is only needed if you have a Pi Zero model. You can find a great tutorial [here](https://www.tinkernut.com/2017/04/adding-audio-output-raspberry-pi-zero-tinkernut-workbench/).
