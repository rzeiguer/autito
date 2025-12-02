const int motoresDerAvanzar = 7;    // DERECHA AIA con BIB
const int motoresDerRetroceder = 6; // DERECHA AIB con BIA
const int motoresIzqAvanzar = 3;    // IZQUIERDA AIA con BIB
const int motoresIzqRetroceder = 4; // IZQUIERDA AIB con BIA


byte velocidad = 160;  // cambie este valor (100 a 255) para controlar velocidad

 
void setup() {

  pinMode(motoresDerAvanzar, OUTPUT);
  pinMode(motoresDerRetroceder, OUTPUT);
  pinMode(motoresIzqAvanzar, OUTPUT);
  pinMode(motoresIzqRetroceder, OUTPUT);

}
 
void loop() {
  adelante();
  delay(2000);
  atras();
  delay(2000);
  der();
  delay(2000);
  izq();
  delay(2000);
}

void adelante(){
  analogWrite(motoresDerAvanzar, velocidad);
  analogWrite(motoresDerRetroceder, 0);
  analogWrite(motoresIzqAvanzar, velocidad);
  analogWrite(motoresIzqRetroceder, 0);
}

void atras(){
  analogWrite(motoresDerAvanzar, 0);
  analogWrite(motoresDerRetroceder, velocidad);
  analogWrite(motoresIzqAvanzar, 0);
  analogWrite(motoresIzqRetroceder, velocidad);
}

void der(){
  analogWrite(motoresDerAvanzar, 0);
  analogWrite(motoresDerRetroceder, velocidad);
  analogWrite(motoresIzqAvanzar, velocidad);
  analogWrite(motoresIzqRetroceder, 0);
}

void izq(){
  analogWrite(motoresDerAvanzar, velocidad);
  analogWrite(motoresDerRetroceder, 0);
  analogWrite(motoresIzqAvanzar, 0);
  analogWrite(motoresIzqRetroceder, velocidad);
}
