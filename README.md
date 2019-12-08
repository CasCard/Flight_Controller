# Flight Controller #

A simple arduino based flight controller that uses MPU6050 Gyro-Accelerometer and NRF24L01 transmission-Reciever module.

## Use Case ##

Normal flight controller usually available in the market are costly and are preprogrammed modules.Instead if we can use it arduino based then we can replicate similar functionalities by integration with various sensor for better caliberation and handling of the module.More over these drones can be highly used for agricultural,safety,surveillance,traffic control,forest fire,delivering and many more.

## This tutorial explain how to create a drone and RC transmitter ##

### Transmitter ###
<img src="images/nrfremote_bb.png">

For this tutorial we don't need very components in the figure but this remote can adopt to changes in number of sensor (eg:if we want to add more sensors to the drone the remote can be programmed based on that).

note:It's important to add capacitors across the teminal VCC and GND of the NRF24L01.

After creating circuit Upload the code:Transmitter_JoyStick.ino

### Reciever ###

