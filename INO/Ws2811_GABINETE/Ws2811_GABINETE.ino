#include <FastLED.h>

#define NUM_LEDS 119
#define DATA_PIN 6
#define CLOCK_PIN 13

int modoAnimacao = 0;
//int ctm = 0; //cycle through modes
int clk = 0;
int fps = 0;
int aux1 = 0;
int aux2 = 0;
int aux3 = 0;
int aux4 = 0;

CRGB leds[NUM_LEDS];
void setup() {
LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
LEDS.setBrightness(255);
}

void loop() {
  //CÍRCULOS
//circulo na janela
for(int i=0;i<71;i++){//para funcionamento conciliado com outras funções, o for externo deve ser modificado
  for(int j=0;j<71;j++){
    if(i==j){
      leds[j].setHSV(255,255,255);
      }
        if(i!=j){
      leds[j].setHSV(0,0,0);
      }  
    }
    FastLED.show();
  }
  
  delay(100);
}
