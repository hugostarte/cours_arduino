#include <Servo.h>

Servo monServo;
const int servoPin = 9;
const int potentiometrePin = A0;

void setup() {
  monServo.attach(servoPin);
  Serial.begin(9600);
  
  Serial.println("Initialisation du controle de servo-moteur...");
}

void loop() {
  int valeurPot = analogRead(potentiometrePin);
  int angle = map(valeurPot, 0, 1023, 0, 180);
  
  monServo.write(angle);
  
  Serial.print("Valeur potentiometre: ");
  Serial.print(valeurPot);
  Serial.print(" Angle servo: ");
  Serial.println(angle);
  
  delay(15);
} 