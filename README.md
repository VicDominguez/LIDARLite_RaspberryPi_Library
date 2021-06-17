# LIDAR-Lite Raspberry Pi Library C Wrapper

Realised by Victor Manuel Dominguez Rivas for his Final Degree Project called Smart Driving Assistant.

Only tested for Raspberry Pi 4 and not all wrapper, only functions used on example.c. 

Use by our own risk.


## Instructions to enable the I2C peripheral in the ARM core
From a command shell, launch the configuration editor
```
sudo raspi-config
```
From the menu, select
* **Interfacing Options**
* **P5  I2C**
* **Enable** the interface
* Select **Finish**
* Reboot the Raspberry Pi


## Wiring the LIDAR-Lite to the Raspberry Pi

[Raspberry Pi Header](https://www.raspberrypi.org/documentation/usage/gpio/images/GPIO-Pinout-Diagram-2.png)

On the 40-pin header make the following connections -
```
* LLv3 Blue  (SDA) - RPi pin 3 (GPIO 2)
* LLv3 Green (SCL) - RPi pin 5 (GPIO 3)
* LLv3 Red   (5V ) - RPi pin 4
* LLv3 Black (GND) - RPi pin 6

- Wire a 680uF capacitor across pins 4 and 6
```

Additionally, see the following tutorials for other information concerning I2C on Raspberry Pi
* [Adafruit](https://learn.adafruit.com/adafruits-raspberry-pi-lesson-4-gpio-setup/configuring-i2c) - Configuring I2C
* [Sparkfun](https://learn.sparkfun.com/tutorials/raspberry-pi-spi-and-i2c-tutorial) - SPI and I2C Tutorial
