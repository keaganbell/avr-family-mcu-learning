# Overview
This example is the *Hello, World!* of bare-metal arduino programming. It just uses the avr toolchain utils to send a high signal to PORTB5 on the ATmega328P which corresponds to the Arduino UNO's GPIO pin 13. This pin's signal is also used for the onboard LED. So no additional electronics are required.

You should be able to plug the Arduino into your PC and run the build script
```CMD
build.bat -tar blink -port COM5 -avr C:\avr-toolchain\avr8-gnu-toolchain-win32_x86_64\
```

You should see the onboard LED start to blink on and off in half-second intervals.