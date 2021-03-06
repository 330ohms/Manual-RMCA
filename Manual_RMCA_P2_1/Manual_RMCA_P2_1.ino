#include <AFMotor.h>

AF_DCMotor motorR(2);//El motor derecho está conectado a M2 en el Motor Shield
AF_DCMotor motorL(1);//El motor izquierdo está conectado a M1 en el Motor Shield

//Inicio de la estructura setup(){}
void setup() {
  Serial.begin(9600);           
  Serial.println("!Prueba de motores!");
  // Encendemos los motores a una velocidad = 100/255
  motorR.setSpeed(100);
  motorL.setSpeed(100);
  motorR.run(RELEASE);//liberamos los motores
  motorL.run(RELEASE);
}

//inicio de la estructura loop(){}
void loop() {
  //Hacemos avanzar ambos motores hacia adelante
  //Antes de avanzar asignamos la velocidad de cada motor 
  motorR.setSpeed(100);//Modifica aquí las velocidades para hacer que tu robot avancé en línea recta
  motorL.setSpeed(100);
  motorR.run(FORWARD);
  motorL.run(FORWARD);
  delay(2000);//Mantenemos el avance por 2 segundos
  motorR.run(RELEASE);
  motorL.run(RELEASE);
  delay(100);//Mantenemos la robot en su posición por medio segundo
  
  
}
