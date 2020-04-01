int opcao=0;
int parametro1=0;

void ouvirPorta() {
  if (Serial.available()) {
    String dados = Serial.readString();
    //Serial.println("Got something!");
    Serial.println(dados);
    /*00-Ligar/desligar
      01-Definir animação 01:XX
      02-Definir parâmetros
      03-Relatório
      "Ping"-Responder "PONG"
    */
    if (dados.indexOf("Ping")>0){
    Serial.println("PONG!");
    }
    if(dados.indexOf(':')!=-1){
    opcao=getValue(dados, ':', 0).toInt();
    //###########################################DEFINIR ANIMAÇÃO
     if(opcao==1){
      int anims=getValue(dados, ':', 1).toInt();
      escreverMemoria(1,anims);
      modoAnimacao=anims;
      Serial.println(anims);
     }
    Serial.flush();
    }
  }
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
