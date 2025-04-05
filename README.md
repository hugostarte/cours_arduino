# Support de Cours Arduino

Ce dépôt contient les exemples et projets réalisés dans le cadre du cours Arduino. Chaque dossier représente un projet différent avec son code source et sa documentation.

## Projets disponibles

### 1. [Contrôle de LED](led_controle/)
Objectif: faire clignoter une LED.

### 2. [Lecture de température et humidité avec DHT22](lecture_temperature_DHT/)
Projet utilisant un capteur DHT22 pour mesurer la température et l'humidité, avec affichage sur moniteur série.

### 3. [Contrôle de servo-moteur avec potentiomètre](servo_potentiometre/)
Contrôle d'un servo-moteur à l'aide d'un potentiomètre.

### 4. [Contrôle de buzzer avec potentiomètre](buzzer_potentiometre/)
Contrôle d'un buzzer avec un potentiomètre et affichage sur écran OLED.

### 5. [Affichage de messages sur écran OLED](ecran_oled_messages/)
Affichage de messages aléatoires sur un écran OLED.

## Matériel nécessaire

Pour suivre ces projets, vous aurez besoin de :
- Arduino UNO ou compatible
- Câble USB pour connecter l'Arduino à l'ordinateur
- LEDs et résistances
- Capteur DHT22
- Servo-moteur
- Potentiomètre
- Buzzer
- Écran OLED 0.96" (128x64 pixels)
- Fils de connexion
- Breadboard (plaque d'essai)

## Installation

1. Installez l'IDE Arduino depuis [le site officiel](https://www.arduino.cc/en/software)
2. Ouvrez l'IDE Arduino
3. Installez les bibliothèques nécessaires via "Outils" > "Gérer les bibliothèques..." :

### Bibliothèques requises

| Nom de la bibliothèque | Auteur | Version recommandée | Projets utilisant cette bibliothèque |
|------------------------|--------|---------------------|--------------------------------------|
| DHT sensor library | Adafruit | 1.4.4 | Lecture de température DHT22 |
| Adafruit SSD1306 | Adafruit | 2.5.7 | Affichage OLED, Buzzer avec OLED |
| Adafruit GFX Library | Adafruit | 1.11.5 | Affichage OLED, Buzzer avec OLED |
| Servo | Arduino | 1.2.1 | Contrôle de servo-moteur |
| SoftWire | Peter Fleury | 1.0.0 | Buzzer avec OLED (pins personnalisés) |
| ArduinoJson | Benoit Blanchon | 6.21.3 | Lecture de température DHT22 (envoi de données) |
| ESP8266WiFi | ESP8266 Community | 1.0.0 | Lecture de température DHT22 (envoi de données) |
| ESP8266HTTPClient | ESP8266 Community | 1.0.0 | Lecture de température DHT22 (envoi de données) |

### Comment installer une bibliothèque

1. Ouvrez l'IDE Arduino
2. Allez dans "Outils" > "Gérer les bibliothèques..."
3. Dans la barre de recherche, tapez le nom de la bibliothèque
4. Cliquez sur la bibliothèque dans les résultats
5. Cliquez sur "Installer"
6. Attendez que l'installation soit terminée
7. Répétez pour chaque bibliothèque

## Structure des projets

Chaque projet contient :
- Un fichier `.ino` avec le code source
- Un fichier `README.md` avec les instructions de branchement et l'explication du code

## Ressources supplémentaires

- [Documentation officielle Arduino](https://docs.arduino.cc/)
- [Guide des capteurs Arduino](https://www.arduino.cc/en/Guide/Sensors)
- [Tutoriels Arduino](https://www.arduino.cc/en/Tutorial/HomePage)

## Licence

Ce support de cours est distribué sous licence libre. Vous êtes libre de l'utiliser, de le modifier et de le partager.

---

*Créé pour le cours Arduino - Tous droits réservés* 