#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 8
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
    Serial.println(F("Échec de l'initialisation de l'écran OLED"));
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