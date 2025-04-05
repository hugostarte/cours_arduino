# Contrôle de buzzer avec potentiomètre et affichage OLED

Ce projet permet de contrôler un buzzer à l'aide d'un potentiomètre et d'afficher le volume sur un écran OLED.

## Matériel requis

- **Microcontrôleur** : Arduino UNO
- Buzzer
- Potentiomètre 10kΩ
- Écran OLED 0.96" (128x64 pixels)
- Fils de connexion

## Branchement

1. **Buzzer** :
   - Pin positif (+) → Pin 9 de l'Arduino
   - Pin négatif (-) → GND de l'Arduino

2. **Potentiomètre** :
   - Pin du milieu (wiper) → Pin A1 de l'Arduino
   - Pin 1 → 5V de l'Arduino
   - Pin 3 → GND de l'Arduino

3. **Écran OLED** :
   - SCL → A5 de l'Arduino (pin I2C par défaut)
   - SDA → A4 de l'Arduino (pin I2C par défaut)
   - VCC → 5V de l'Arduino
   - GND → GND de l'Arduino

```
Arduino UNO    Buzzer          Potentiomètre    Écran OLED
Pin 9     →    Pin positif (+)  
GND       →    Pin négatif (-)  Pin 3            GND
Pin A1    →                      Pin du milieu
5V        →                      Pin 1            VCC
A5        →                                        SCL
A4        →                                        SDA
```

## Explication du code

Le code se compose de plusieurs parties :

1. **Inclusion des bibliothèques** :
```cpp
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
```

2. **Configuration** :
```cpp
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int pinBuzzer = 9;     // Pin du buzzer
const int pinPot = A1;       // Pin du potentiomètre

void setup() {
  Serial.begin(9600);
  
  // Initialisation de l'écran OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Échec de l'initialisation SSD1306"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Initialisation...");
  display.display();
  
  pinMode(pinBuzzer, OUTPUT);
}
```

3. **Boucle principale** :
```cpp
void loop() {
  // Lecture du potentiomètre
  int valeurPot = analogRead(pinPot);
  
  // Conversion en volume (0-255)
  int volume = map(valeurPot, 0, 1023, 0, 255);
  
  // Application du volume au buzzer
  analogWrite(pinBuzzer, volume);
  
  // Calcul du pourcentage
  int pourcentage = map(valeurPot, 0, 1023, 0, 100);
  
  // Affichage sur l'écran OLED
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Volume: ");
  display.print(pourcentage);
  display.println("%");
  
  // Messages conditionnels
  if (pourcentage >= 50) {
    display.println("Aie j'ai mal!");
  }
  if (pourcentage >= 90) {
    display.println("STOP STP!");
  }
  
  display.display();
  delay(100);
}
```

## Fonctionnement

1. L'Arduino démarre et initialise l'écran OLED
2. Dans la boucle principale :
   - Le potentiomètre est lu (valeur entre 0 et 1023)
   - Cette valeur est convertie en volume (entre 0 et 255)
   - Le buzzer est contrôlé avec ce volume via PWM
   - Le pourcentage est affiché sur l'écran OLED
   - Des messages conditionnels sont affichés selon le volume :
     - "Aie j'ai mal!" si le volume est ≥ 50%
     - "STOP STP!" si le volume est ≥ 90%

## Modifications possibles

Vous pouvez modifier le code pour changer le comportement du buzzer et de l'affichage :

- Changer les seuils pour les messages conditionnels
- Ajouter d'autres messages ou animations
- Utiliser d'autres pins pour le buzzer, le potentiomètre ou l'écran OLED
- Ajouter des effets sonores différents selon le volume

## Notes importantes

- L'Arduino UNO utilise les pins A4 (SDA) et A5 (SCL) pour l'I2C par défaut
- Si l'écran OLED ne s'affiche pas, vérifiez les connexions et l'adresse I2C
- Le buzzer peut être contrôlé directement par le pin de l'Arduino car il consomme peu de courant
- Le potentiomètre est connecté au pin A1 car il est disponible sur l'Arduino UNO 