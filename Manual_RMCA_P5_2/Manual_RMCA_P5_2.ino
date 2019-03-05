#define sensorDerechoPin 0//Pin analógico #0
#define sensorIzquierdoPin 1//Pin analógico #1  

#define trigPin 19
#define echoPin 18

#include <AFMotor.h>


int valSD=0;//Variable para guardar el valor leido en el sensor derecho
int valSI=0;//Variable para guardar el valor leido en el sensor izquierdo



AF_DCMotor motorR(2);//El motor derecho está conectado a M2 en el Motor Shield
AF_DCMotor motorL(1);//El motor izquierdo está conectado a M1 en el Motor Shield

//Velocidades calibradas para giro en linea recta
//Coloca aquí las velocidades calibradas de tu robot
int vm_derecho_F=100;//velocidad del motor derecho para avance
int vm_derecho_B=100;//velocidad del motor derecho para retroceso
int vm_izquierdo_F=132;//velocidad del motor izquierdo para avance
int vm_izquierdo_B=132;//velocidad del motor izquierdo para retroceso

void setup() {
  
  Serial.begin(9600);//Inicializamos la comunicación serial
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Encendemos los motores a una velocidad = 100/255
  motorR.setSpeed(100);
  motorL.setSpeed(100);
  motorR.run(RELEASE);//liberamos los motores
  motorL.run(RELEASE);
}

void loop() {
  long d=medirDistancia();//Obtenemos la distancia
  Serial.print("Distancia: ");
  Serial.println(d);//Imprimimos la distancia obtenida  
  valSD = analogRead(sensorDerechoPin);//Tomamos la lectura analógica del sensor derecho y guardamos el valor
  valSI = analogRead(sensorIzquierdoPin);//Tomamos la lectura analógica del sensor izquierdo y guardamos el valor
  
  Serial.print("Sensor derecho:  ");//imprimimos sin salto de línea 
  Serial.println(valSD);//Imprimimos con salto de línea
  Serial.print("Senor Izquierdo: ");//imprimimos sin salto de línea
  Serial.println(valSI);//imprimimos con salto de línea
  Serial.println();//Imprimimos un salto de línea adicional para teenr un formato fácil de leer en el monitor serie

  //delay(1000);descomenta para ver los valores en el monitor serie y comenta para dejar al robot funcionando//
  
  
  

  if(d>15){//Avanzamos mientras la distancia sea mayor a 15cm
   
    avanzar();
    
  }
  else{//Si la distancia es menor a 15cm 
   
      detenerse();
    
  }
}


//Creamos la fucnción detenerse() para tener menos líneas de código dentro de la estructura loop(){}
//La función es de tipo void porque no regresa ningún valor
void detenerse(){
    motorR.run(RELEASE);
    motorL.run(RELEASE);
}

//Creamos la fucnción avanzar() para tener menos líneas de código dentro de la estructura loop(){}
//La función es de tipo void porque no regresa ningún valor
void avanzar(){
  motorR.setSpeed(vm_derecho_F );
  motorL.setSpeed(vm_izquierdo_F);
  motorR.run(FORWARD);
  motorL.run(FORWARD);
}




//Creamos la fucnción medirDistancia() para tener menos líneas de código dentro de la estructura loop(){}
//La función es de tipo long porque regresa un valor de tipo long
long medirDistancia(){
  long duracion, distancia; //variables utilizadas para el cálculo y el resultado
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duracion = pulseIn(echoPin, HIGH);//Obtenemos el tiempo en microsegundos que le toma al pulso llegar a la superfice más cercana y regresar
  //Para el cálculo de la distancia tomamos la mitad del tiempo para considerar solo la ida del pulso
  //Y miltiplicamos por el factor 1/29.1 correspondiente a la velocidad del sonido en [centimetros/microsegundos]
  distancia = (duracion/2) / 29.1;
  return distancia;//Regresamos el valor calculado
}

