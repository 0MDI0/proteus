#include <ModbusRtu.h>
#define ID   1

Modbus slave(ID, Serial, 0);

uint16_t au16data[10]; 

void setup() {

  Serial.begin(9600);

  pinMode(2,OUTPUT) ;
  pinMode(3,INPUT) ;
  pinMode(6,OUTPUT) ;

  analogWrite(6,0) ;
}

void loop() {
  slave.poll( au16data, 10 ); 
  
  bitWrite(au16data[0], 0, digitalRead(3));  
  digitalWrite(2, bitRead(au16data[1],0));   
  analogWrite(6, au16data[2]);   
  au16data[3] = analogRead(A0);
} 