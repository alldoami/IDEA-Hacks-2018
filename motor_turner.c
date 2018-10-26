#include <Servo.h>

#define REDLED 5
#define GREENLED 6
#define BLUELED 9

#define MOTOR 3

#define rain 1
#define sunny 2
#define cloudy 3
#define partly 4

#define articles 4

Servo hanger;
int position;
int rainPos = 2;
int sunPos = 1;void setup() {
Serial.begin(9600); // set the baud rate
Serial.println("Ready"); // print "Ready" once
}
void loop() {
char inByte = ' ';
if(Serial.available()){ // only send data back if data has been sent
char inByte = Serial.read(); // read the incoming data
Serial.println(inByte); // send the data back in a new line so that it is not all one long line
}
delay(100); // delay for 1/10 of a second
}
int cloudPos = 3;
int partlyPos = 4;
int weather;

void whiteLights(){
  for (int r = 0; r <=100; r++){
    analogWrite(REDLED, r);
    delay(5);
  }
  
  for (int b = 0; b <= 230; b++){
    analogWrite(BLUELED, b);
    delay(5);
  }
  
  for (int g = 0; g <= 230; g++){
   analogWrite(GREENLED, g);
   delay(5);
  }
}

void lightsOff(){
  analogWrite(REDLED, 0);
  analogWrite(BLUELED, 0);
  analogWrite(GREENLED, 0);
}
void setup() { 
   Serial.begin(9600);
   
   hanger.attach(MOTOR); 

   pinMode(REDLED, OUTPUT);
   pinMode(BLUELED, OUTPUT);
   pinMode(GREENLED, OUTPUT);
   lightsOff();
   whiteLights();  
}


void rotate90CW(){
  hanger.write(100);
  delay(1800);
  hanger.write(92);
}

void rotate90CCW(){
  hanger.write(80);
  delay(1800);
  hanger.write(92);
}

void rotateTo(int newPos, int currPos){
//  int diff;
//  if (currPos > newPos){
//    if (diff > (articles/2)){
//      for(int k = 0; k < (currPos - newPos); k++)
//      rotate90CW();
//    }
//    else for(int k = 0; k < (currPos - newPos); k++)
//      rotate90CW();
//  }
//
//  if (currPos < newPos){
//    
//  }
//  if currPos == newPos)
//    return;
}
//void getData

void loop(){ 
  //getData()
  int currPos = sunPos;   //must manually reset upon disconnection
  
  switch(weather){
    case rain:        //rain
      rotateTo(rainPos, currPos);
      currPos = rainPos;
      break;
    case sunny:       //sunny
      rotateTo(sunPos, currPos);
      currPos = sunPos;
      break;
    case cloudy:      //cloudy
      rotateTo(cloudPos, currPos);
      currPos = cloudPos;
      break;
    case partly:      //partly
      rotateTo(partlyPos, currPos);
      currPos = partlyPos;
      break;
  }
  rotate90CW();
  delay(1000);
  //rotateTo(sunPos);
  //lightsOff();
  }