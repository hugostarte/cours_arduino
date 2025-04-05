#include <Servo.h>

// Définition des broches
#define SERVO_PIN D1    // servomoteur
#define POT_PIN A0      // potentiomètre

Servo monServo;

void setup() {
  Serial.begin(19200);
  
  monServo.attach(SERVO_PIN);
}

void loop() {

  int valeurPot = analogRead(POT_PIN); 
  
  // Conversion en angle (0-180) - map(convertit une valeur analogique en une valeur numérique)
  int angle = map(valeurPot, 0, 1023, 0, 180);
  

  monServo.write(angle);
  

  Serial.print("Potentiomètre: ");
  Serial.print(valeurPot);
  Serial.print(" | Angle: ");
  Serial.print(angle);
  Serial.println("°");
  
  delay(15);
} 