
#define pinLED1 0
#define pinLED2 1
#define pinLED3 2

void setup() {
pinMode(pinLED1, OUTPUT);
pinMode(pinLED2, OUTPUT);
pinMode(pinLED3, OUTPUT);

}

void loop() {
digitalWrite(pinLED1, HIGH);
digitalWrite(pinLED2, HIGH);
digitalWrite(pinLED3, HIGH);
delay(20);
digitalWrite(pinLED1, LOW);
digitalWrite(pinLED2, LOW);
digitalWrite(pinLED3, LOW);
delay(20);  
}
