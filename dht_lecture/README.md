# Lecture de température et d'humidité avec DHT22 et affichage OLED

Ce projet permet de lire la température et l'humidité à l'aide d'un capteur DHT22 et d'afficher ces données sur un écran OLED.

## Matériel requis

- **Microcontrôleur** : Arduino UNO
- Capteur DHT22
- Écran OLED 0.96" (128x64 pixels)
- Fils de connexion

## Branchement

1. **Capteur DHT22** :
   - Pin de données → Pin 2 de l'Arduino
   - VCC → 5V de l'Arduino
   - GND → GND de l'Arduino

2. **Écran OLED** :
   - SCL → A5 de l'Arduino (pin I2C par défaut)
   - SDA → A4 de l'Arduino (pin I2C par défaut)
   - VCC → 5V de l'Arduino
   - GND → GND de l'Arduino

```
Arduino UNO    DHT22           Écran OLED
Pin 2      →   Pin de données
5V         →   VCC             VCC
GND        →   GND             GND
A5         →                   SCL
A4         →                   SDA
```

## Explication du code

Le code utilise les bibliothèques suivantes :
- DHT.h : Pour la lecture du capteur DHT22
- Wire.h : Pour la communication I2C
- Adafruit_GFX.h : Pour les fonctions graphiques
- Adafruit_SSD1306.h : Pour le contrôle de l'écran OLED

```cpp
#define DHTPIN 2
#define DHTTYPE DHT22
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Echec initialisation ecran OLED"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Initialisation...");
  display.display();
  delay(2000);
}

void loop() {
  float temperature = dht.readTemperature();
  float humidite = dht.readHumidity();
  
  if (isnan(temperature) || isnan(humidite)) {
    display.clearDisplay();
    display.setCursor(0,0);
    display.println("Erreur de lecture!");
    display.display();
    delay(2000);
    return;
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperature: ");
  display.println(temperature);
  display.print("Humidite: ");
  display.println(humidite);
  display.display();
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidite: ");
  Serial.print(humidite);
  Serial.println(" %");
  
  delay(2000);
}
```

## Fonctionnement

1. L'Arduino UNO initialise le capteur DHT22 et l'écran OLED
2. Toutes les 2 secondes :
   - Le capteur DHT22 est lu pour obtenir la température et l'humidité
   - Les valeurs sont affichées sur l'écran OLED
   - Les valeurs sont également envoyées au moniteur série

## Modifications possibles

- Changer l'intervalle entre les lectures
- Ajouter d'autres capteurs
- Modifier l'affichage sur l'écran OLED
- Ajouter des alertes en cas de valeurs hors limites

## Notes importantes

- Le capteur DHT22 doit être alimenté en 5V
- Une résistance de pull-up de 10kΩ est recommandée sur la ligne de données
- Le capteur ne doit pas être lu plus fréquemment que toutes les 2 secondes
- L'Arduino UNO utilise les pins A4 (SDA) et A5 (SCL) pour la communication I2C par défaut 