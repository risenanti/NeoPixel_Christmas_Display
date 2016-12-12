#include <Adafruit_NeoPixel.h>

#define PIN 7
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

void runningDefault();
void setGreen();
void setRed();
void setBlue();

char *p;

void setup() {

  p = new char;
  strip.begin();
  strip.setBrightness(85);
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(115200);
}

void loop() 
{
  if (Serial.available())
    {    //checks for serial information
    *p = Serial.read(); //pointer to val
    }

  if (*p =='G')
  {
    setGreen();
  }
  else if (*p == 'R')
  {
    setRed();
  }
  else if (*p == 'B')
  {
    setBlue();
  }
  else
  {
    runningDefault();
  }
}

void setGreen()
{
      int i = 0;
    while(i<60)
      {
        strip.setPixelColor(i,0x00FF00);
        strip.show();
        i++;
        delay(20);
      }
}

void setRed()
{
    int i = 0;
    while(i<60)
      {
        strip.setPixelColor(i,0xFF0000);
        strip.show();
        i++;
        delay(20);
      }
}

void setBlue()
{

    int i = 0;
    while(i<60)
      {
        strip.setPixelColor(i,0x0000FF);
        strip.show();
        i++;
        delay(20);
      }
}

void runningDefault()
{
    int i = 0;
    while(i<60)
      {
        strip.setPixelColor((i-1),0x000000);
        strip.show();
        strip.setPixelColor(i,0xFF0000);
        strip.show();
        i++;
        delay(20);
      }

      i=0;
      while(i<60)
      {
        strip.setPixelColor((i-1),0x000000);
        strip.show();
        strip.setPixelColor(i,0x00FF00);
        strip.show();
        i++;
        delay(20);
      }

      i=0;
      while(i<60)
      {
        strip.setPixelColor((i-1),0x000000);
        strip.show();
        strip.setPixelColor(i,0x0000FF);
        strip.show();
        i++;
        delay(20);
      }
      i=0;
      while(i<60)
      {
        strip.setPixelColor(i,0x50AA50);
        strip.show();
        i++;
        delay(20);
      }


     i=0;
      while(i<60)
      {
        strip.setPixelColor(i,0x000000);
        strip.show();
        i++;
        delay(20);
      }


      i=0;
      while(i<60)
      {
        strip.setPixelColor((i-1),000000);
        strip.setPixelColor(i,0xFF0000);

        strip.setPixelColor(i+1,0x00FF00);
        strip.show();
        i++;
        delay(20);
      }
}


