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
  //Hacemos girar ambos motores, uno hacia atrás y el otro hacia adelante para observar un giro del robot sobre su propio eje
  //Antes asignamos la velocidad de cada motor 
  motorR.setSpeed(vm_derecho_B);
  motorL.setSpeed(vm_izquierdo_F);
  motorR.run(BACKWARD);//Hacemos girar el motor de la derecha hacia atras para conseguir un giro horario
  motorL.run(FORWARD);
  delay(2000);//Mantenemos el avance por 2 segundos
  motorR.run(RELEASE);
  motorL.run(RELEASE);
  delay(500);//Mantenemos la robot en su posición por medio segundo
    
  //Hacemos girar ambos motores, uno hacia atrás y el otro hacia adelante para observar un giro del robot sobre su propio eje
  //Antes asignamos la velocidad de cada motor 
  motorR.setSpeed(vm_derecho_F );
  motorL.setSpeed(vm_izquierdo_B );
  motorR.run(FORWARD);
  motorL.run(BACKWARD);//Hacemos girar el motor de la izquierda hacia atrás para conseguir un giro antihirario
  delay(2000);//Mantenemos el avance por 2 segundos
  motorR.run(RELEASE);
  motorL.run(RELEASE);
  delay(500);//Mantenemos al robot estático 0.5 segundos antes de repetir el ciclo
  
}
