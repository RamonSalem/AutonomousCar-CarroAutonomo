void modoManual(){
  freiaRobot();
  bool getOut = false;
  while(!getOut){
      if(irrecv.decode(&leitura)){
        if (leitura.value == 0xFD8877){ // esse codigo é referente a seta para cima, ele faz o carro andar para frente
          Serial.println("frente");
          frenteRobot();
      }else if(leitura.value == 0xFD28D7){ // esse if é referente a seta para a esquerda, ele faz o carro girar para esquerda
        Serial.println("esquerda");
        esquerdaRobot();
      }else if(leitura.value == 0xFD9867){ // esse if é referente a seta para baixo, ele faz o carro da ré
        Serial.println("tras");
        trasRobot();
      }else if(leitura.value == 0xFD6897){ // esse if é referente a seta para direita, ele faz o carro girar para direita
        Serial.println("direita");
        direitaRobot();
      }else if(leitura.value == 0xFDA857){
        Serial.println("parar");
        freiaRobot();
       }else  if(leitura.value == 0xFD00FF){
          getOut = true;
        }     
  irrecv.resume(); // Faz com que o receptor faça uma nova leitura
        }
      }  
    }
  
