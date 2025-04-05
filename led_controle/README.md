# Contrôle de LED

Ce projet permet de contrôler une LED avec un Arduino UNO.

## Matériel requis

- **Microcontrôleur** : Arduino UNO
- 1 LED (de n'importe quelle couleur)
- 1 résistance de 220Ω
- Fils de connexion

## Branchement

1. **LED** :
   - Anode (patte longue) → Pin 13 de l'Arduino via la résistance de 220Ω
   - Cathode (patte courte) → GND de l'Arduino

```
Arduino UNO    LED
Pin 13     →   Anode (+) via résistance 220Ω
GND        →   Cathode (-)
```

## Explication du code

Le code est très simple et se compose de deux parties principales :

1. **Configuration (setup)** :
```cpp
const int ledPin = 13;  // Définition du pin pour la LED

void setup() {
  pinMode(ledPin, OUTPUT);  // Configuration du pin en sortie
}
```

2. **Boucle principale (loop)** :
```cpp
void loop() {
  digitalWrite(ledPin, HIGH);  // Allume la LED
  delay(1000);                 // Attend 1 seconde
  digitalWrite(ledPin, LOW);   // Éteint la LED
  delay(1000);                 // Attend 1 seconde
}
```

## Fonctionnement

1. L'Arduino démarre et configure le pin 13 en sortie
2. Dans la boucle principale :
   - La LED s'allume
   - Le programme attend 1 seconde
   - La LED s'éteint
   - Le programme attend 1 seconde
   - Le cycle recommence

## Modifications possibles

Vous pouvez modifier le code pour personnaliser le projet :

- Changer la durée d'allumage et d'extinction
- Utiliser un autre pin pour la LED
- Ajouter plusieurs LEDs
- Créer des motifs d'allumage plus complexes
- Utiliser un bouton pour contrôler la LED

## Notes importantes

- La résistance de 220Ω est nécessaire pour limiter le courant traversant la LED
- Sans cette résistance, la LED pourrait être endommagée
- La patte longue de la LED (anode) doit être connectée au pin de l'Arduino
- La patte courte de la LED (cathode) doit être connectée au GND
- Le pin 13 a une LED intégrée sur la carte Arduino, ce qui peut être utile pour le débogage 