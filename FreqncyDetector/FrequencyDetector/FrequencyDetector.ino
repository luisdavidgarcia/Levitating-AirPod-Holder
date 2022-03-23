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

//Code Electromagnet
//digitalWrite(relay_5V_pin,HIGH);
// delay(3000);
//  digitalWrite(relay_5V_pin,LOW);
//  delay(3000);

  //int originalFrequency = recordFrequency();
//  for (int n = 0; n < 50; n++)
//  {
//    if (FreqCount.available()) 
//    {
//      frequency = FreqCount.read();
//    }
//  }
//  Serial.println(frequency);
//  delay(3000);
//  FreqCount.end();
//
//  for (int n = 0; n < 50; n++)
//  {
//    FreqCount.begin(1000);
//    if (FreqCount.available()) 
//    {
//      frequency2 = FreqCount.read();
//    }
//  }
//  Serial.println(frequency2);
//  delay(3000);
//  FreqCount.end();
//  //Serial.println(originalFrequency);
