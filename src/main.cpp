#include <Arduino.h>

/*
 ESP8266 Blink by Simon Peter
 Blink the blue LED on the ESP-01 module
 This example code is in the public domain

 The blue LED on the ESP-01 module is connected to GPIO1 
 (which is also the TXD pin; so we cannot use Serial.print() at the same time)
*/

#include <ESP8266WiFi.h>            // we need wifi to get internet access
#include <time.h>                   // time() ctime()

// These variables store the flash pattern
// and the current state of the LED

int ledPin =  1;                  // GPIO1 = blaue LED
int ledState = LOW;               // ledState used to set the LED
unsigned long previousMillis = 0; // will store last time LED was updated
long OnTime = 600;                 // milliseconds of on-time
long OffTime = 150;               // milliseconds of off-time



void setup() 
{
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, 0);
  //Serial.begin(115200);
  //delay(3000);   
}

void loop()
{
  // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();
 
  if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
  {
    previousMillis += OnTime;          // on time is over, set new start
    ledState = LOW;                    // Turn it off
    digitalWrite(ledPin, ledState);    // Update the actual LED
    //Serial.println(previousMillis);
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
  {
    previousMillis += OffTime;           // off time is over, set new start
    ledState = HIGH;                     // turn it on
    digitalWrite(ledPin, ledState);	     // Update the actual LED
    //Serial.println(previousMillis);
  }
}
