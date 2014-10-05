# LEDMeter

This app is designed to provide a (RGB) LED bargraph from the microphone input using `python` and [Arduino](http://www.arduino.cc/) with some TLC5940 drivers.

## Table of contents

- [Requirements](#requirements)
- [Setup](#setup)
- [Run](#run)
- [Have fun](#have-fun)
- [TODO](#todo)

## Requirements

    * An Arduino or whatever *duino-like you have near your hands  Actually, I used some nano-like I bought on \"Aliexpress\" for something like 3 bucks.
    * A running computer with python
    * A head

## Setup

Before to start using this, you will probably need to install need `python-alsaaudio`.  
If you already have it, just jump to the the next step.

* Using `apt` :

        sudo apt-get install python-alsaaudio

* Then, you're gonna need to upload the arduino sketch to the device.  
Assuming that you know how to use an arduino, and since there are many tutorials about it, I won't describe this process.

## Run

* Once your Arduino is running, make sure it is connected to your desktop using USB

* Apply the permission to execute `ledMeter`

        sudo chmod +x ledMeter

* Launch the python app using this command :

        ledMeter "[PORT]" [BAUDRATE]

According to my configuration, I use `ledMeter \"/dev/ttyUSB0\" 9600`.

## Have fun

And now, just talk in your mike or put a jack from the soundcard output to the microphone input and enjoy!!!

## TODO

* Add the wiring
