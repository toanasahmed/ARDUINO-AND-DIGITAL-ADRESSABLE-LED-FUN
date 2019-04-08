/*
   Developed by Anas Ahmed, Manager at Hackerspace Karachi.
   Email: anas.ahm5@gmail.com
   Whatsapp: (+92)-332-3265201
   Website: www.hackerspacekarachi.com



*/

#include <Adafruit_NeoPixel.h>

#define PIN 13 
#define BUTTON 2
#define manualLed 4
#define autoLed 3
#define potpin A0
#define ldrpin A4

int state = LOW;
int a = 0;
int NUM_LEDS = 287;
int b = 5;
int potvalue;
int ldrvalue;
int brightness = 5;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), switchOn, RISING);


  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  Serial.begin(9600);
}

void loop() {

  b = 5;
  pot();
  ldr();
  brightness = potvalue + ldrvalue;
  strip.setBrightness(brightness);


  if ( a > 1 && a < 7 ) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }

  else if (a == 1) {
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
  }

  else if (a == 0) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    strip.show(); // Initialize all pixels to 'off'

  }

  Serial.print("Value of a in loop = ");
  Serial.println(a);

  switch (a) {
    case 1: manualmode();
      delay(500);
      break;
    case 2: delay(500);
      colorWipe(strip.Color(255, 0, 0), 50);
      colorWipe(strip.Color(0, 255, 0), 50); // Green
      colorWipe(strip.Color(0, 0, 255), 50); // Blue
      break;
    case 3: delay(1000);
      rainbow(20);
      break;
    case 4: //delay(500);
      theaterChase(strip.Color(127, 127, 127), 50); // White
      theaterChase(strip.Color(127, 0, 0), 50);
      theaterChase(strip.Color(0, 0, 127), 50); // Blue
      //delay(500);
      break;
    case 5: rainbowCycle(20);
    break;
    case 6:  delay(500);
      //      strip.begin();
      strip.show(); // Initialize all pixels to 'off'
      theaterChaseRainbow(50);
      break;
  }


}



void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    if (a != 2) {
      break;
    }
    //delay(10);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  
    for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
      if (a ==  6) {
        break;
      }
      for (i = 0; i < strip.numPixels(); i++) {
        if (a ==  6) {
          break;
        }
        strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
      }
      strip.show();
      delay(wait);

    }
  }

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {

        strip.setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {

        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) {// cycle all 256 colors in the wheel
    if (a != 6) {
      break;
    }
    for (int q = 0; q < 3; q++) {
      if (a != 6) {
        break;
      } for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        if (a != 6) {
          break;
        } strip.setPixelColor(i + q, Wheel( (i + j) % 255)); //turn every third pixel on
      } if (a != 6) {
        break;
      }
      strip.show();
      if (a != 6) {
        break;
      }
      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        if (a != 6) {
          break;
        } strip.setPixelColor(i + q, 0);     //turn every third pixel off
      }
    }
  }
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);

}





void manualmode() {
  for (int i = 0; i <= 28; i++) {
    strip.setPixelColor(i, 0XFFA500);
  }
  for (int i = 29; i <= 57; i++) {
    strip.setPixelColor(i, 0X000000);

  }
  for (int i = 58; i <= 86; i++) {
    strip.setPixelColor(i, 0XFF69B4);
  }
  for (int i = 87; i <= 115; i++) {
    strip.setPixelColor(i, 0X663399);
  }
  for (int i = 116; i <= 144; i++) {
    strip.setPixelColor(i, 0X00FF7F);
  }
  for (int i = 145; i <= 173; i++) {
    strip.setPixelColor(i, 0);
  }
  for (int i = 174; i <= 202; i++) {
    strip.setPixelColor(i, 0XD2B48C);
  }
  for (int i = 203; i <= 231; i++) {
    strip.setPixelColor(i, 200);
  }
  for (int i = 232; i <= 260; i++) {
    strip.setPixelColor(i, 0XFFFFF0);
  }
  for (int i = 261; i <= 289; i++) {
    strip.setPixelColor(i, 0XDCDCDC);
  }

  strip.show();

}


void ldr()
{ ldrvalue = analogRead(ldrpin);
  //ldrvalue = constrain(ldrvalue, 400, 500);
  ldrvalue = map(ldrvalue,  0, 750, 5, 225); // change these value accordingly
  Serial.print("ldr value ="); //prints the values coming from the sensor on the screen
  Serial.println(ldrvalue); //prints the values coming from the sensor on the screen
  delay(500);

}


void pot()
{ potvalue = analogRead(potpin);
  potvalue = map(potvalue, 0, 900, 0, 10);
  Serial.print("pot value ="); //prints the values coming from the sensor on the screen
  Serial.println(potvalue); //prints the values coming from the sensor on the screen

}





void switchOn() {
  b--;

  if (b == 4)
  { a++;
    if (a > 6) {
      a = 0;
    }
    check();
  }

  digitalWrite(4, LOW);
  digitalWrite(3, LOW);

}




void check() {

  Serial.print("Value of a in function = ");
  Serial.println(a);



}
