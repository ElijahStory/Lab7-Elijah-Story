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

const int colors[][3] = {{255, 0, 0},{255, 127, 0},{255, 255, 0},{0, 255, 0},{0, 0, 255},{75, 0, 130},{143, 0, 255}};


void setup() {
  pinMode(redPin, OUTPUT);    //sets pin 9 to output
  pinMode(greenPin, OUTPUT);  //sets pin 10 to output
  pinMode(bluePin, OUTPUT);   //sets pin 11 to output
  pinMode(buttonPin, INPUT);  //this reads the button press

  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin); //checks the state of the button

  if(buttonState == HIGH){              //if the button is pressed
    if(!fadingState){
        fadingState = true;
        adjust(-stepAdjust);
        index++;
        adjust(stepAdjust);
        fadingState = false;
    }
  }
}

void adjust(int change){
    for(int i = 0; i < 255; i += stepAdjust){
        redValue += colors[index%sizeof(colors)][0] / change;
        greenValue += colors[index%sizeof(colors)][1] / change;
        blueValue += colors[index%sizeof(colors)][2] / change;
        setColor(redValue,greenValue,blueValue);
        Serial.println(colors[index%sizeof(colors)][2] / change);
        delay(fadingDelay);
    }
}

//this function sets the pin values base on its input
void setColor(float red, float green, float blue){
  analogWrite(redPin, red);         //sets the red pin
  analogWrite(greenPin, green);     //sets the green pin
  analogWrite(bluePin, blue);       //sets the blue pin
}
