/*
An open-source binary clock for Arduino. 
http://www.instructables.com/id/LED-Binary-Clock-1/
http://www.instructables.com/member/emihackr97/
*/
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

const int analogInPin = A1;

int second=0, minute=0, hour=0; //start the time on 00:00:00
int munit = 0;
int hunit = 0;
int valm=0;
int valh=0;
int ledstats = 0;
int i= 0;
boolean light = 1;
int sensorValue = 0;
int outputValue = 0;  
Adafruit_NeoPixel strip = Adafruit_NeoPixel(15, 6, NEO_RGB + NEO_KHZ800);

void setup() { //set outputs and inputs
  Serial.begin(9600);
  strip.begin();
  strip.show();

pinMode(18, INPUT);
pinMode(14, INPUT);
pinMode(19, INPUT);
digitalWrite(14, HIGH);
digitalWrite(19, HIGH);
digitalWrite(18, HIGH);
}


void loop() {
  int light = 0;
//  static unsigned long last = 0;
//  if (millis() - last >= 100) {
 // last = millis();
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  Serial.print("value: ");
  Serial.print(outputValue);
  if (outputValue > 230)
  {
    light = 5000/outputValue;
  }
  else
  {
    light = 10000/outputValue;
  }
  Serial.print("light: ");
  Serial.println(light);
//}

static unsigned long lastTick = 0; // set up a local variable to hold the last time we moved forward one second
// (static variables are initialized once and keep their values between function calls)
// move forward one second every 1000 milliseconds

if (millis() - lastTick >= 1000) {
  lastTick = millis();
  second++;
}

// move forward one minute every 60 seconds
  if (second >= 60) {
  minute++;
  second = 0; // reset seconds to zero
}

// move forward one hour every 60 minutes
if (minute >=60) {
  hour++;
  minute = 0; // reset minutes to zero
}

if (hour >=12) {
  hour=0;
  minute = 0; // reset minutes to zero
}

  munit = minute%10; //sets the variable munit and hunit for the unit digits
  hunit = hour%10;
  
//  ledstats = digitalRead(18);  // read input value, for setting leds off, but keeping count
//  if (ledstats == LOW){
//    light=!light;
//    delay(250);
//  }
//    
//    if(light== LOW){
//  for(i=1;i<=13;i++){
//  digitalWrite(i, HIGH);}
//  
//  } else  {

  //seconds units
  if((second >= 10 && second < 20) || (second >= 30 && second < 40) || (second >= 50 && second < 60)) 
  {strip.setPixelColor(12, 0, light, 0);
  strip.show();} 
  else 
  {strip.setPixelColor(12, 0, 0, 0);
  strip.show();}
  if(second >= 20 && second < 40)
  {strip.setPixelColor(13, 0, light, 0);
  strip.show();}
  else 
  {strip.setPixelColor(13, 0, 0, 0);
  strip.show();}
  if(second >= 40 && second < 60) 
  {strip.setPixelColor(14, 0, light, 0);
  strip.show();} 
  else
  {strip.setPixelColor(14, 0, 0, 0);
  strip.show();}

  
  //minutes units
  if(munit == 1 || munit == 3 || munit == 5 || munit == 7 || munit == 9)
  {strip.setPixelColor(0, 0, light, 0);
  strip.show();}
  else 
  {strip.setPixelColor(0, 0, 0, 0);
  strip.show();}
  if(munit == 2 || munit == 3 || munit == 6 || munit == 7)
  {strip.setPixelColor(1, 0, light, 0);
  strip.show();}
  else 
  {strip.setPixelColor(1, 0, 0, 0);
  strip.show();}
  if(munit == 4 || munit == 5 || munit == 6 || munit == 7) 
  {strip.setPixelColor(2, 0, light, 0);
  strip.show();} 
  else 
  {strip.setPixelColor(2, 0, 0, 0);
  strip.show();}
  if(munit == 8 || munit == 9) 
  {strip.setPixelColor(3, 0, light, 0);
  strip.show();} 
  else 
  {strip.setPixelColor(3, 0, 0, 0);
  strip.show();}

  //minutes 
  if((minute >= 10 && minute < 20) || (minute >= 30 && minute < 40) || (minute >= 50 && minute < 60)) 
  {strip.setPixelColor(4, 0, light, 0);
  strip.show();} 
  else 
  {strip.setPixelColor(4, 0, 0, 0);
  strip.show();}
  if(minute >= 20 && minute < 40)
  {strip.setPixelColor(5, 0, light, 0);
  strip.show();}
  else 
  {strip.setPixelColor(5, 0, 0, 0);
  strip.show();}
  if(minute >= 40 && minute < 60) 
  {strip.setPixelColor(6, 0, light, 0);
  strip.show();} 
  else
  {strip.setPixelColor(6, 0, 0, 0);
  strip.show();}

  //hour units
  if(hunit == 1 || hunit == 3 || hunit == 5 || hunit == 7 || hunit == 9)
  {strip.setPixelColor(7, 0, light, 0);
  strip.show();}
  else 
  {strip.setPixelColor(7, 0, 0, 0);
  strip.show();}
  if(hunit == 2 || hunit == 3 || hunit == 6 || hunit == 7)
  {strip.setPixelColor(8, 0, light, 0);
  strip.show();}
  else
  {strip.setPixelColor(8, 0, 0, 0);
  strip.show();}
  if(hunit == 4 || hunit == 5 || hunit == 6 || hunit == 7) 
  {strip.setPixelColor(9, 0, light, 0);
  strip.show();}
  else {strip.setPixelColor(9, 0, 0, 0);
  strip.show();}
  if(hunit == 8 || hunit == 9)
  {strip.setPixelColor(10, 0, light, 0);
  strip.show();}
  else
  {strip.setPixelColor(10, 0, 0, 0);
  strip.show();}

  //hour
  if(hour >= 10 && hour < 20)  
  {strip.setPixelColor(11, 0, light, 0);
  strip.show();} 
  else
  {strip.setPixelColor(11, 0, 0, 0);
  strip.show();}

 // }

  valm = digitalRead(14);    // add one minute when pressed
   if(valm== LOW) {
   minute++;
   second=0;
   delay(250);
  }
  
  valh = digitalRead(19);    // add one hour when pressed
   if(valh==LOW) {
   hour++;
   second=0;
   delay(250);
  }
}
