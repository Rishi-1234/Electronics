#include "EYES.h"

#include <SPI.h>
#include <TFT_eSPI.h> // Hardware-specific library
TFT_eSPI tft = TFT_eSPI();
int frames = 33;

void setup() {
  // put your setup code here, to run once:
tft.init();
  tft.setRotation(1);

  tft.setSwapBytes(true);
  tft.fillScreen(TFT_WHITE);
  
}

void loop() {
    tft.fillScreen(TFT_WHITE);
  // put your main code here, to run repeatedly:
for(int i=0;i<frames;i++)

{
  delay(100);
  tft.pushImage(60, -7,animation_width  , animation_height, EYES[i]);
  }

}
