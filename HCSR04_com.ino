/*
 Name:		HCSR04_com.ino
 Created:	12/04/2021 09:57:47
 Author:	pc_technique_swarmz
*/

const int trigPin = 13;
const int echoPin11 = 2;
const int echoPin12 = 3;

 volatile int a = 0;
 volatile int b = 0;

 volatile int a1 = 0;
 volatile int b1 = 0;
 
 int delta=0 ;
 int delta1 = 0;

 double speedOfSoundInCmPerMs = 0.03313 + 0.0000606 * 20; // Cair ≈ (331.3 + 0.606 ⋅ ϑ) m/s

void setup() 
{
    pinMode(trigPin, OUTPUT);
    init_interrupt();
    Serial.begin(9600); 
}

void loop() 
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    Serial.print("Capteur1:");
    Serial.println(delta / 2 * speedOfSoundInCmPerMs);
    Serial.print("Capteur2:");
    Serial.println(delta1 / 2 * speedOfSoundInCmPerMs);

}

void interrupt1()
{
    a = micros();
    attachInterrupt(1, interrupt2, FALLING);
}
void interrupt2()
{
    b = micros();
    delta = (b - a);
    attachInterrupt(1, interrupt1, RISING);
}

void interrupt11()
{
    a1 = micros();
    attachInterrupt(0, interrupt22, FALLING);
}

void interrupt22()
{
    b1 = micros();
    delta1 = (b1 - a1);
    attachInterrupt(0, interrupt11, RISING);
}

void init_interrupt()
{
    attachInterrupt(1, interrupt1, RISING);
    attachInterrupt(0, interrupt11, RISING);
}


