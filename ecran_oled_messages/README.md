# Affichage de messages aléatoires sur écran OLED

Ce projet permet d'afficher des messages aléatoires sur un écran OLED 0.96" via l'interface I2C, en utilisant un Arduino UNO.

## Matériel nécessaire

- Arduino UNO
- Écran OLED 0.96" (128x64 pixels)
- Fils de connexion
- Alimentation USB

## Branchement

### Écran OLED
- VCC → 5V
- GND → GND
- SCL → A5 - Pin I2C par défaut
- SDA → A4 - Pin I2C par défaut

## Explication du code

Le code utilise les bibliothèques suivantes :
- Wire.h : Pour la communication I2C
- Adafruit_GFX.h : Pour les fonctions graphiques
- Adafruit_SSD1306.h : Pour le contrôle de l'écran OLED

```cpp
// Configuration de l'écran
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

// Tableau de messages
const char* messages[] = {
  "Bonjour!",
  "2 * 2 = 4",
  "Arduino est cool",
  "Hello World!",
  "Temperature: 25C",
  "Humidite: 60%",
  "Bienvenue!",
  "Ca marche!",
  "Test ecran OLED"
};

void setup() {
  Serial.begin(9600);
  
  // Initialisation de l'écran
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  // Sélection aléatoire d'un message
  int messageIndex = random(9);
  
  // Affichage du message
  display.clearDisplay();
  display.setCursor(0, 32);
  display.println(messages[messageIndex]);
  display.display();
  
  delay(2000);
}
```

## Fonctionnement

1. L'Arduino UNO initialise l'écran OLED via I2C
2. Toutes les 2 secondes :
   - Un message est sélectionné aléatoirement
   - L'écran est effacé
   - Le nouveau message est affiché
   - L'affichage est mis à jour

## Modifications possibles

- Ajouter plus de messages dans le tableau
- Modifier l'intervalle entre les messages
- Ajouter des animations
- Changer la taille ou le style du texte

## Notes importantes

- L'Arduino UNO utilise les pins A4 (SDA) et A5 (SCL) pour la communication I2C par défaut
- L'adresse I2C de l'écran OLED est généralement 0x3C
- Assurez-vous d'utiliser une alimentation 5V pour l'écran OLED 