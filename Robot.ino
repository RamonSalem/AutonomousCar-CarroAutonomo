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
//trasM1();  //ok
//frenteRobot(); //ok
//trasRobot(); //ok
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

if(distancia <= 25){
  verificar();    
  }
else{
  frenteRobot();
    }
 
}
