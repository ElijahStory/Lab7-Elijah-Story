//Elijah Story
//10-23-2020
//Lab7 RGB LED

//Followed the video in the lab instructions.
//Sets the color of an RGB LED based on the valuse given to each leg.
//Diagram of wiring in README.

//sets up the pins that are used
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

//this is the delay between colors in milliseconds
int delayTime = 1000;

void setup() {
  pinMode(redPin, OUTPUT);    //sets pin 9 to output
  pinMode(greenPin, OUTPUT);  //sets pin 10 to output
  pinMode(bluePin, OUTPUT);   //sets pin 11 to output

}

void loop() {
  setColor(255, 0, 0);        //red
  delay(delayTime);
  setColor(255, 127, 0);      //orange
  delay(delayTime);
  setColor(255, 255, 0);      //yellow
  delay(delayTime);
  setColor(0, 255, 0);        //green
  delay(delayTime);
  setColor(0, 0, 255);        //blue
  delay(delayTime);
  setColor(75, 0, 130);       //indigo
  delay(delayTime);
  setColor(143, 0, 255);      //violet
  delay(delayTime);

}

//this function sets the pin values base on its input
void setColor(int red, int green, int blue){
  analogWrite(redPin, red);         //sets the red pin
  analogWrite(greenPin, green);     //sets the green pin
  analogWrite(bluePin, blue);       //sets the blue pin
}