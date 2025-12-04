#define pinLed 8      // cambié el pin para evitar usar el TX
const int Trigger = 3;
const int Echo = 4;

void setup() {
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(pinLed, OUTPUT);
  digitalWrite(Trigger, LOW);
}

void loop() {
  long t;
  long d;

  // Envío de pulso
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);

  // Lectura
  t = pulseIn(Echo, HIGH);
  d = t / 59;

  // Condición
  if (d < 20 && d > 0) {
    digitalWrite(pinLed, HIGH);
  } else {
    digitalWrite(pinLed, LOW);
  }

  delay(50); // pequeño delay para estabilidad
}