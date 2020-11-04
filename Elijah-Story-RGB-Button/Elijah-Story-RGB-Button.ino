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
const int[][] colors = {{255, 0, 0},{255, 127, 0},{255, 255, 0},{0, 255, 0},{0, 0, 255},{75, 0, 130},{143, 0, 255}};

//Setting up the variables that will hold the values for each color
int redValue = 0;
int greenValue = 0;
int blueValue = 0;
int index = 0;
int step = 5;

int buttonState = 0;          //will say if the button is pressed or not
boolean fadingState = false;  //says if the light is changing

void setup() {
  pinMode(redPin, OUTPUT);    //sets pin 9 to output
  pinMode(greenPin, OUTPUT);  //sets pin 10 to output
  pinMode(bluePin, OUTPUT);   //sets pin 11 to output
  pinMode(buttonPin, INPUT);  //this reads the button press

}

void loop() {
  buttonState = digitalRead(buttonPin); //checks the state of the button

  if(buttonState == HIGH){              //if the button is pressed
    if(!fadingState){
        fadingState = ture;
        adjust(-step);
        index++;
        adjust(step);
    }
  }
}

void adjust(int change){
    for(int i = 0; i < 255; i += step){
        redValue += 255 / colors[index][0];
        greenValue += 255 / colors[index][1];
        blueValue += 255 / colors[index][2];
        setColor(redValue,greenValue,blueValue);
    }
}

//this function sets the pin values base on its input
void setColor(int red, int green, int blue){
  analogWrite(redPin, red);         //sets the red pin
  analogWrite(greenPin, green);     //sets the green pin
  analogWrite(bluePin, blue);       //sets the blue pin
}