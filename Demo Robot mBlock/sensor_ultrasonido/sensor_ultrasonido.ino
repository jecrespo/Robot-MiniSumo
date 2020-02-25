#define MEDIA_VELOCIDAD_SONIDO 0.017175 // Mitad de la velocidad del sonido a 20 °C expresada en cm/µs
#define PIN_TRIGGER 7
#define PIN_ECHO 8
#define ESPERA_ENTRE_LECTURAS 1000 // tiempo entre lecturas consecutivas en milisegundos
#define TIMEOUT_PULSO 25000 // la espera máxima de es 30 ms o 30000 µs
 
float distancia;
unsigned long tiempo;
unsigned long cronometro;
unsigned long reloj=0;
 
void setup()
{
  Serial.begin(9600);
  pinMode(PIN_ECHO,INPUT);
  pinMode(PIN_TRIGGER,OUTPUT);
  digitalWrite(PIN_TRIGGER,LOW); // Para «limpiar» el pulso del pin trigger del módulo
  delayMicroseconds(2);
}
 
void loop()
{
  cronometro=millis()-reloj;
  if(cronometro>ESPERA_ENTRE_LECTURAS)
  {
    digitalWrite(PIN_TRIGGER,HIGH); // Un pulso a nivel alto…
    delayMicroseconds(10); // …durante 10 µs y
    digitalWrite(PIN_TRIGGER,LOW); // …volver al nivel bajo
    tiempo=pulseIn(PIN_ECHO,HIGH,TIMEOUT_PULSO); // Medir el tiempo que tarda en llegar un pulso
    distancia=MEDIA_VELOCIDAD_SONIDO*tiempo;
    Serial.print(distancia);
    Serial.print(",");
    Serial.println(tiempo);
    //Serial.println(" cm");
    reloj=millis();
  }
}
