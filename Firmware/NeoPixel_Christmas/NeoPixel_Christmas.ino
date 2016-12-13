#include <Adafruit_NeoPixel.h>

#define PIN 7
Adafruit_NeoPixel strip = Adafruit_NeoPixel(15, PIN, NEO_GRB + NEO_KHZ800);

void Green();
void Red();
void iceBlue();
void Gold();
void Default();

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
      
     else if (*p == 'G')
       {
        Green();
       }
       
    else if (*p == 'R')
       {
        Red();
       }

    else if (*p == 'B')
       {
        iceBlue();
       }

    else if (*p == 'O')
       {
        Gold();
       }

    else 
    {
      Default();
    }
}

void Green()
{
       uint32_t green = 0x00FF00;
       int i = 0;
       int j = 0;
       while (j<255)
       {
       while(i<15)
          {
            strip.setPixelColor(i,green);
            strip.show();
            i++;
          }
          i = 0;
          j++;
        strip.show();
        delay(10);
        green=green -0x000100;
       }
       green = 0x00FF00;
}

void Red()
{
       uint32_t red = 0xFF0000;
       int i = 0;
       int j = 0;
       while (j<255)
       {
       while(i<15)
          {
            strip.setPixelColor(i,red);
            strip.show();
            i++;
          }
          i = 0;
          j++;
        strip.show();
        delay(10);
        red=red -0x010000;
       }
       red = 0x0FF0000;
}

void iceBlue()
{
       uint32_t blue = 0xA5F2F3;
       int i = 0;
       int j = 0;
       while (j<165)
       {
       while(i<15)
          {
            strip.setPixelColor(i,blue);
            strip.show();
            i++;
          }
          i = 0;
          j++;
        strip.show();
        delay(10);
        blue = blue -0x010101;
       }
       blue = 0xA5F2F3;
}

void Gold()
{
  uint32_t gold = 0xFFD700;

       int i = 0;
       int j = 0;
       while (j<200)
       {
       while(i<15)
          {
            strip.setPixelColor(i,gold);
            strip.show();
            i++;
          }
          i = 0;
          j++;
        strip.show();
        delay(10);
        gold = gold -0x010100;
       }
}

void Default()
{
       Green(); 
       iceBlue();
       Gold();
       Red();
}

