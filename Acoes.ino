void verificar(){
  freiaRobot();
  int distancia180 = 0;
  int distancia0 = 0;
  
  moverServo180();
  delay(1000);
  atualizarDistancia();
  distancia180 = distancia;
  Serial.print("Distance 180: ");
  Serial.println(distancia);
  
  delay(1000);
  
  moverServo0();
  delay(1000);
  
  atualizarDistancia();
  distancia0 = distancia;
  Serial.print("Distance 0: ");
  Serial.println(distancia);
  
  delay(3000);
  moverServoCentro();

  if(distancia180 > 25 && distancia180 > distancia0){
    Serial.print("Mover para direcao 180: ");
    direitaRobot();
    delay(300);
    }
  else if(distancia0 > 25 && distancia0 > distancia180){
    Serial.print("Mover para direcao 0");
    esquerdaRobot();
    delay(300);
    }
  else{
    Serial.print("Dar a re");
    trasRobot();
    delay(500);
    verificar();
    }    
  }
