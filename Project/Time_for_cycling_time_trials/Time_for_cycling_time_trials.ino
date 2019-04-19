// CheapStepper - Version: Latest 
#include <CheapStepper.h>

#include <Stepper.h>

#include <Adafruit_NeoPixel.h> 
#define PIN 8
#include <TimerOne.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(88, PIN, NEO_GRB + NEO_KHZ800); 

CheapStepper stepper (10,11,12,13); 



const int stopstart = A4;
const int reset = A5;
const int buzz = 9;

int State;
int pushbutton;
int resets;
int motor = 10;
int LDR = A3;
int LDRval = 0;

bool paused = false;
bool lastState;
bool reseted = false;
boolean moveClockwise = true;

int r =0;
int g = 0;
int b = 100;
int segment;

unsigned char ten;
unsigned char seconds;
unsigned char Lmiliseconds;
unsigned char mili;

unsigned long count=6000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(! Serial);
  Serial.println("Speed 0 to 255");
  pinMode(reset, INPUT);
  pinMode(stopstart, INPUT);
  pinMode(buzz, OUTPUT);
  Timer1.initialize(10000);
 Timer1.attachInterrupt(startcountdown);
  strip.begin();

}

void screen(){
segmentPicker(4);
  numbers(Lmiliseconds);

    segmentPicker(3);
 numbers(mili);

  segmentPicker(2);
  numbers(seconds);

 segmentPicker(1);
  numbers(ten);

 
}

void loop() {
  
 if(resets==LOW)
{count=1000;}
     
   State = digitalRead(A4);// Reads inputy of start stop button

  if (State != lastState) // if button is pressed and has a value >0
  { 
    if (State == HIGH) // if state is high
    {
      pushbutton++; // Increase the amount of times pushed
    }
  }
  lastState = State; // reset the amount of times pushed
 
  if (pushbutton %2 != 1) // fiqures out what state the button is in
  {
      paused = false;
  }
  else  {paused = true;}
  
  LDRval = analogRead(LDR);
  Serial.println(LDRval);

  ten = (count/1000);
  seconds = ((count%1000)/100);
  mili =  ((count%100)/10);
  Lmiliseconds = (count%10);
  //Serial.println(count);
  screen();
 
  resets = digitalRead(A5);
  
}
void segmentPicker(int segmentToDisplay)
{
  switch (segmentToDisplay)
  {
    case 1:
  
    segment =(0);
    break;

    case 2:
    
    segment =(21);
    break;

    case 3:
   
    segment =(42);
    break;

    case 4:
    segment =(63);
    break;
  }
}

void numbers(int numberToDisplay)
{
  switch (numberToDisplay)
  {
    case 0:
strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment Bm
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment,r,g,b); //Segment D
strip.setPixelColor(10+segment,r,g,b); //Segment D
strip.setPixelColor(11+segment,r,g,b); //Segment D
strip.setPixelColor(12+segment,r,g,b); //Segment E
strip.setPixelColor(13+segment,r,g,b); //Segment E
strip.setPixelColor(14+segment,r,g,b); //Segment E
strip.setPixelColor(15+segment,r,g,b); //Segment F
strip.setPixelColor(16+segment,r,g,b); //Segment F
strip.setPixelColor(17+segment,r,g,b); //Segment F
strip.setPixelColor(18+segment, 0, 0, 0);
strip.setPixelColor(19+segment, 0, 0, 0);
strip.setPixelColor(20+segment, 0, 0, 0);
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 1:
strip.setPixelColor(0+segment,0,0,0); //Segment A
strip.setPixelColor(1+segment,0,0,0); //Segment A
strip.setPixelColor(2+segment,0,0,0); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment,0,0,0); //Segment D
strip.setPixelColor(10+segment,0,0,0); //Segment D
strip.setPixelColor(11+segment,0,0,0); //Segment D
strip.setPixelColor(12+segment,0,0,0); //Segment E
strip.setPixelColor(13+segment,0,0,0); //Segment E
strip.setPixelColor(14+segment,0,0,0); //Segment E
strip.setPixelColor(15+segment,0,0,0); //Segment F
strip.setPixelColor(16+segment,0,0,0); //Segment F
strip.setPixelColor(17+segment,0,0,0); //Segment F
strip.setPixelColor(18+segment, 0, 0, 0);
strip.setPixelColor(19+segment, 0, 0, 0);
strip.setPixelColor(20+segment, 0, 0, 0);
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 2:

strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment, 0, 0, 0);
strip.setPixelColor(7+segment, 0, 0, 0);
strip.setPixelColor(8+segment, 0, 0, 0);
strip.setPixelColor(9+segment,r,g,b); //Segment D
strip.setPixelColor(10+segment,r,g,b); //Segment D
strip.setPixelColor(11+segment,r,g,b); //Segment D
strip.setPixelColor(12+segment,r,g,b); //Segment E
strip.setPixelColor(13+segment,r,g,b); //Segment E
strip.setPixelColor(14+segment,r,g,b); //Segment E
strip.setPixelColor(15+segment, 0, 0, 0);
strip.setPixelColor(16+segment, 0, 0, 0);
strip.setPixelColor(17+segment, 0, 0, 0);
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 3:

strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment,r,g,b); //Segment D
strip.setPixelColor(10+segment,r,g,b); //Segment D
strip.setPixelColor(11+segment,r,g,b); //Segment D
strip.setPixelColor(12+segment, 0, 0, 0);
strip.setPixelColor(12+segment, 0, 0, 0);
strip.setPixelColor(13+segment, 0, 0, 0);
strip.setPixelColor(14+segment, 0, 0, 0);
strip.setPixelColor(15+segment, 0, 0, 0);
strip.setPixelColor(16+segment, 0, 0, 0);
strip.setPixelColor(17+segment, 0, 0, 0);
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 4:
strip.setPixelColor(0+segment, 0, 0, 0);
strip.setPixelColor(1+segment, 0, 0, 0);
strip.setPixelColor(2+segment, 0, 0, 0);
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment, 0, 0, 0);
strip.setPixelColor(10+segment, 0, 0, 0);
strip.setPixelColor(11+segment, 0, 0, 0);
strip.setPixelColor(12+segment, 0, 0, 0);
strip.setPixelColor(13+segment, 0, 0, 0);
strip.setPixelColor(14+segment, 0, 0, 0);
strip.setPixelColor(15+segment,r,g,b); //Segment F
strip.setPixelColor(16+segment,r,g,b); //Segment F
strip.setPixelColor(17+segment,r,g,b); //Segment F
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 5:
strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment, 0, 0, 0);
strip.setPixelColor(4+segment, 0, 0, 0);
strip.setPixelColor(5+segment, 0, 0, 0);
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment,r,g,b); //Segment D
strip.setPixelColor(10+segment,r,g,b); //Segment D
strip.setPixelColor(11+segment,r,g,b); //Segment D
strip.setPixelColor(12+segment, 0, 0, 0);
strip.setPixelColor(13+segment, 0, 0, 0);
strip.setPixelColor(14+segment, 0, 0, 0);
strip.setPixelColor(15+segment,r,g,b); //Segment F
strip.setPixelColor(16+segment,r,g,b); //Segment F
strip.setPixelColor(17+segment,r,g,b); //Segment F
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 6:

strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment, 0, 0, 0);
strip.setPixelColor(4+segment, 0, 0, 0);
strip.setPixelColor(5+segment, 0, 0, 0);
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment,r,g,b); //Segment D
strip.setPixelColor(10+segment,r,g,b); //Segment D
strip.setPixelColor(11+segment,r,g,b); //Segment D
strip.setPixelColor(12+segment,r,g,b); //Segment E
strip.setPixelColor(13+segment,r,g,b); //Segment E
strip.setPixelColor(14+segment,r,g,b); //Segment E
strip.setPixelColor(15+segment,r,g,b); //Segment F
strip.setPixelColor(16+segment,r,g,b); //Segment F
strip.setPixelColor(17+segment,r,g,b); //Segment F
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 7:

strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment, 0, 0, 0);
strip.setPixelColor(10+segment, 0, 0, 0);
strip.setPixelColor(11+segment, 0, 0, 0);
strip.setPixelColor(12+segment, 0, 0, 0);
strip.setPixelColor(13+segment, 0, 0, 0);
strip.setPixelColor(14+segment, 0, 0, 0);
strip.setPixelColor(15+segment, 0, 0, 0);
strip.setPixelColor(16+segment, 0, 0, 0);
strip.setPixelColor(17+segment, 0, 0, 0);
strip.setPixelColor(18+segment, 0, 0, 0);
strip.setPixelColor(19+segment, 0, 0, 0);
strip.setPixelColor(20+segment, 0, 0, 0);
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 8:

strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment,r,g,b); //Segment D
strip.setPixelColor(10+segment,r,g,b); //Segment D
strip.setPixelColor(11+segment,r,g,b); //Segment D
strip.setPixelColor(12+segment,r,g,b); //Segment E
strip.setPixelColor(13+segment,r,g,b); //Segment E
strip.setPixelColor(14+segment,r,g,b); //Segment E
strip.setPixelColor(15+segment,r,g,b); //Segment F
strip.setPixelColor(16+segment,r,g,b); //Segment F
strip.setPixelColor(17+segment,r,g,b); //Segment F
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;

case 9:

strip.setPixelColor(0+segment,r,g,b); //Segment A
strip.setPixelColor(1+segment,r,g,b); //Segment A
strip.setPixelColor(2+segment,r,g,b); //Segment A
strip.setPixelColor(3+segment,r,g,b); //Segment B
strip.setPixelColor(4+segment,r,g,b); //Segment B
strip.setPixelColor(5+segment,r,g,b); //Segment B
strip.setPixelColor(6+segment,r,g,b); //Segment C
strip.setPixelColor(7+segment,r,g,b); //Segment C
strip.setPixelColor(8+segment,r,g,b); //Segment C
strip.setPixelColor(9+segment, 0, 0, 0);
strip.setPixelColor(10+segment, 0, 0, 0);
strip.setPixelColor(11+segment, 0, 0, 0);
strip.setPixelColor(12+segment, 0, 0, 0);
strip.setPixelColor(13+segment, 0, 0, 0);
strip.setPixelColor(14+segment, 0, 0, 0);
strip.setPixelColor(15+segment,r,g,b); //Segment F
strip.setPixelColor(16+segment,r,g,b); //Segment F
strip.setPixelColor(17+segment,r,g,b); //Segment F
strip.setPixelColor(18+segment,r,g,b); //Segment G
strip.setPixelColor(19+segment,r,g,b); //Segment G
strip.setPixelColor(20+segment,r,g,b); //Segment G
strip.setPixelColor(21+segment, 0, 0, 0);
strip.show();
break;


  }
}

void startcountdown()
{
  if(paused == false)
    {
    count--; 
    if(count == 3099)
  {
    tone(buzz, 1000,150);
  }
  
  if(count == 1099)
  {
    tone(buzz, 1000,150);
  }
  
  if(count == 599)
  {
    tone(buzz, 1000,150);
  }
  if(count == 499)
  {
    tone(buzz, 1000,150);
  }
  if(count == 399)
  {
    tone(buzz, 1000,150);
  }
  if(count == 299)
  {
    tone(buzz, 1000,150);
  }
  if(count == 199)
  {
    tone(buzz, 1000,150);
  }
  if(count == 100)
  {
    tone(buzz, 1000,300);
  }
    
  if(count == 0)
  {
    Timer1.detachInterrupt();
    Timer1.attachInterrupt(startcountup);
  }
  }
  
}

void startcountup()
{
if(count == 0)
      {
        stepper.moveDegrees (moveClockwise, 10);
      }
  if(paused == false)
    {
      count++;
    }
  if(LDRval <= 950)
  {
    Timer1.detachInterrupt();
  }
}
