
#include <Ultrasonic.h>
 
//Define os pinos para o trigger e echo
#define pino_trigger 4
#define pino_echo 5
#define pinoAzul 1
#define pinoVerde 2
#define pinoVermelho 3
#define pinoB 8


 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);
 
void setup()
{
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  pinMode(pinoVermelho, OUTPUT);
  pinMode(pinoVerde, OUTPUT);
  pinMode(pinoAzul, OUTPUT);
  pinMode(pinoB,OUTPUT);

}
 
void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  digitalWrite(pinoB,LOW);
  
  if (cmMsec < 20){
 //branco
   analogWrite(pinoVermelho, 500);
   analogWrite(pinoVerde, 500);
   analogWrite(pinoAzul, 500);
   digitalWrite(pinoB,HIGH);
   delay(35);
   digitalWrite(pinoB,LOW);
   delay(35);
  }else if ( cmMsec < 40){
    //Amarelo
   analogWrite(pinoVermelho, 300);
   analogWrite(pinoVerde, 0);
   analogWrite(pinoAzul, 0);
   digitalWrite(pinoB,HIGH);
   delay(250);
   digitalWrite(pinoB,LOW);
   delay(250);
  }else{
    //verde
   analogWrite(pinoVermelho,0);
   analogWrite(pinoVerde, 500);
   analogWrite(pinoAzul, 0);
   digitalWrite(pinoB,LOW);
   delay(500);
  }
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
 
}
