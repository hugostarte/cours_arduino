#include <DHT.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#define DHTPIN D4      
#define DHTTYPE DHT22   

const char* ssid = "NomDuWifi";
const char* password = "MotDePasseDuWifi";
const char* serverUrl = "http://hugostawiarski.fr/cours_arduino/dht.php";
// Données visibles sur http://hugostawiarski.fr/cours_arduino/


DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;

void setup() {
  Serial.begin(19200);
  dht.begin();
  
  // Connexion au WiFi
  WiFi.begin(ssid, password);
  Serial.println("Connexion au WiFi...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConnecté au WiFi");
  Serial.print("Adresse IP: ");
  Serial.println(WiFi.localIP());
  Serial.println("Lecture du capteur DHT22...");
}

void loop() {
  float temperature = dht.readTemperature(); 
  float humidity = dht.readHumidity();      

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Erreur de lecture du capteur !");
  } else {
    Serial.print("Température : ");
    Serial.print(temperature);
    Serial.print(" °C\t");
    Serial.print("Humidité : ");
    Serial.print(humidity);
    Serial.println(" %");
    
    if (WiFi.status() == WL_CONNECTED) {
      HTTPClient http;
      
      StaticJsonDocument<200> doc;
      doc["temperature"] = temperature;
      doc["humidity"] = humidity;
      
      String jsonString;
      serializeJson(doc, jsonString);
      
      Serial.println("JSON envoyé : " + jsonString);
      
      http.begin(client, serverUrl);
      http.addHeader("Content-Type", "application/json");
      
      int httpResponseCode = http.POST(jsonString);
      
      if (httpResponseCode > 0) {
        String response = http.getString();
        Serial.print("Code de réponse HTTP: ");
        Serial.println(httpResponseCode);
        Serial.print("Réponse du serveur: ");
        Serial.println(response);
      } else {
        Serial.print("Erreur lors de l'envoi: ");
        Serial.println(httpResponseCode);
      }
      
      http.end();
    }
  }

  delay(2000);
}
