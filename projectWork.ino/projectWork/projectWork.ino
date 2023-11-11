
const int rightIR = A0;    // pin for the right IR sensor
const int leftIR = A1;   // pin for the left IR sensor

#define leftSpeed 3     // left motor speed control

#define rightSpeed 6   // right motor speed control

//RIGHT MOTOR
#define IN1 4 // connect IN1 on the H-Bridge to Arduino pin 4
#define IN2 5 // connect IN2 on the H-Bridge to Arduino pin 5

//LEFT MOTOR
#define IN3 9 // connect IN3 on the H-Bridge to Arduino pin 9
#define IN4 10 // connect IN4 on the H-Bridge to Arduino pin 10

void setup() {
  // Motor control is output
    pinMode(rightSpeed, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    pinMode(leftSpeed, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

  // IR is input
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);
}

//set speed 150 of left & right if line on both sides
void forward() {
  analogWrite(rightSpeed, 150);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

  analogWrite(leftSpeed, 150);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}


//set speed 0 of right if no line on left
void right() {
  analogWrite(rightSpeed, 0);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

  analogWrite(leftSpeed, 100);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

//set speed 0 of left if no line on right
void left() {
  analogWrite(rightSpeed, 100);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

  analogWrite(leftSpeed, 0);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

//set speed 0 if no line
void stop() {
  analogWrite(rightSpeed, 0);
  analogWrite(leftSpeed, 0);
}

void loop() {
  // Read sensor values
  int leftValue = analogRead(leftIR);
  int rightValue = analogRead(rightIR);

  // Line logic
  if (leftValue == rightValue && leftValue >= {black}) {
    forward();  // move if both values are black
  } else if (leftValue << rightValue && rightValue >= {black}) {
    left();     // if leftIR sees white, move till it sees black
  } else if (rightValue << leftValue && leftValue >= {black}) {
    right();    // if rightIR sees white, move till it sees black
  } else {
    stop();
  }
}
