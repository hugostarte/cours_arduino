# Affichage de messages aléatoires sur écran OLED

Ce projet permet d'afficher des messages aléatoires sur un écran OLED via l'interface I2C.

## Matériel requis

- **Microcontrôleur** : ESP8266
- Écran OLED 0.96" (128x64 pixels) avec interface I2C
- Fils de connexion

## Branchement

1. **Écran OLED** :
   - SCL → GPIO5 (D1) de l'ESP8266
   - SDA → GPIO4 (D2) de l'ESP8266
   - VCC → 3.3V de l'ESP8266
   - GND → GND de l'ESP8266

```
ESP8266         Écran OLED
GPIO5 (D1)  →   SCL
GPIO4 (D2)  →   SDA
3.3V        →   VCC
GND         →   GND
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

// Tableau des messages à afficher
const char* messages[] = {
  "Bonjour!",
  "2 * 2 = 4",
  "Arduino est cool",
  "ESP8266 WiFi",
  "Hello World!",
  "Temperature: 25C",
  "Humidite: 60%",
  "Bienvenue!",
  "Ca marche!",
  "Test ecran OLED"
};

const int nombreMessages = sizeof(messages) / sizeof(messages[0]);

void setup() {
  Serial.begin(115200);
  
  // Initialisation de l'écran OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Échec de l'initialisation SSD1306"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}
```

3. **Boucle principale** :
```cpp
void loop() {
  // Sélection aléatoire d'un message
  int indexMessage = random(nombreMessages);
  const char* message = messages[indexMessage];
  
  // Affichage du message
  display.clearDisplay();
  display.setCursor(0, 0);
  
  // Centrage du texte
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(message, 0, 0, &x1, &y1, &w, &h);
  int x = (SCREEN_WIDTH - w) / 2;
  int y = (SCREEN_HEIGHT - h) / 2;
  
  display.setCursor(x, y);
  display.println(message);
  display.display();
  
  delay(2000);  // Attente de 2 secondes
}
```

## Fonctionnement

1. L'ESP8266 démarre et initialise l'écran OLED
2. Dans la boucle principale :
   - Un message est sélectionné aléatoirement
   - Le message est affiché centré sur l'écran
   - Le programme attend 2 secondes
   - Le cycle recommence avec un nouveau message

## Messages par défaut

Le code inclut 10 messages prédéfinis :
- "Bonjour!"
- "2 * 2 = 4"
- "Arduino est cool"
- "ESP8266 WiFi"
- "Hello World!"
- "Temperature: 25C"
- "Humidite: 60%"
- "Bienvenue!"
- "Ca marche!"
- "Test ecran OLED"

## Modifications possibles

Vous pouvez modifier le code pour personnaliser le projet :

- Ajouter ou modifier les messages dans le tableau `messages`
- Changer le délai entre les messages (actuellement 2 secondes)
- Ajouter des animations ou des effets visuels
- Modifier la taille ou le style du texte
- Ajouter des icônes ou des symboles

## Notes importantes

- L'adresse I2C par défaut est 0x3C, mais certains écrans peuvent utiliser 0x3D
- Si l'écran ne s'affiche pas, vérifiez :
  - Les connexions des fils
  - L'adresse I2C
  - L'alimentation (3.3V uniquement pour l'ESP8266)
- Les bibliothèques Adafruit doivent être installées dans l'IDE Arduino
- L'ESP8266 utilise les pins GPIO4 et GPIO5 pour l'I2C par défaut 