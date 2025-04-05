# Lecture de température et d'humidité avec DHT22

Ce projet permet de lire la température et l'humidité à l'aide d'un capteur DHT22 et d'envoyer ces données à un serveur web.

## Matériel requis

- **Microcontrôleur** : ESP8266
- Capteur DHT22
- Fils de connexion

## Branchement

1. **Capteur DHT22** :
   - Pin de données → GPIO4 (D2) de l'ESP8266
   - VCC → 3.3V de l'ESP8266
   - GND → GND de l'ESP8266

```
ESP8266         DHT22
GPIO4 (D2)  →   Pin de données
3.3V        →   VCC
GND         →   GND
```

## Configuration WiFi

Avant d'utiliser le code, vous devez configurer les paramètres WiFi :

```cpp
const char* ssid = "VOTRE_SSID";
const char* password = "VOTRE_MOT_DE_PASSE";
const char* serverUrl = "http://votre-serveur.com/dht.php";
```

## Explication du code

Le code se compose de plusieurs parties :

1. **Inclusion des bibliothèques** :
   - DHT : pour le capteur DHT22
   - ESP8266WiFi : pour la connexion WiFi
   - ESP8266HTTPClient : pour les requêtes HTTP
   - ArduinoJson : pour la création et le traitement de JSON

2. **Configuration** :
   - Configuration des paramètres WiFi
   - Initialisation du capteur DHT22
   - Configuration de la communication série

3. **Boucle principale** :
   - Lecture des valeurs du capteur
   - Création d'un objet JSON avec les données
   - Envoi des données au serveur
   - Attente de 2 secondes avant la prochaine lecture

## Fonctionnement

1. L'ESP8266 se connecte au réseau WiFi
2. Dans la boucle principale :
   - Le capteur DHT22 est lu
   - Les valeurs sont converties en JSON
   - Les données sont envoyées au serveur
   - Le programme attend 2 secondes
   - Le cycle recommence

## Fichier PHP associé

Le projet nécessite un fichier PHP sur le serveur (`dht.php`) qui :
- Reçoit les données JSON
- Les sauvegarde dans un fichier `data_dht.json`
- Renvoie une confirmation

## Modifications possibles

Vous pouvez modifier le code pour personnaliser le projet :

- Changer l'intervalle entre les lectures
- Ajouter d'autres capteurs
- Modifier le format des données envoyées
- Ajouter des alertes en cas de valeurs hors limites
- Implémenter une gestion des erreurs plus robuste

## Notes importantes

- Le capteur DHT22 doit être alimenté en 3.3V
- Une résistance de pull-up de 10kΩ est recommandée sur la ligne de données
- Le capteur ne doit pas être lu plus fréquemment que toutes les 2 secondes
- En cas d'erreur de lecture, le code attend 1 seconde avant de réessayer
- Les valeurs sont envoyées au serveur uniquement si elles sont valides
- Le fichier PHP doit être placé sur un serveur web accessible
- Le serveur doit avoir les permissions d'écriture pour créer/modifier le fichier JSON 