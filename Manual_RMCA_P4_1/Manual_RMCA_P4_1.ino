#define trigPin 19
#define echoPin 18


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  
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
  Serial.println(distancia);//Imprimimos la distancia medida
  delay(1000);//Tomamos la medida cada segundo aproximadamente
}

