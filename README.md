# Projets Arduino

Ce dépôt contient plusieurs projets Arduino pour apprendre et expérimenter avec différents composants et fonctionnalités.

## Liste des projets

1. [Contrôle de LED](led_controle/README.md)
   - Projet de base pour contrôler une LED avec un Arduino UNO
   - Clignotement simple avec un intervalle d'une seconde

2. [Lecture de température et d'humidité avec DHT22](lecture_temperature_DHT/README.md)
   - Utilisation d'un ESP8266 pour lire les données d'un capteur DHT22
   - Envoi des données à un serveur web via WiFi

3. [Lecture de température et d'humidité avec DHT22 et affichage OLED](dht_lecture/README.md)
   - Utilisation d'un Arduino UNO pour lire les données d'un capteur DHT22
   - Affichage des données sur un écran OLED

4. [Contrôle de servo-moteur avec potentiomètre](servo_potentiometre/README.md)
   - Contrôle d'un servo-moteur avec un potentiomètre sur Arduino UNO
   - Position du servo proportionnelle à la valeur du potentiomètre

5. [Contrôle de moteur avec potentiomètre](moteur_potentiometre/README.md)
   - Contrôle de la vitesse d'un moteur avec un potentiomètre sur Arduino UNO
   - Vitesse du moteur proportionnelle à la valeur du potentiomètre

6. [Contrôle de buzzer avec potentiomètre et affichage OLED](buzzer_potentiometre/README.md)
   - Contrôle du volume d'un buzzer avec un potentiomètre
   - Affichage du volume sur un écran OLED

7. [Affichage de messages aléatoires sur écran OLED](ecran_oled_messages/README.md)
   - Affichage de messages aléatoires sur un écran OLED avec Arduino UNO
   - Changement de message toutes les 2 secondes

## Matériel nécessaire

### Composants communs
- Fils de connexion
- Breadboard (recommandé)
- Alimentation USB

### Composants spécifiques
- LED et résistance 220Ω
- Capteur DHT22
- Servo-moteur SG90
- Potentiomètre 10kΩ
- Buzzer
- Écran OLED 0.96" (128x64)
- Moteur à courant continu
- Transistor (2N2222 ou similaire)
- Diode (1N4007 ou similaire)
- ESP8266 (pour le projet WiFi)

## Bibliothèques requises

| Bibliothèque | Auteur | Version | Projets |
|--------------|---------|---------|---------|
| DHT sensor library | Adafruit | 1.4.4 | Lecture température |
| Adafruit SSD1306 | Adafruit | 2.5.7 | Affichage OLED |
| Adafruit GFX Library | Adafruit | 1.11.5 | Affichage OLED |
| Servo | Arduino | 1.2.1 | Contrôle servo |
| ArduinoJson | Benoit Blanchon | 6.21.3 | Communication JSON |
| ESP8266WiFi | ESP8266 Community | 1.0.0 | Connexion WiFi |
| ESP8266HTTPClient | ESP8266 Community | 1.0.0 | Requêtes HTTP |

## Installation

1. Installez l'IDE Arduino depuis [le site officiel](https://www.arduino.cc/en/software)
2. Dans l'IDE Arduino, allez dans "Outils > Gérer les bibliothèques"
3. Installez les bibliothèques listées ci-dessus
4. Pour les projets ESP8266 :
   - Ajoutez l'URL `http://arduino.esp8266.com/stable/package_esp8266com_index.json` dans les préférences
   - Installez le support ESP8266 via le gestionnaire de cartes

## Pins par défaut

### Arduino UNO
- I2C : SDA (A4), SCL (A5)
- PWM : 3, 5, 6, 9, 10, 11
- Analogiques : A0, A1, A2, A3, A4, A5
- Numériques : 0-13

### ESP8266
- I2C : GPIO4 (D2), GPIO5 (D1)
- PWM : GPIO0-GPIO15
- Analogique : A0

## Structure des projets

Chaque projet est organisé dans son propre dossier et contient :
- Le fichier source Arduino (.ino)
- Un README.md détaillé avec :
  - Liste du matériel requis
  - Instructions de branchement
  - Explication du code
  - Notes importantes
