#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SoftWire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

const int buzzerPin = 9;
const int potentiometrePin = 15;

// Définition des pins I2C personnalisés
const int SDA_PIN = A2;
const int SCL_PIN = A0;

// Création d'un objet SoftWire pour l'I2C personnalisé
SoftWire sw(SDA_PIN, SCL_PIN);

// Création de l'objet display avec SoftWire
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &sw, OLED_RESET);

void setup() {
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  
  Serial.println("Initialisation de l'écran OLED...");
  
  // Initialisation de SoftWire
  sw.begin();
  
  // Test de l'adresse I2C
  sw.beginTransmission(SCREEN_ADDRESS);
  byte error = sw.endTransmission();
  
  if (error == 0) {
    Serial.println("Écran OLED trouvé à l'adresse 0x3C");
  } else {
    Serial.print("Erreur lors de la communication avec l'écran OLED. Code d'erreur: ");
    Serial.println(error);
    Serial.println("Vérifiez les connexions et l'adresse I2C.");
  }
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Échec de l'initialisation de l'écran OLED"));
    for(;;);
  }
  
  Serial.println("Écran OLED initialisé avec succès!");
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Initialisation...");
  display.display();
  delay(2000);
}

void loop() {
  int valeurPot = analogRead(potentiometrePin);
  int volumeBuzzer = map(valeurPot, 0, 1023, 0, 255);
  int pourcentage = map(valeurPot, 0, 1023, 0, 100);
  
  analogWrite(buzzerPin, volumeBuzzer);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Volume: ");
  display.print(pourcentage);
  display.println("%");
  
  if (pourcentage >= 90) {
    display.println("STOP STP!");
    display.setTextSize(2);
    display.setCursor(0, 32);
    display.println("STOP!");
  } else if (pourcentage >= 50) {
    display.println("Aie j'ai mal!");
  }
  
  display.display();
  
  Serial.print("Valeur potentiometre: ");
  Serial.print(valeurPot);
  Serial.print(" Volume buzzer: ");
  Serial.println(volumeBuzzer);
  
  delay(100);
} 