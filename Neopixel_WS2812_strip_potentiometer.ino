// Lighting control of a small Neopixel strip (8 LEDs) with an ATtiny85 microcontroller and a 10k potentiometer (by Pléyades IT).

#include <Adafruit_NeoPixel.h>

#define PIN 4             // Select digital pin to control de Neopixel module
#define NUMPIXELS 8       // Number of pixels in the strip
#define BRIGHTNESS 12     // Set brightness (from 0 to 255)
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int PotValue = 0;
int NumeroPixels = 0;
int RedLED[] = {0, 0, 0, 128, 128, 128, 128, 128};
int GreenLED[] = {128, 128, 128, 128, 128, 128, 0, 0};

void setup()
{
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
  pinMode(A1, INPUT);
  // INICIO TEST
  delay(1000);
  for(int i=0; i<8; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 128, 0));   // Green
    pixels.show();
    delay(100);
  }
  pixels.clear();
  for(int i=0; i<8; i++)
  {
    pixels.setPixelColor(i, pixels.Color(128, 0, 0));   // Red
    pixels.show();
    delay(100);
  }
  pixels.clear();
  for(int i=0; i<8; i++)
  {
    pixels.setPixelColor(i, pixels.Color(128, 128, 0)); // Yellow (red and green light mix)
    pixels.show();
    delay(100);
  }
  delay(500);
  pixels.clear();
  pixels.show();
  delay(1000);
  // FIN TEST
}

void loop()
{
    PotValue = analogRead(A1); 
    NumeroPixels = map(PotValue, 0, 1023, 0, 9);
    if (PotValue <= 50)
    {
      pixels.clear();
      pixels.show();
    }
    if (PotValue > 50)
    {
      for(int i=0; i<NumeroPixels; i++)
      {
        pixels.setPixelColor(i, pixels.Color(RedLED[i], GreenLED[i], 0));  // Set colors (R, G, B)
        pixels.show();                                                     // Light the stritp
      }
    }      
    delay(10);
    pixels.clear();
    pixels.show();
}
