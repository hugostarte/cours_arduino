#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* messages[] = {
  "Bonjour!",
  "Comment allez-vous?",
  "Bonne journee!",
  "Au revoir!",
  "A bientot!"
};

const int nombreMessages = sizeof(messages) / sizeof(messages[0]);

void setup() {
  Serial.begin(9600);
  
  Serial.println("Initialisation de l'ecran OLED...");
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("Echec initialisation ecran OLED"));
    for(;;);
  }
  
  Serial.println("Ecran OLED initialise avec succes!");
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Initialisation...");
  display.display();
  delay(2000);
}

void loop() {
  int messageIndex = random(nombreMessages);
  const char* message = messages[messageIndex];
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(message, 0, 0, &x1, &y1, &w, &h);
  
  int x = (SCREEN_WIDTH - w) / 2;
  int y = (SCREEN_HEIGHT - h) / 2;
  
  display.setCursor(x, y);
  display.println(message);
  display.display();
  
  Serial.print("Message affiche: ");
  Serial.println(message);
  
  delay(2000);
} 