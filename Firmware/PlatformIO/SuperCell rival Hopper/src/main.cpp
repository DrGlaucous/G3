//configuration (not enough options to warrant a completely new file)

#define DEBUG_MODE//un-comment this to enable some serial printing of variables


#define I2C //use i2c for controlling the supercell (the supercell expects a 3-byte stream, one for on/off, one for fan, and one for Agitator speed)
#define I2C_CHANNEL 2//the channel the pack will listen on for commands
//if using an arduino nano, SCL is A5 and SDA is A4

//pin definitions
//outputs (MUST be PWM)
#define FAN_PIN 7//pin for the ESC
#define AGITATOR_PIN 3//pin for agitator motor
//inputs
#define TRIGGER_PIN 2
#define AGITATOR_POT 7
#define FAN_POT 6



#define POT_MIN_VALUE 0
#define POT_MAX_VALUE 1023

#define IDLE_ANGLE 37//(the angle that the ESC sits at when "off")
#define MAX_ANGLE 180//the angle of the ESC when it is at its fullest

#define ON_STATE 1//the state of the button when "on" (only applies when using manual control)

//end configuration


#include <Arduino.h>
#include <Servo.h>


#ifdef I2C
#include <Wire.h>
#endif

//global objects
unsigned char Angle {};//esc angle
unsigned char AgitatorSpeed {};
bool isON {};

//for the clock
unsigned long MillisecondTicks{};
unsigned long MicrosecondTicks{};
unsigned long LastMillisecondTicks{};//previous values
unsigned long LastMicrosecondTicks{};

//servo object for the fan
Servo ESCServo;


//we want a set of variables to control our blower and agitator
//3 total: blower speed, agitator speed, GO

//System clock
void GetTicks(void)
{
	LastMillisecondTicks = MillisecondTicks;
	LastMicrosecondTicks = MicrosecondTicks;

	MillisecondTicks = millis();
	MicrosecondTicks = micros();
}

//drives the blower
void BlowerHandler(void)
{

  if(isON == ON_STATE)
  {
    ESCServo.write(Angle);
  }
  else if(ESCServo.read() > IDLE_ANGLE &&
  MillisecondTicks % 5 == 0 &&
  MillisecondTicks != LastMillisecondTicks)//once every 10 milliseconds
  {

    //decrement servo when not in use
    ESCServo.write(ESCServo.read() - 1);
  }


}

//takes the variables and drives the agitator with them
void AgitatorHandler(void)
{
  if(isON == ON_STATE)
  {
    analogWrite(AGITATOR_PIN, AgitatorSpeed);
  }
  else
  {
    analogWrite(AGITATOR_PIN, 0);
  }

}

//function that reads the pots and buttons to get the values for driving the pack
void IORead(void)
{
  //ESC
  Angle = map(analogRead(FAN_POT), POT_MIN_VALUE, POT_MAX_VALUE, IDLE_ANGLE, MAX_ANGLE);

  AgitatorSpeed = map(analogRead(AGITATOR_POT), POT_MIN_VALUE , POT_MAX_VALUE, 0, 255);

  isON = digitalRead(TRIGGER_PIN);

}

//function that gets the values from the controller device for driving the pack
#ifdef I2C
void i2cRead(int byteCount)
{

  //we should get 3 bytes: one for trigger, one for fan, and one for motor
  if(byteCount != 3)//if this is not the case, break out
  {
#ifdef DEBUG_MODE
    Serial.print("Error: Gor byte count: ");
    Serial.println(byteCount);
#endif
    return;
  }

  //should read a sequence of 3 bytes containing the needed information
  isON = Wire.read();
  Angle = Wire.read();
  AgitatorSpeed = Wire.read();


#ifdef DEBUG_MODE
  Serial.print(byteCount);
  Serial.print(": ");
  Serial.println(int(isON));
#endif



}
#endif

void setup() {


#ifdef I2C
  Wire.begin(I2C_CHANNEL);
  Wire.onReceive(i2cRead);
#endif

  pinMode(TRIGGER_PIN, INPUT_PULLUP);
  Angle = IDLE_ANGLE;
  ESCServo.attach(FAN_PIN);
  ESCServo.write(Angle);



  //debug stuff
#ifdef DEBUG_MODE
  Serial.begin(9600);
#endif


}

void loop() {

  GetTicks();

#ifndef I2C
  IORead();
#endif

  BlowerHandler();
  AgitatorHandler();




}