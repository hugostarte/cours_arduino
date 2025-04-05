#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128    // Largeur de l'écran en pixels
#define SCREEN_HEIGHT 64    // Hauteur de l'écran en pixels
#define OLED_RESET -1      // Reset pin (partagé avec Arduino RESET)
#define SCREEN_ADDRESS 0x3C // Adresse I2C standard pour les écrans OLED

// Déclaration de l'objet écran
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Tableau de messages à afficher
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

// Nombre total de messages
const int nombreMessages = sizeof(messages) / sizeof(messages[0]);

void setup() {
  Serial.begin(115200);
  Serial.println("Initialisation de l'écran OLED...");

  // Initialisation de l'écran
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Échec de l'initialisation SSD1306"));
    for(;;); // Boucle infinie en cas d'échec
  }

  // Configuration de l'écran
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Initialisation...");
  display.display();
  
  delay(2000);
  Serial.println("Écran OLED initialisé avec succès!");
}

void loop() {
  // Sélection aléatoire d'un message
  int indexMessage = random(nombreMessages);
  const char* message = messages[indexMessage];
  
  // Affichage du message
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  // Centrer le texte
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(message, 0, 0, &x1, &y1, &w, &h);
  int x = (SCREEN_WIDTH - w) / 2;
  int y = (SCREEN_HEIGHT - h) / 2;
  
  display.setCursor(x, y);
  display.println(message);
  
  // Ajouter un petit texte en bas
  display.setTextSize(1);
  display.setCursor(0, SCREEN_HEIGHT - 10);
  display.print("Message ");
  display.print(indexMessage + 1);
  display.print("/");
  display.print(nombreMessages);
  
  display.display();
  
  // Affichage dans le moniteur série
  Serial.print("Message affiché: ");
  Serial.println(message);
  
  // Attente de 2 secondes
  delay(2000);
} 