#define sensorDerechoPin 0//Pin analógico #0
#define sensorIzquierdoPin 1//Pin analógico #1  

int valSD=0;//Variable para guardar el valor leido en el sensor derecho
int valSI=0;//Variable para guardar el valor leido en el sensor izquierdo

void setup() {
  
  Serial.begin(9600);//Inicializamos la comunicación serial
  
}

void loop() {
  
  valSD = analogRead(sensorDerechoPin);//Tomamos la lectura analógica del sensor derecho y guardamos el valor
  valSI = analogRead(sensorIzquierdoPin);//Tomamos la lectura analógica del sensor izquierdo y guardamos el valor
  Serial.print("Sensor derecho:  ");//Imprimimos sin salto de línea 
  Serial.println(valSD);//Imprimimos con salto de línea
  Serial.print("Senor Izquierdo: ");//Imprimimos sin salto de línea
  Serial.println(valSI);//Imprimimos con salto de línea
  Serial.println();//Imprimimos un salto de línea adicional para teenr un formato fácil de leer en el monitor serie

  delay(1000);//Delay para realizar la letura aproximadamete cada segundo
  
}
