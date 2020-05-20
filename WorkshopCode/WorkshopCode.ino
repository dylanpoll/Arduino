/* Made by Dylan Poll
 * https://github.com/dylanpoll/Arduino
 * for my intro workshop, you can do it online with a simulator on freeCAD
 * https://sites.google.com/view/valencia-robotics/arduino?authuser=0
 */                                                         //  "//" is used to make comments, "/*  */" is used to make comments for a section like above.
                                                            
  const int ledPin = 9;                                     // choose the pin for the LED
  const int inPin = 7;                                      // choose the input pin (for a pushbutton)
  
  int fadeAmount = 5;                                       // how many points to fade the LED by
  int brightness;                                           // how bright the LED is
  int buttonstate;                                          // variable for reading the pin status
  int toggle = 0;                                           // this toggles the button 
  
  void fadeout();                                           // the code that turns the led off 
  void fadein();                                            // the code that turns the led on

//--------------------------------------------------------
void setup() {
      pinMode(ledPin, OUTPUT);                              // declare LED as output
      pinMode(inPin, INPUT);                                // declare pushbutton as input
    
      Serial.begin(9600);                                   // this starts the serial monitor 
      Serial.println("serial is running");                  // open the "serial monitor" in the tools section of this ide. this will print this line of text in the serial monitor, this is used for debugging. 
   }//end of void setup    
//--------------------------------------------------------I use the void loop as a menu select in this code.
void loop(){  
        buttonstate = digitalRead(inPin);                   // read input value of push button              
          
        if (buttonstate == LOW) {                           // if the button is pressed, this will be satisfied, and that will allow the user to turn on or off the LED.
    
                                                            // this tells the user the toggle has started.
                    Serial.println("Toggle has been pressed, release within 2 seconds unless you want to turn off the light"); 
                    delay (1000);
                    toggle = 0;}                            // this sets the toggle to zero allowing for the next if statement to be executed.
                    
        if (toggle == 0){ do{  
        delay (1000);                                       // I use delays so that using the terminal monitor isn't awful and the user has time to move their finger. the delays are in miliseconds, so this is 1 second.
        
        buttonstate = digitalRead(inPin);                   // this tells the arduino to make another check for the buttonstate, so if its being pressed or not. 
        
            if (buttonstate == LOW) {                       // if it is being pressed, sends user to fadeout and that will dim the light until its off.
               fadeout();    
               loop();} 
            if (buttonstate == HIGH) {                      // check if the input is HIGH (button released) and sends the user to the fadein function that powers the led on.
                fadein();
                loop();}
            else{                                           // this is incase something is wrong, if there is no high or low input this should print.
              Serial.println("\nwiring is not working....");    
              delay (30);
              toggle = 1;
        } toggle = 1;}
        while(toggle == 0);                                 // this is the condition for the do while loop, so once this is run the condition is no longer met and it just constantly loops checking the toggle value. 
        }
        else {
          loop();
        }
      }//end of void loop
    void fadein(){
      if ( brightness < 255){                               // the max brightness for the LED is 255 in this case, this code is written so that the light will turn on until its brightest so if its less than 255, it will go up to 255.
      Serial.println("\n HIGH! input");
      Serial.println("raising the brightness!");
          do{delay (30);                                    //this is used to control the brightness, less than and greater than operators and brightness is the "iterator" and fade amount is the amount it changes by.
                   if(brightness < 250){ brightness = brightness + fadeAmount;    
                   analogWrite(ledPin, brightness);         // if you don't put this here, the light wont reflect the changes made to the varieble "brightness".  
                   delay (30);}}
          while(brightness <250);
                  delay (30);
                  toggle = 1;
                  Serial.println("done!");
                  loop();}
    else                                                    // if its already bright enough.
    {  
      toggle = 1;
      loop();
    }
  }//end of void loop
//--------------------------------------------------------
void fadeout(){
      if ( brightness > 0){                                 // this checks if its off, if it isn't at 0 than it brings it down to 0.
      Serial.println("\n LOW! input");
      Serial.println("dropping the brightness");
      delay (30);
            if(brightness > 0){
              do{brightness = brightness - fadeAmount;
                 analogWrite(ledPin, brightness);           // if you don't put this here, the light wont reflect the changes made to the varieble "brightness".  
                 delay (30);}
              while(brightness > 0);
         
             delay (30);}
             toggle = 1;
             Serial.println("done!");
             loop();}
    else
    {  
      toggle = 1;
      loop();
    }
  }//end of void fadeout
