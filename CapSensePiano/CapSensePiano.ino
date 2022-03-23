/*
  Capacitive-Touch Arduino Keyboard Piano
  
  Plays piano tones through a buzzer when the user taps touch-sensitive piano "keys"
  
  Created  18 May 2013
  Modified 23 May 2013
  by Tyler Crumpton and Nicholas Jones
  
  This code is released to the public domain. For information about the circuit,
  visit the Instructable tutorial at http://www.instructables.com/id/Capacitive-Touch-Arduino-Keyboard-Piano/
*/
#include <CapacitiveSensor.h>
#include "pitches.h"
//#include <FreqCount.h>

#define COMMON_PIN      2    // The common 'send' pin for all keys
#define BUZZER_PIN      A4   // The output pin for the piezo buzzer
#define NUM_OF_SAMPLES  20   // Higher number whens more delay but more consistent readings
#define CAP_THRESHOLD   300  // Capactive reading that triggers a note (adjust to fit your needs)
#define NUM_OF_KEYS     4    // Number of keys that are on the keyboard
#define LED_PIN         8 

//FreqCount Frequency Measurment relies on pin 5
int relay_5V_pin = 9;


// This macro creates a capacitance "key" sensor object for each key on the piano keyboard:
#define CS(Y) CapacitiveSensor(2, Y)

// Each key corresponds to a note, which are defined here. Uncomment the scale that you want to use:
int notes[]={NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4}; // C-Major scale

// Defines the pins that the keys are connected to:
CapacitiveSensor keys[] = {CS(3), CS(4), CS(5), CS(6)};

// Define Correct Sequence to Unlock Magnet
int code[4] = {0, 3, 2, 1};
int code2[4] = {notes[0], notes[3], notes[2], notes[1]};
int count = 0;
double sum = 0;
int lastPressed = 4;

void setup() { 
   Serial.begin(57600);
//   FreqCount.begin(1000);
     pinMode(relay_5V_pin,OUTPUT);
  //digitalWrite(relay_5V_pin,HIGH);
 // Turn off autocalibrate on all channels:
  for(int i = 0; i < 4; ++i) {
    keys[i].set_CS_AutocaL_Millis(0xFFFFFFFF);
  }
  // Set the buzzer as an output:
  pinMode(BUZZER_PIN, OUTPUT); 
  //Set the LED as an ouput:
  pinMode(LED_PIN, OUTPUT);
}

void loop(){   
  // Code for Metal Detector 
//   if (FreqCount.available()) 
//   {
//       unsigned long frequency = FreqCount.read();
//       Serial.println(frequency);
//       if (frequency  < 12200)
//       {
//         digitalWrite(relay_5V_pin,LOW);
//         delay(5000);
//         //digitalWrite(relay_5V_pin,HIGH);
//         //delay(5000);
//       }
//    }

  // Code for Piano
  // Loop through each key:
  for (int i = 0; i < 4; ++i) {
    // If the capacitance reading is greater than the threshold, play a note:
    if(keys[i].capacitiveSensor(NUM_OF_SAMPLES) > CAP_THRESHOLD) {
      tone(BUZZER_PIN, notes[i]); // Plays the note corresponding to the key pressed
      delay(1000);
      noTone(BUZZER_PIN);
      if (i != lastPressed){
        if(code[count] == i){
          count++;
          lastPressed = i;
      
          //correctly entered key sequence
          if (count == 4){
            digitalWrite(LED_PIN, HIGH);
            delay(3000); //increase delay times so that when key presses are complete their individual sounds
            noTone(BUZZER_PIN);
            delay(3000);
            digitalWrite(LED_PIN, LOW);
            
          }
        }
        else {
            count = 0;
            lastPressed = 4;
        }
      }
    }
  }
}
  
