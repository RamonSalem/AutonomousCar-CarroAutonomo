#include <Servo.h>
#include <IRremote.h>

/*Pinagem do arduino*/
//Servo
Servo servo;

//Sensor
const int trigPin = 6;
const int echoPin = 8;

long duracao;
int distancia;

//Controle IR
int pinReceiver = 13;
float valorIr;

IRrecv irrecv(pinReceiver);
decode_results leitura;

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
 
 //Configs Controle IR
 irrecv.enableIRIn(); // inicializa o receptor do controle;
 
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


//Serial.print("Distance: ");
//Serial.println(distancia);

//esquerdaRobot();
//delay(2000);
//direitaRobot();
//delay(2000);

//Modo 1: Automático(autônomo)
//Modo 2: Manual

if(irrecv.decode(&leitura)){
  //Modo automático
  bool goManual = false;
  while(!goManual){
    atualizarDistancia();
    if(irrecv.decode(&leitura)){
      if(leitura.value == 0xFD807F){
      goManual = true;
      }
      irrecv.resume(); 
      }
    Serial.println("automatico");
    //irrecv.resume();
    //distancia = 25;
    Serial.println(distancia );
     
    if(distancia <= 25){
      verificar();    
      }
    else{
      frenteRobot();
        }    
    }
  //Modo manual  
  if(leitura.value == 0xFD807F){
    Serial.println("manual");
    //irrecv.resume();
    modoManual();  
    }
  irrecv.resume();
  }

 
}

/*
else if(distancia <= 25){
  verificar();    
  }
else{
  frenteRobot();
    }
    */

/*Codigo reuniao
 if(irrecv.decode(&leitura)){
  //Modo automático
  if(leitura.value == 0xFD00FF){
    Serial.println("automatico");
    atualizarDistancia();
    //irrecv.resume();
    //distancia = 25;
    Serial.println(distancia );
    if(distancia <= 25){
      verificar();    
      }
    else{
      frenteRobot();
        }
    }
  //Modo manual  
  else if(leitura.value == 0xFD807F){
    Serial.println("manual");
    //irrecv.resume();
    modoManual();  
    }
  irrecv.resume();
  }
*/



    
