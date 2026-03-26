# Overview
This repo contains example code for learning the the avr family microcontroller feature set. This project primarily uses the ATmega328P (Arduino UNO) without the IDE or Ardiuno system libraries to focus on the foundations of bare-metal programming in C. It uses the [AVRtoolchain](https://tinusaur.com/guides/avr-gcc-toolchain/) to compile C code to .hex files and flashes it to the Arduino with avrdude. See the build instructions for how to choose which code example to compile and run on the board.

## Requirements
- Windows (for now).
- [AVR toolchain](https://tinusaur.com/guides/avr-gcc-toolchain/). Need avr-gcc, avr-objcopy, and avrdude programs.

## Build Instructions
After isntalling the avr toolchain, just run build.bat with the specified parameters. It should produce a build folder and a target folder depending on which example was specified in with the -tar flag. It will also flash the program to the board. Make sure the Arduino is plugged in to your PC via USB. Edit path below to your installation of the avr toolchain. The specified path should contain the .\bin\ folder with the toolchain executables.
``` CMD
build.bat -tar blink -port COM5 -avr C:\avr-toolchain\avr8-gnu-toolchain-win32_x86_64\
```

To clean build artifacts, just delete the folder and re-run the build script with desired arguments. The script will take care of making and moving the necessary files.