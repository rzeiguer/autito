const int motoresDerAvanzar = 7;
const int motoresDerRetroceder = 6;
const int motoresIzqAvanzar = 3;
const int motoresIzqRetroceder = 4;

const int TriggerDer = 12;
const int EchoDer = 13;
const int TriggerIzq = 10; 
const int EchoIzq = 11;

#define DIST 10
byte velocidad = 180;

void setup() {
  pinMode(motoresDerAvanzar, OUTPUT);
  pinMode(motoresDerRetroceder, OUTPUT);
  pinMode(motoresIzqAvanzar, OUTPUT);
  pinMode(motoresIzqRetroceder, OUTPUT);

  pinMode(TriggerDer, OUTPUT);
  pinMode(TriggerIzq, OUTPUT);
  pinMode(EchoIzq, INPUT);
  pinMode(EchoDer, INPUT);

  digitalWrite(TriggerDer, LOW);
  digitalWrite(TriggerIzq, LOW);
}

void loop() {

    long distDer, timeDer;
    long distIzq, timeIzq;

    UltraDerecha(distDer, timeDer);
    UltraIzquierda(distIzq, timeIzq);

    // comportamiento
    if(distDer <= DIST && distIzq > DIST){
        Izq();
        return;
    }
    if(distIzq <= DIST && distDer > DIST){
        Der();
        return;
    }
    if(distIzq <= DIST && distDer <= DIST){
        atras();
        return;
    }

    adelante();
}

// ---------------- FUNCIONES -------------------

void UltraDerecha(long &distancia, long &tiempo){
    digitalWrite(TriggerDer, HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerDer, LOW);

    tiempo = pulseIn(EchoDer, HIGH);
    distancia = tiempo / 59;
}

void UltraIzquierda(long &distancia, long &tiempo){
    digitalWrite(TriggerIzq, HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerIzq, LOW);

    tiempo = pulseIn(EchoIzq, HIGH);
    distancia = tiempo / 59;
}

void atras(){
  analogWrite(motoresDerAvanzar, velocidad);
  analogWrite(motoresDerRetroceder, 0);
  analogWrite(motoresIzqAvanzar, velocidad);
  analogWrite(motoresIzqRetroceder, 0);
}

void adelante(){
  analogWrite(motoresDerAvanzar, 0);
  analogWrite(motoresDerRetroceder, velocidad);
  analogWrite(motoresIzqAvanzar, 0);
  analogWrite(motoresIzqRetroceder, velocidad);
}

void Izq(){
  analogWrite(motoresDerAvanzar, 0);
  analogWrite(motoresDerRetroceder, velocidad);
  analogWrite(motoresIzqAvanzar, velocidad);
  analogWrite(motoresIzqRetroceder, 0);
}

void Der(){
  analogWrite(motoresDerAvanzar, velocidad);
  analogWrite(motoresDerRetroceder, 0);
  analogWrite(motoresIzqAvanzar, 0);
  analogWrite(motoresIzqRetroceder, velocidad);
}