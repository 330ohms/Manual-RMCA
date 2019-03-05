#include <AFMotor.h>

AF_DCMotor motorR(2);//El motor derecho está conectado a M2 en el Motor Shield
AF_DCMotor motorL(1);//El motor izquierdo está conectado a M1 en el Motor Shield

//Velocidades calibradas para giro en linea recta
//Coloca aquí las velocidades calibradas de tu robot
int vm_derecho_F=100;
int vm_derecho_B=100;
int vm_izquierdo_F=132;
int vm_izquierdo_B=132;

void setup() {
  Serial.begin(9600);           
  Serial.println("!Prueba de motores!");
  // Encendemos los motores a una velocidad = 100/255
  motorR.setSpeed(100);
  motorL.setSpeed(100);
  motorR.run(RELEASE);//liberamos los motores
  motorL.run(RELEASE);
}

void loop() {
  //Hacemos avanzar ambos motores con distintas velocidades para observar un giro hacia la derecha
  //Antes de avanzar asignamos la velocidad de cada motor 
  motorR.setSpeed(vm_derecho_F / 2);//Menor velocidad de giro en la llanta derecha para girar hacia la derecha
  motorL.setSpeed(vm_izquierdo_F);
  motorR.run(FORWARD);
  motorL.run(FORWARD);
  delay(2000);//Mantenemos el avance por 2 segundos
  motorR.run(RELEASE);
  motorL.run(RELEASE);
  delay(500);//Mantenemos la robot en su posición por medio segundo
  
  //Hacemos avanzar ambos motores con distintas velocidades para observar un giro hacia la izquierda
  //Antes de avanzar asignamos la velocidad de cada motor 
  motorR.setSpeed(vm_derecho_F );
  motorL.setSpeed(vm_izquierdo_F /2 );//Menor velocidad de giro en la llanta izquierda para girar hacia la izquierda
  motorR.run(FORWARD);
  motorL.run(FORWARD);
  delay(2000);//Mantenemos el avance por 2 segundos
  motorR.run(RELEASE);
  motorL.run(RELEASE);
  delay(500);//Mantenemos al robot estático 0.5 segundos antes de repetir el ciclo
  
}
