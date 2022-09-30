// I, Damanpreet Singh, student number 000741359, certify that all code submitted is my own work;
// that I have not copied it from any other source.
// I also certify that I have not allowed my work to be copied by others.

#include <Arduino.h> 
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 
 
  pinMode(D5, INPUT_PULLUP); 
  // set default PWM range 
  analogWriteRange(1023); 
} 
 
 
void loop() { 

  int iVal;  // variable to read agalog
  double val; // variable to get mapped value

  int ibutton;
  ibutton = digitalRead(D5);
  
  if (ibutton == 1 ){
    digitalWrite(D4,ibutton);
    Serial.println(ibutton +"---- button = 1" );
  }
  if (ibutton == 0 ){
    Serial.println(ibutton +"---- button = 0" );
    // read digitized value from the D1 Mini's A/D convertor 
    iVal = analogRead(A0); 
    // val = map(iVal, 0, 1023, 0,3300 );
    val = map(iVal, 0, 1023, 0,5000 );
    analogWrite(D4, val); 
  }
  delay(1);
} 