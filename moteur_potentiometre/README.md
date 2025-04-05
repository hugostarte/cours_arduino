# Contrôle de moteur avec potentiomètre

Ce projet permet de contrôler la vitesse d'un moteur à l'aide d'un potentiomètre.

## Matériel requis

- **Microcontrôleur** : Arduino UNO
- Moteur à courant continu
- Transistor (2N2222 ou similaire)
- Diode (1N4007 ou similaire)
- Potentiomètre 10kΩ
- Fils de connexion

## Branchement

1. **Moteur** :
   - Pin positif (+) → Collecteur du transistor
   - Pin négatif (-) → GND de l'Arduino

2. **Transistor** :
   - Base → Pin 9 de l'Arduino via une résistance de 1kΩ
   - Émetteur → GND de l'Arduino
   - Collecteur → Pin positif du moteur

3. **Diode** :
   - Anode → GND
   - Cathode → Pin positif du moteur (protection contre les surtensions)

4. **Potentiomètre** :
   - Pin du milieu (wiper) → Pin A0 de l'Arduino
   - Pin 1 → 5V de l'Arduino
   - Pin 3 → GND de l'Arduino

```
Arduino UNO    Transistor       Moteur           Potentiomètre
Pin 9      →   Base (via 1kΩ)  
GND        →   Émetteur         Pin négatif (-)  Pin 3
5V         →                                     Pin 1
Pin A0     →                                     Pin du milieu
```

## Explication du code

Le code est simple et se compose de deux parties principales :

1. **Configuration (setup)** :
```cpp
const int moteurPin = 9;
const int potentiometrePin = A0;

void setup() {
  pinMode(moteurPin, OUTPUT);
  Serial.begin(9600);
}
```

2. **Boucle principale (loop)** :
```cpp
void loop() {
  int valeurPot = analogRead(potentiometrePin);
  int vitesseMoteur = map(valeurPot, 0, 1023, 0, 255);
  
  analogWrite(moteurPin, vitesseMoteur);
  
  Serial.print("Valeur potentiometre: ");
  Serial.print(valeurPot);
  Serial.print(" Vitesse moteur: ");
  Serial.println(vitesseMoteur);
  
  delay(100);
}
```

## Fonctionnement

1. L'Arduino démarre et configure le pin 9 en sortie
2. Dans la boucle principale :
   - Le potentiomètre est lu (valeur entre 0 et 1023)
   - Cette valeur est convertie en vitesse (entre 0 et 255)
   - Le moteur est contrôlé avec cette vitesse via PWM
   - Les valeurs sont affichées sur le moniteur série
   - Le programme attend 100 millisecondes
   - Le cycle recommence

## Modifications possibles

Vous pouvez modifier le code pour personnaliser le projet :

- Changer la plage de vitesse du moteur
- Utiliser d'autres pins pour le moteur ou le potentiomètre
- Ajouter un contrôle de direction avec un second potentiomètre
- Implémenter un démarrage progressif

## Notes importantes

- Le moteur doit être alimenté via un transistor car l'Arduino ne peut pas fournir assez de courant
- La diode est nécessaire pour protéger le circuit contre les surtensions lors de l'arrêt du moteur
- Le pin 9 est utilisé car il supporte le PWM, nécessaire pour le contrôle de la vitesse
- Le potentiomètre est connecté au pin A0 car il est disponible sur l'Arduino UNO 