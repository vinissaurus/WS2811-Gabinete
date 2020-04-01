int modoAnimacao=0;

void setup() {
  Serial.begin(115200);
  lerMemoria();
  initAnim();
}

void loop() {
  ouvirPorta();
  anime(modoAnimacao);//refatore esse nome please

  
  //delay(2);
}
