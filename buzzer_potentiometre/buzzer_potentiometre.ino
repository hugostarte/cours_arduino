#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

const int buzzerPin = 9;
const int potentiometrePin = A1;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  pinMode(buzzerPin, OUTPUT);
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
  
  // Petit bonus pour ajouter un message sur l'ecran en fonction du volume
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