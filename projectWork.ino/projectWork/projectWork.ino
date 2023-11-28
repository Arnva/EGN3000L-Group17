#include <LiquidCrystal_I2C.h> // Include the LiquidCrystal_I2C library for LCD

// Create an LCD object with its address (0x27) and dimensions (16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define variables for different states and messages
char array1[] = "Robot State:    ";
char array2[] = "STOPPED         ";
char array3[] = "BACKWARD        ";
char array4[] = "FORWARD         ";
char array5[] = "OUT OF RANGE    ";

// Define pins for ultrasonic sensor, motor driver, and LED
int echoPin = 8; 
int trigPin = 7;
int in1 = 4;
int in2 = 5;
int in3 = 9;
int in4 = 10;
int ledpin = 13;

// Variables to track the previous and current LCD states
int LCDprev = 99;
int LCDcurr = 100;

// Variables for ultrasonic sensor measurements
long duration;
int distance;

void setup() {
  // Initialize and turn on the LCD backlight
  lcd.init();
  lcd.backlight();

  // Set pin modes for ultrasonic sensor, motor driver, and LED
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ledpin, OUTPUT);

  // Configure serial communication for debugging
  Serial.begin(9600);

  // Set the cursor to the top left corner of the LCD
  lcd.setCursor(0, 0);

  // Print the initial message on the LCD
  lcd.print(array1);
}

void loop() {
  // Update the LCD state only when there is a change in state
  LCDprev = LCDcurr;

  // Send a pulse to the ultrasonic sensor to measure distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Display the distance on the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Determine the robot state based on the distance and update the LCD
  if (distance <= 15) {
    LCDcurr = 1;

    // Control the motor and LED for backward movement
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(ledpin, HIGH);

    // Update the LCD only if there is a change in state
    if (LCDprev != LCDcurr) {
      lcd.setCursor(0, 1);
      lcd.print(array3);
      delay(10);
    }
  } else if (distance <= 30) {
    LCDcurr = 2;

    // Stop the motor and turn off the LED
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(ledpin, LOW);

    // Update the LCD only if there is a change in state
    if (LCDprev != LCDcurr) {
      lcd.setCursor(0, 1);
      lcd.print(array2);
      delay(10);
    }
  } else if (distance <= 45) {
    LCDcurr = 3;

    // Control the motor and LED for forward movement
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(ledpin, HIGH);

    // Update the LCD only if there is a change in state
    if (LCDprev != LCDcurr) {
      lcd.setCursor(0, 1);
      lcd.print(array4);
      delay(10);
    }
  } else {
    LCDcurr = 4;

    // Stop the motor and turn off the LED
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(ledpin, LOW);

    // Update the LCD only if there is a change in state
    if (LCDprev != LCDcurr) {
      lcd.setCursor(0, 1);
      lcd.print(array5);
      delay(10);
    }
  }

  // Add a small delay to stabilize the measurements
  delay(10);
}
