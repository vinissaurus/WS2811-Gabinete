#include <EEPROM.h>

void lerMemoria(){
  modoAnimacao=EEPROM.read(1);
  }

  void escreverMemoria(int posicao,int valor){
    EEPROM.write(posicao,valor);
    }
