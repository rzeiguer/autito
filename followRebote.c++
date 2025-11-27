const int Trigger1 = ...;
const int Echo1 = ...;
const int Trigger2 = ...;
const int Echo2 = ...;

long t, distance1, distance2;

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

    t = pulseIn(Echo1, HIGH);
    distance1 = t / 59;
    t = pulseIn(Echo2, HIGH);
    distance2 = t / 59;

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