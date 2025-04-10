# Contrôle de servo-moteur avec potentiomètre

Ce projet permet de contrôler un servo-moteur à l'aide d'un potentiomètre. La position du servo est proportionnelle à la valeur du potentiomètre.

## Matériel requis

- **Microcontrôleur** : Arduino UNO
- 1 servo-moteur (SG90 ou similaire)
- 1 potentiomètre 10kΩ
- Fils de connexion

## Branchement

1. **Servo-moteur** :
   - Fil rouge (VCC) → 5V de l'Arduino
   - Fil marron/noir (GND) → GND de l'Arduino
   - Fil orange/jaune/blanc (signal) → Pin 9 de l'Arduino

2. **Potentiomètre** :
   - Pin du milieu (wiper) → Pin A0 de l'Arduino
   - Pin 1 → 5V de l'Arduino
   - Pin 3 → GND de l'Arduino

```
Arduino UNO    Servo-moteur          Potentiomètre
5V         →   Fil rouge (VCC)       Pin 1
GND        →   Fil marron (GND)      Pin 3
Pin 9      →   Fil orange (signal)
Pin A0     →                         Pin du milieu
```

## Explication du code

Le code se compose de plusieurs parties :

1. **Inclusion des bibliothèques** :
```cpp
#include <Servo.h>
```

2. **Configuration** :
```cpp
Servo monServo;  // Création d'un objet Servo
const int pinServo = 9;    // Pin du servo-moteur
const int pinPot = A0;     // Pin du potentiomètre

void setup() {
  Serial.begin(9600);      // Initialisation de la communication série
  monServo.attach(pinServo);  // Attache le servo au pin spécifié
}
```

3. **Boucle principale** :
```cpp
void loop() {
  // Lecture de la valeur du potentiomètre (0-1023)
  int valeurPot = analogRead(pinPot);
  
  // Conversion en angle (0-180 degrés)
  int angle = map(valeurPot, 0, 1023, 0, 180);
  
  // Application de l'angle au servo
  monServo.write(angle);
  
  // Affichage des valeurs
  Serial.print("Potentiomètre: ");
  Serial.print(valeurPot);
  Serial.print(" Angle: ");
  Serial.println(angle);
  
  delay(15);  // Petit délai pour un mouvement plus fluide
}
```

## Fonctionnement

1. L'Arduino démarre et initialise le servo-moteur
2. Dans la boucle principale :
   - Le potentiomètre est lu (valeur entre 0 et 1023)
   - Cette valeur est convertie en angle (entre 0 et 180 degrés)
   - Le servo-moteur est positionné à cet angle
   - Les valeurs sont affichées sur le moniteur série
   - Le programme attend 15 millisecondes
   - Le cycle recommence

## Modifications possibles

Vous pouvez modifier le code pour personnaliser le projet :

- Changer la plage d'angles du servo (par défaut 0-180°)
- Utiliser d'autres pins pour le servo ou le potentiomètre
- Ajouter plusieurs servos contrôlés par différents potentiomètres
- Ajouter des limites de mouvement
- Implémenter un mouvement plus fluide avec interpolation

## Notes importantes

- Le servo-moteur doit être alimenté en 5V
- Si vous utilisez plusieurs servos, il est recommandé d'utiliser une alimentation externe
- Ne dépassez pas les limites mécaniques du servo (généralement 0-180°)
- Le potentiomètre doit être de bonne qualité pour un contrôle précis
- La valeur du potentiomètre est lue toutes les 15ms pour un mouvement fluide
- En cas de saccades, vérifiez l'alimentation du servo
- Le pin 9 est utilisé car il supporte le PWM, nécessaire pour le contrôle du servo 