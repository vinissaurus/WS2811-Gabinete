#include <FastLED.h>

#define DATA_PIN 6
#define CLOCK_PIN 13
#define NUM_LEDS 119

#define COOLING  55
#define SPARKING 120

#define PI 3.1415926535897932384626433832795
/*
  0-Cyclon
  1-Spinner
  2-Fogo
  3-Cyberpunk
  4-Pulsação
  5-Natal
  6-Estático

*/




int clk = 0;
int aux1 = 0;
int aux2 = 0;
int aux3 = 0;
int aux4 = 0;
int aux5 = 0;
int anim[NUM_LEDS];
double aux6=0;
float aux7=0;


static byte heat[NUM_LEDS];
uint8_t gHue = 0;

CRGB leds[NUM_LEDS];
CRGBPalette16 gPal;
CRGB color;


void initAnim() {
  LEDS.addLeds<WS2811, DATA_PIN, GRB>(leds, NUM_LEDS);
  LEDS.setBrightness(50);
  gPal = CRGBPalette16( CRGB::Black, CRGB::Blue, CRGB::Aqua,  CRGB::White);
  //Serial.begin(115200);
}

void fadeall() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].nscale8(250);
  }
}

void anime(int mode) {
  //###################################################[   0   ]########################################################
  if (mode == 0 && clk == 10) { //Ciclão?
    if (aux1 < NUM_LEDS) {
      leds[aux1] = CHSV(aux2++, 255, 255);
      // Show the leds

      // now that we've shown the leds, reset the i'th led to black
      // leds[i] = CRGB::Black;

    }
    if (aux1 > NUM_LEDS) {

      leds[2 * NUM_LEDS - aux1] = CHSV(aux2++, 255, 255);
      // now that we've shown the leds, reset the i'th led to black
      // leds[i] = CRGB::Black;

      if (aux1 > 2 * NUM_LEDS) {
        aux1 = 0;
        aux2 = 0;
      }
    }
    fadeall();
    aux1++;
    clk = 0;
  }
  //###################################################[   1   ]########################################################
  if (mode == 1 && clk == 10) { //Spinner
    //girar o pixel na janela
    if (aux1 > 71) {
      aux1 = 0;
    }
    leds[aux1] = CHSV(aux5, 255, 255);
    aux1++;

    fadeall();
    //girar o pixel na barra superior
    if (aux2 < 72) {
      aux2 = 72;
    }
    if (aux2 > 76) {
      aux2 = 72;
    }
    leds[aux2] = CHSV(aux5, 255, 255);
    aux2++;

    fadeall();
    //girar o pixel na ventoinha superior
    if (aux3 < 77) {
      aux3 = 77;
    }
    if (aux3 > 97) {
      aux3 = 77;
    }
    leds[aux3] = CHSV(aux5, 255, 255);
    aux3++;

    fadeall();
    //girar o pixel na ventoinha inferior
    if (aux4 < 98) {
      aux4 = 98;
    }
    if (aux4 > 118) {
      aux4 = 98;
    }
    leds[aux4] = CHSV(aux5, 255, 255);
    aux4++;

    aux5++;
    if (aux5 > 255) {
      aux5 = 0;
    }
    fadeall();
    clk = 0;
  }

  if (mode == 2) {//Fogoooooooooooooooooooooooooooooooooooooooooo
    random16_add_entropy( random());
    // Array of temperature readings at each simulation cell


    // Step 1.  Cool down every cell a little
    for ( int i = 0; i < NUM_LEDS; i++) {
      heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / NUM_LEDS) + 2));
    }

    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for ( int k = NUM_LEDS - 1; k >= 2; k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    }

    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if ( random8() < SPARKING ) {
      //int y = random8(7);
      heat[random8(7)] = qadd8( heat[random8(7)], random8(160, 255) );
    }

    // Step 4.  Map from heat cells to LED colors
    for ( int j = 0; j < NUM_LEDS; j++) {
      // Scale the heat value from 0-255 down to 0-240
      // for best results with color palettes.
      //byte colorindex = scale8( heat[j], 240);
      color = ColorFromPalette( gPal, scale8( heat[j], 240));
      leds[j] = color;
    }


    fadeall();
    //clk = 0;
  }

  if (mode == 3 ) { //Cyberpunk

    fill_gradient(leds, 0, CHSV(190, 255, 120), NUM_LEDS, CHSV(240, 255, 120), FORWARD_HUES);
        if ( random8() < 10) {
      leds[ random16(NUM_LEDS) ] += CRGB::White;
    }

//    if (clk == 20) {
//
//    clk=0;
//    }
  }


  if (mode == 4) {//Pulsação
    fadeToBlackBy(leds, NUM_LEDS, 10);
    leds[random16(NUM_LEDS)] += CHSV( gHue + random8(64), 200, 255);

    gHue++;
    //clk = 0;

  }

  if (mode == 5 && clk == 100) { //RGBW simples

    if (aux2 > 3) {
      aux2 = 0;
    }
    if (aux2 == 0) {
      anim[0] = 0;
      anim[1] = 1;
      anim[2] = 2;
      anim[3] = 3;
    }
    if (aux2 == 1) {
      anim[0] = 1;
      anim[1] = 2;
      anim[2] = 3;
      anim[3] = 0;
    }
    if (aux2 == 2) {
      anim[0] = 2;
      anim[1] = 3;
      anim[2] = 0;
      anim[3] = 1;
    }
    if (aux2 == 3) {
      anim[0] = 3;
      anim[1] = 0;
      anim[2] = 1;
      anim[3] = 2;
    }

    aux2++;
    for (int i = 0; i < NUM_LEDS; i++) {
      if (aux1 > 3 || i == NUM_LEDS) {
        aux1 = 0;
      }

      if (aux1  == anim[0]) {//Red
        leds[i].setRGB(255, 0, 0);
      }
      if (aux1  == anim[1]) { //Green
        leds[i].setRGB(0, 255, 0);
      }
      if (aux1  == anim[2]) { //Blue
        leds[i].setRGB(0, 0, 255);
      }
      if (aux1  == anim[3] ) { //Walter White
        leds[i].setRGB(255, 255, 255);
      }
      aux1++;
    }

    clk = 0;


  }

  if ( mode == 6) {

    fill_gradient(leds, 0, CHSV(190, 255, 120), NUM_LEDS, CHSV(240, 255, 120), FORWARD_HUES);

  }


  //###########################################################################################################
  //LINHA DE FUNDO DO MÉTODO
  FastLED.show();
  clk++;//dá um passo no clock
}
