//the Arduino Script and walk through and setup of the home lab was done by : Dylan Poll
//https://www.linkedin.com/in/dylan-poll-4a324a1a2/
//this was part of the who is home project. It used a pi to check mac addresses of devices on the network
//to light up leds be color, the project used the mac addresses of cell phones to see who was home.
//https://github.com/dylanpoll/WhoIsHome
// I used the FastLED libraries demo-reel as a foundation for this, please check out the fastLED github!!
//https://github.com/FastLED/FastLED/wiki/Overview

#include <FastLED.h>
FASTLED_USING_NAMESPACE
#define DATA_PIN    9
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS    10
CRGB leds[NUM_LEDS];
#define BRIGHTNESS  10
#define FRAMES_PER_SECOND  20

char person = 'F';// the default value that gets ignored

//below are all used to identify people
int d=0;//person 1
int l=0;//person 2
int k=0;//person 3
int j=0;//person 4

int count;//count used to check if each person is or is not home. goes up to 4 in this case.

void RunTheLights();

void setup() {
  delay(3000); // 3 second delay for recovery
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.delay(1000/FRAMES_PER_SECOND);
  Serial.begin(9600);//serial is used for inputs
}


void loop(){
  
   if (Serial.available() > 0) {     //checks that serial is running or this will not work
    
        Serial.println();// clears the prior value read.
        person = Serial.read();      //reads input value
        delay(1000);//one second delay
                       
        switch(person){     //this checks the person against our possible casses.
            case'D':
              d = 1;        // 0 is for not present or untrue, 1 is used for true IN THIS SWITCH CASE, UPPERCASE is true, LOWERCASE is false
              person = 'F'; //resets the value of person
              count=count+1;//a person has been checked so it adds a +1 to the count
              break;        //this is the same setup for all switch cases but F, f does not add to the count.
            case'd':
              d = 0;
              person = 'F'; 
              count=count+1;
              break;
            case'L':
            
              l = 1;
              person = 'F';
              count=count+1;
              break;
            case'l': 
            
              l = 0;
              person = 'F';
              count=count+1;
              break;
            case'K':
            
              k = 1;
              person = 'F';
              count=count+1;
              break;
            case'k':
            
              k = 0;
              person = 'F';
              count=count+1;
              break;
            case'J':
            
              j = 1;
              person = 'F';
              count=count+1;
              break;
            case'j':
            
              j = 0;
              person = 'F';
              count=count+1;
              break;
            case'F':                //simply breaks without incrimenting 
              break;                //because we only want to have the count change after reading if a person is or is not home
            }                       //if the resault is F we know it did not get a proper input so the loop continues.
            
  if(count == 4){RunTheLights();}   //if the count is at 4, it will start the function "RunTheLights"
  }
}

void RunTheLights(){                //first set them all to off
        leds[0] =  CRGB::Black;
        leds[1] =  CRGB::Black;
        leds[2] =  CRGB::Black; 
        leds[3] =  CRGB::Black; 
        leds[4] =  CRGB::Black;
        leds[5] =  CRGB::Black; 
        leds[6] =  CRGB::Black; 
        leds[7] =  CRGB::Black;
        leds[8] =  CRGB::Black;
        leds[9] =  CRGB::Black; 
                                    //turn on lights for the "people" who are home.
                                    
    if(d == 1){                     //if person is home  
        leds[0] = 0xdd8bff;         //turn on led 1 and the color will be purple 
        leds[1] = 0xdd8bff;}        //turn on led 2 and the color will be purple 
    if(l == 1){                     //if you want some extra colors.. you can use hex values like  0x00ffe2 for  blue
        leds[2] = CRGB::Green; 
        leds[3] = CRGB::Green;}
    if(k == 1){
        leds[4] = CRGB::Red;  
        leds[5] = CRGB::Red; }
    if(j == 1){
        leds[6] = CRGB::Blue; 
        leds[7] = CRGB::Blue;}
        
FastLED.show();                     //this will "show" or light the LEDs according to our list above
                                    //the list above is tells fast.led what LED WILL be what color once .show() is called, so colors won't change
                                    //until FastLED.show();

delay(30000);                       //30 second wait 
                        
  d=0;                              //reset all people to false
  l=0;
  k=0;
  j=0;
count=0;                            //reset count to 0
person = 'F';                       //reset the last serial input to F
}
