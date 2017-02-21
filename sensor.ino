void atualizarDistancia(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duracao= pulseIn(echoPin, HIGH);
    distancia= duracao*(0.034/2);
  }
  
