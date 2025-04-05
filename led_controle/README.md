# Contrôle de LED avec Arduino

Ce projet permet de contrôler une LED à l'aide d'un Arduino UNO. La LED clignote avec un intervalle d'une seconde.

## Matériel nécessaire

- 1 Arduino UNO
- 1 LED (de n'importe quelle couleur)
- 1 résistance (220Ω à 330Ω)
- Fils de connexion

## Branchement

Le branchement est très simple :

1. **LED** :
   - Anode (patte longue, +) → Pin 13 de l'Arduino
   - Cathode (patte courte, -) → Résistance → GND de l'Arduino

2. **Résistance** :
   - Une extrémité → Cathode de la LED
   - Autre extrémité → GND de l'Arduino

```
Arduino UNO    LED
Pin 13    →    Anode (+)
GND       →    Résistance → Cathode (-)
```

## Explication du code

Le code est très simple et se compose de deux parties principales :

### Configuration (setup)

```cpp
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
}
```

- `const int ledPin = 13;` : Définit le pin 13 comme celui qui contrôle la LED
- `pinMode(ledPin, OUTPUT);` : Configure le pin 13 comme sortie

### Boucle principale (loop)

```cpp
void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
```

- `digitalWrite(ledPin, HIGH);` : Allume la LED (5V)
- `delay(1000);` : Attend 1000 millisecondes (1 seconde)
- `digitalWrite(ledPin, LOW);` : Éteint la LED (0V)
- `delay(1000);` : Attend à nouveau 1 seconde

Cette séquence se répète indéfiniment, créant un effet de clignotement.

## Fonctionnement

1. L'Arduino démarre et configure le pin 13 comme sortie
2. Dans la boucle principale :
   - La LED s'allume pendant 1 seconde
   - La LED s'éteint pendant 1 seconde
   - Le cycle se répète

## Modifications possibles

Vous pouvez modifier le code pour changer le comportement de la LED :

- Changer la vitesse de clignotement en modifiant les valeurs de `delay()`
- Utiliser un autre pin en modifiant la valeur de `ledPin`
- Ajouter plusieurs LEDs sur différents pins
- Utiliser `analogWrite()` pour contrôler la luminosité de la LED

## Notes importantes

- La résistance est nécessaire pour limiter le courant qui traverse la LED
- Sans résistance, la LED pourrait être endommagée ou détruire le pin de l'Arduino
- La valeur de la résistance dépend de la tension d'alimentation et de la LED (220Ω à 330Ω est généralement approprié) 