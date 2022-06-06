#include <AFMotor.h>

//initializing motor pins and frequency.
AF_DCMotor left(3);
AF_DCMotor right(4 );

// initializing LDR pins.
int left_reader = A0,right_reader = A2;

//initializing variable to store read value of LDR over Black & White strip.
float left_read_value_black, right_read_value_black , left_read_value_white, right_read_value_white;

// initializing variable to store mean black and white value.
float mean_left, mean_right;

//initializing variable for loop analog reading of left & right LDR.
float left_ldr, right_ldr;

void setup() {
  // setting serial communication at 9600 baud rate.
  Serial.begin(9600);
  // setting motors speed.
  left.setSpeed(180);
  right.setSpeed(180);
  
  // initalizing A1 pin for output.
  pinMode(A1,OUTPUT);
  
  digitalWrite(A1,LOW);
  delay(2000);
  
  digitalWrite(A1,HIGH);
  delay(2500);
  //put on black strip.
  left_read_value_black = analogRead(left_reader);
  right_read_value_black = analogRead(right_reader);
  digitalWrite(A1,LOW);
  delay(2000);
  
  //put on white strip.
  digitalWrite(A1,HIGH);
  delay(2500);
  left_read_value_white = analogRead(left_reader);
  right_read_value_white = analogRead(right_reader);
  digitalWrite(A1,LOW);
  delay(2000);

  //Calculating mean for left & right LDR.
  mean_left = (left_read_value_black + left_read_value_white)/2;
  mean_right = (right_read_value_black + right_read_value_white)/2;
  Serial.println(mean_left);
  Serial.println(mean_right);

  delay(2000);
}

void loop() {

  left_ldr = analogRead(left_reader);
  right_ldr = analogRead(right_reader);
  
  //To check Readings of left LDR(if faulty replace)
  Serial.println("Left LDR Reading\n");
  Serial.println(left_ldr);
  
  //To check Readings of Right LDR(if faulty replace)
  Serial.println("Right LDR Reading\n");
  Serial.println(right_ldr);

  if(left_ldr<mean_left && right_ldr< mean_right){
    straight();
    }
  if(left_ldr<mean_left && right_ldr>mean_right){
    mleft();
    }
  if(left_ldr>mean_left && right_ldr<mean_right){
    mright();
    }
  if(left_ldr>=mean_left && right_ldr>=mean_right){
    back();
    }
  }
// motors move in forward direction
 void straight(){
  left.run(FORWARD);
  right.run(FORWARD);
  }
//motor move in backward direction
 void back(){
  left.run(BACKWARD);
  right.run(BACKWARD);
  }
// motors turn right
  void mright(){
  left.setSpeed(255);
  left.run(FORWARD);
  right.run(RELEASE);
    }
// motors turn left
  void mleft(){
  right.setSpeed(255);
  left.run(RELEASE);
  right.run(FORWARD);
  }
