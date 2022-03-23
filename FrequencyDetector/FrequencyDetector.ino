#include <FreqCount.h>

//Needs to use Pin 5 for Frequency Reading
// Link to Instructions: https://www.pjrc.com/teensy/td_libs_FreqCount.html
int relay_5V_pin = 9;
unsigned long frequency_NoMarble = 23500; //assign a value to this one after calibrating

void setup() {
  Serial.begin(57600);
  FreqCount.begin(1000);
  pinMode(relay_5V_pin,OUTPUT);
  digitalWrite(relay_5V_pin,HIGH);
}

void loop() {
   if (FreqCount.available()) 
   {
       unsigned long count = FreqCount.read();
       Serial.println(count);
       if (count  < frequency_NoMarble)
       {
         digitalWrite(relay_5V_pin,LOW);
         delay(1000);
         digitalWrite(relay_5V_pin,HIGH);
         delay(1000);
       }
    }
}

