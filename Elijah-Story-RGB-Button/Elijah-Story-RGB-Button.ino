//Elijah Story
//11-04-2020
//Lab7 RGB LED and button

//This code merdges Both of the other code parts of this lab (RGB and the Button Fading)
//Diagram of wiring in README.

//Setting up the variables that will not be changed.
const int buttonPin = 2;      //will get input from pin 2
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int fadingDelay = 50;   //the delay the led will fade in milliseconds

//Setting up the variables that will hold the values for each color
float redValue = 255;
float greenValue = 0;
float blueValue = 0;
int index = 0;
int stepAdjust = 5;

int buttonState = 0;          //will say if the button is pressed or not
boolean fadingState = false;  //says if the light is changing

float colors[][3] = {{255, 0, 0}, {142, 68, 173}, {149, 165, 166}, {0, 255, 0}, {22, 188, 156}, {75, 0, 130}, {211, 84, 0}};


void setup() {
  pinMode(redPin, OUTPUT);    //sets pin 9 to output
  pinMode(greenPin, OUTPUT);  //sets pin 10 to output
  pinMode(bluePin, OUTPUT);   //sets pin 11 to output
  pinMode(buttonPin, INPUT);  //this reads the button press

  Serial.begin(9600);

//  for (int i = 0; i < 7; i++) {
//    colors[i][0] = colors[i][0] / (255 / stepAdjust);
//    colors[i][1] = colors[i][1] / (255 / stepAdjust);
//    colors[i][2] = colors[i][2] / (255 / stepAdjust);
//  }
  setColor(redValue, greenValue, blueValue);
}

void loop() {
  buttonState = digitalRead(buttonPin); //checks the state of the button

  if (buttonState == HIGH) {            //if the button is pressed
    if (!fadingState) {
      fadingState = true;
      adjust(-1);
      index++;
      adjust(1);
      fadingState = false;
    }
  }
}

void adjust(int change) {
  int sizeArray = (sizeof(colors) / sizeof(colors[0]));
  for (int i = 0; i < 255; i += stepAdjust) {
    redValue += colors[index % sizeArray][0] / (255 / stepAdjust) * change;
    greenValue += colors[index % sizeArray][1] / (255 / stepAdjust) * change;
    blueValue += colors[index % sizeArray][2] / (255 / stepAdjust) * change;
    setColor(redValue, greenValue, blueValue);
    delay(fadingDelay);
  }
}

//this function sets the pin values base on its input
void setColor(float red, float green, float blue) {
  analogWrite(redPin, red);         //sets the red pin
  analogWrite(greenPin, green);     //sets the green pin
  analogWrite(bluePin, blue);       //sets the blue pin
}
