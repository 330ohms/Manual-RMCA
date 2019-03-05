#include <AFMotor.h>

AF_DCMotor motorR(2);//El motor derecho está conectado a M2 en el Motor Shield
AF_DCMotor motorL(1);//El motor izquierdo está conectado a M1 en el Motor Shield

void setup() {
  Serial.begin(9600);           
  Serial.println("!Prueba de motores!");

  // Encendemos los motores a una velocidad = 250/255
  motorR.setSpeed(250);
  motorL.setSpeed(250);
  
  motorR.run(RELEASE);//liberamos los motores
  motorL.run(RELEASE);
}

void loop() {
  //Hacemos avanzar ambos motores hacia adelante
  motorR.run(FORWARD);
  motorL.run(FORWARD);
}
