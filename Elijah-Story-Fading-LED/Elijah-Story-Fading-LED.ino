//Elijah Story
//10-23-2020
//Lab7 Fading LED

//Followed the video in the lab instructions.
//Turns the light on and off with a fade.
//Diagram of wiring in README.

//Setting up the variables that will not be changed.
const int buttonPin = 2;      //will get input from pin 2
const int ledPin = 9;         //will output from pin 9
const int fadingDelay = 50;   //the delay the led will fade in milliseconds


int buttonState = 0;          //will say if the button is pressed or not
boolean fadingState = false;  //says if the light is on or off

void setup() {
  pinMode(ledPin, OUTPUT);    //this will control the LEDs fade
  pinMode(buttonPin, INPUT);  //this reads the button press

}

void loop() {
  buttonState = digitalRead(buttonPin); //checks the state of the button

  if(buttonState == HIGH){              //if the button is pressed
    if(fadingState == false){           //if the light is off
      for (int i = 0; i <= 255; i += 5){
        analogWrite(ledPin, i);         //adds more power to LED based on loop
        delay(fadingDelay);             //waits to give the fade affect
      }
    }else{                              //if the light is on
      for (int i = 255; i >= 0; i -= 5){
        analogWrite(ledPin, i);         //takes power from LED based on loop
        delay(fadingDelay);             //waits to give the fade affect
      }
    }
    fadingState = !fadingState;         //switch the state saying if the light is on or off.
  }
}
