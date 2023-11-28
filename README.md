# EGN3000L-Group17
This is the code for the EGN3000L Project for Group 17


Each comment explains the function of each line in the code, but this file will explain everything in brief.

This Arduino code utilizes an ultrasonic sensor to measure distances and control a robot's behavior accordingly. 
The setup section initializes the LCD, pins, and serial communication.
In the main loop, the code continuously measures distances, determining the robot's state based on proximity to obstacles. 
The LCD display is updated only when a change in state occurs. 
The code distinguishes between stopped, backward, forward, and out-of-range states, adjusting motor and LED settings accordingly.
small delays in a few lines makes sure the sensors have time to read values.
