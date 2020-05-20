#include <Servo.h>
Servo myservo;                                  // create servo object to control a servo
  //-- function list
  void servo();
  void select();
  void servoup();
  void servodown();
  
  //---pin list
  const int button1 = 2;
  const int button2 = 3;
  const int button3 = 4;
  const int button4 = 5;
  //---servo is on pin 9 via myservo
  
  //---variables that change
  int buttonState1;
  int buttonState2;
  int buttonState3;
  int buttonState4;
  int pos = 0;                                    // variable to store the servo position     
  //---

void setup() {
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);
    pinMode(button4, INPUT);
    Serial.begin(9600);                           // this starts the serial monitor 
    Serial.println("serial is running");          // open the "serial monitor" in the tools section of this ide. this will print this line of text in the serial monitor, this is used for debugging.
  }//end setup
void loop() {
  int tog;
  /*
      digitalRead(button1);
      digitalRead(button2);
      digitalRead(button3);
      digitalRead(button4);
  */  
      buttonState1 = digitalRead(button1);
      buttonState2 = digitalRead(button2);
      buttonState3 = digitalRead(button3);
      buttonState4 = digitalRead(button4);
      delay(100);   
          Serial.println("button 1");
      Serial.println(buttonState1);        
          Serial.println("button 2");
      Serial.println(buttonState2);        
          Serial.println("button 3");
      Serial.println(buttonState3);        
          Serial.println("button 4");
      Serial.println(buttonState4);       
        Serial.println("toggle is ");
      Serial.println(tog);
      delay(100);    
  
  //---BUTTON1 
        if(buttonState1 == LOW){
          Serial.println("button one pressed");
          servo();
          delay(100);
          }
  //--- button2
     /*   if(buttonState2 == LOW){
          tog == 2;}
          delay(100);
     */
  //--- button3
        if(buttonState3 == LOW){
         Serial.println("going up");
       servoup();
          delay(100);
        }
  //--- button4
        if(buttonState4 == LOW){
              Serial.println("going down");
            servodown();
          delay(100);
         }
  //=========button toggles end
  
  delay(3000);
  loop();
  }//end loop
void servo(){
        myservo.attach(9);                     // attaches the servo on pin 9 to the servo object  
        pos == 0;
        myservo.write(pos);
     
        //------
         for (pos = 0; pos <= 30; pos += 1) {  // goes from 0 degrees to 180 degrees in steps of 1 degree
         myservo.write(pos);                   // tell servo to go to position in variable 'pos'
         delay(15);                            // waits 15ms for the servo to reach the position
        }
        //----------  
  
        //----------
        for (pos = 30; pos >= 0; pos -= 1) {  // goes from 180 degrees to 0 degrees
        myservo.write(pos);                   // tell servo to go to position in variable 'pos'
        delay(15);                            // waits 15ms for the servo to reach the position
        }
        pos == 0;
        myservo.detach();
  }//end servo
void servoup(){      
        myservo.attach(9);                    // attaches the servo on pin 9 to the servo object  
        pos == 0;
        myservo.write(pos);
  //-----------
    do{
        do{
        pos == pos+1;
        myservo.write(pos);                   // tell servo to go to position in variable 'pos'
        delay(50);                            // waits 15ms for the servo to reach the position
        }while(pos < 90);    
        buttonState3 = digitalRead(button3);
    
    }while(buttonState3 == LOW);
     //------------ 
      pos == 0;
      myservo.write(pos);
      myservo.detach();
      loop();
  }//end servo group
void servodown(){
        myservo.attach(9);                      // attaches the servo on pin 9 to the servo object  
        pos == 180;
        myservo.write(pos);
  //-----------
    do{
        do{
        pos == pos-1;
        myservo.write(pos);                   // tell servo to go to position in variable 'pos'
        delay(15);                            // waits 15ms for the servo to reach the position
        }
        while(pos < 0);
        buttonState4 = digitalRead(button4);
    }
     while(buttonState4 == LOW);
     //------------ 
      pos == 0;
      myservo.write(pos);
      myservo.detach();
      loop();
  }//end servodown
void select(){

}//end selection
