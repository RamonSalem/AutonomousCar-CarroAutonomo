//Movimentos Básicos Motor 1 M1
void trazM1(){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
  }
void frenteM1(){
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
  }
void freioM1(){
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,HIGH);
  }
//Movimentos Básicos Motor 2 M2    
void frenteM2(){
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
  }  
void trazM2(){
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
  }  
void freioM2(){
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,HIGH);
  }
//Movimentos robo completo
//tested
void frenteRobot(){
  frenteM1();
  frenteM2();
}
//tested
void trazRobot(){
  trazM1();
  trazM2();
}
//motor1 frente motor2 traz direita
//tested
void direitaRobot(){
  frenteM1();
  trazM2();
  }
  //tested
void esquerdaRobot(){
  trazM1();
  frenteM2();
  }

  void freiaRobot(){
    freioM1();
    freioM2();
    }


    
