# EGN3000L-Group17
This is the code for the EGN3000L Project for Group 17


Each comment explains the function of each line in the code, but this file will explain everything in a bit more detail.

The first 30 lines of code are dedicated to instantiating every variable that will be used in the robot. The pins for A0 and A1 are declared to be the pins for the IR sensors right and left respectively. 

The pins 4,5 and 6 are for the right motor, where 4 and 5 determine the motor's rotation and 6 determines its speed. Sinilarly, the pins 9,10 and 3 are for the rights motor, where 9 and 10 determines rotation and 3 is for speed.

The pinMode function is to configure each pin to behave like an input of output. The motors are outputs and the sensors input data.

in lines 33 to 41, the forward function makes the robot move forward. The analogWrite function gives a value between 0-255 (in this case 150) to the motor speed, allowing both motors to move at the same speed. The digitalWrite function gives a binary value of High or Low to the motor. As both motors have the same values for rotation, both motors move forward.

For the right function, The speed is set to 100 for the left and 0 for the left, allowing the car to move right, and vice versa for the left function

For the stop function, both speeds are set to 0.

The loop function in lines 72 to 87, makes it such that the functions inside the loop will always be called until the robot is shut down

The analogRead function reads the values of each IR sensor. If the values correspond to black or white, the corresponding functions will be called.

The If/else statements determine the movement of the car based on the values the IR sensors provide. If both IR sensors detect the black line, the forward function is called. If only one IR sensor detects the line, the car will move in that direction. If neither IR sensor sees the line, the car will stop.
