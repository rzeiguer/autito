const int motoresDerAvanzar = 7;    // DERECHA AIA con BIB
const int motoresDerRetroceder = 6; // DERECHA AIB con BIA
const int motoresIzqAvanzar = 3;    // IZQUIERDA AIA con BIB
const int motoresIzqRetroceder = 4; // IZQUIERDA AIB con BIA
const int TriggerDer = 12;
const int EchoDer = 13;
const int TriggerIzq = 10; 
const int EchoIzq = 11;


#define DIST 20
byte velocidad = 180;  // cambie este valor (100 a 255) para controlar velocidad

 
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
//lectura de los sensores ultrasonicos
    long *timeDer;
    long *distDer;
    long *timeIzq;
    long *distIzq;

    UltraDerecha(&distDer, &timeDer);
    UltraIzquierda(&distIzq, &timeIzq);
    
//-------------------------------------------------------------------
//comportamiento del autito
    if(*distDer <= DIST && *distIzq >DIST){
        Izq();
    }
    if(*distIzq <= DIST && *distDer > DIST){
        Der();
    }
    if(*distIzq <= DIST && *distDer <= DIST){
        atras();
    }
    
    adelante();

    //en teoria si no se le pone delay tendria que funcionar como un while
}

//funcion para lectura del ultrasonico derecho
void UltraDerecha(long* distancia, long* tiempo){
    digitalWrite(TriggerDer, HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerDer, LOW);

    *distancia = pulseIn(Echo, HIGH);
    *distancia = *tiempo / 59;
}

//funcion para lectura del ultrasonico izquierdo
void UltraIzquierda(long* distancia, long* tiempo){
    digitalWrite(TriggerIzq, HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerIzq, LOW);

    *distancia = pulseIn(Echo, HIGH);
    *distancia = *tiempo / 59;
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
