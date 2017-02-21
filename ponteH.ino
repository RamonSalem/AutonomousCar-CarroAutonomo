#include <Servo.h>

/*Pinagem do arduino*/
//Servo
Servo servo;

//Sensor
const int trigPin = 6;
const int echoPin = 8;

long duracao;
int distancia;
 
//motor 1
const int IN1 = 2 ;//amarelo
const int IN2 = 3 ;//branco
 
//motor 2
const int IN3 = 4 ;//cinza
const int IN4 = 5 ;//roxo
 
//Inicializa Pinos
void setup(){
 //Configs Servo
 servo.attach(9);

 //configs Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
 //Configs motores
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);

 Serial.begin(9600);
}
 
void loop(){
//Testes motor
//frenteM1(); //ok
//freioM1(); //ok
//trazM1();  //ok
//frenteRobot(); //ok
//trazRobot(); //ok
//direitaRobot(); //ok
//esquerdaRobot(); //ok

//Testes servo

//moverServoCentro();
//delay(2000);
//moverServo180();
//delay(2000);
//moverServo0();
//delay(2000);
//moverServoCentro();
//Testes sensor
atualizarDistancia();
//Serial.print("Distance: ");
//Serial.println(distancia);

//esquerdaRobot();
//delay(2000);
//direitaRobot();
//delay(2000);

if(distancia <= 20){
  freiaRobot();
  int distancia180 = 0;
  int distancia0 = 0;
  
  moverServo180();
  delay(2000);
  atualizarDistancia();
  distancia180 = distancia;
  Serial.print("Distance 180: ");
  Serial.println(distancia);
  
  delay(5000);
  
  moverServo0();
  delay(2000);
  
  atualizarDistancia();
  distancia0 = distancia;
  Serial.print("Distance 0: ");
  Serial.println(distancia);
  
  delay(4000);
  moverServoCentro();

  if(distancia180 > 20 && distancia180 > distancia0){
    Serial.print("Mover para direcao 180: ");
    esquerdaRobot();
    delay(200);
    }
  else if(distancia0 > 20 && distancia0 > distancia180){
    Serial.print("Mover para direcao 0");
    direitaRobot();
    delay(200);
    }
  else{
    Serial.print("Dar a re");
    trazRobot();
    delay(200);
    }    
  }
  else{
    frenteRobot();
    }
    



 
}
