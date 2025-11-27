const int Trigger1 = ...;
const int Echo1 = ...;
const int Trigger2 = ...;
const int Echo2 = ...;

long t1, t2, distance1, distance2;

void setup(){

    iniciarMotores();
    iniciarComponentes(); // Incluyendo los dos sensores

}

void loop(){

    digitalWrite(Trigger1, HIGH);
    digitalWrite(Trigger2, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trigger1, LOW);
    digitalWrite(Trigger2, LOW);

    t1 = pulseIn(Echo1, HIGH);
    distance1 = t1 / 59;
    t2 = pulseIn(Echo2, HIGH);
    distance2 = t2 / 59;

    if (distance1 < 50){
        avanceIzq();
        delay(500); // Avanza por medio segundo
    }
    else if ( distance2 < 50){
        avanceDer();
        delay(500); // Avanza por medio segundo
    }
    else {
        avance();
        delay(500);
    }
    
}