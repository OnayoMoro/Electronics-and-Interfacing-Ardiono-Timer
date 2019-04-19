#include <Adafruit_NeoPixel.h> 
#define PIN 8
#include <TimerOne.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(84, PIN, NEO_GRB + NEO_KHZ800); 

int r =0;
int g = 0;
int b = 100;
int segment;

unsigned char ten;
unsigned char seconds;
unsigned char Lmiliseconds;
unsigned char mili;

unsigned long count = 6000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Timer1.initialize(10000);
  Timer1.attachInterrupt(startcount);
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
  // put your main code here, to run repeatedly:
  screen();
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

void startcount()
{
  ten = (count/1000);
  seconds = ((count%1000)/100);
  mili =  ((count%100)/10);
  Lmiliseconds = (count%10);
  Serial.println(count);

  count--;
  if(count>1000000)
   {
    //Timer1.detachInterrupt();
    count=100000;
   }
}
