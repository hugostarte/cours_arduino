# Contrôle de buzzer avec potentiomètre et affichage OLED

Ce projet permet de contrôler un buzzer à l'aide d'un potentiomètre et d'afficher le volume sur un écran OLED.

## Matériel requis

- **Microcontrôleur** : Arduino UNO
- Buzzer
- Potentiomètre 10kΩ
- Écran OLED 0.96" (128x64 pixels)
- Fils de connexion

## Branchement

1. **Buzzer** :
   - Pin positif (+) → Pin 9 de l'Arduino
   - Pin négatif (-) → GND de l'Arduino

2. **Potentiomètre** :
   - Pin du milieu (wiper) → Pin 15 de l'Arduino
   - Pin 1 → 5V de l'Arduino
   - Pin 3 → GND de l'Arduino

3. **Écran OLED** :
   - SCL → A0 de l'Arduino
   - SDA → A2 de l'Arduino
   - VCC → 5V de l'Arduino
   - GND → GND de l'Arduino

```
Arduino UNO    Buzzer          Potentiomètre    Écran OLED
Pin 9     →    Pin positif (+)  
GND       →    Pin négatif (-)  Pin 3            GND
Pin 15    →                      Pin du milieu
5V        →                      Pin 1            VCC
A0        →                                        SCL
A2        →                                        SDA
```

## Explication du code

Le code se compose de plusieurs parties :

1. **Inclusion des bibliothèques** :
   - Wire : pour la communication I2C
   - Adafruit_GFX : pour les graphiques
   - Adafruit_SSD1306 : pour l'écran OLED
   - SoftWire : pour utiliser des pins I2C personnalisés

2. **Configuration** :
   - Définition des pins pour le buzzer, le potentiomètre et l'écran OLED
   - Initialisation de l'écran OLED avec SoftWire
   - Configuration des pins I2C personnalisés (A0 pour SCL, A2 pour SDA)

3. **Boucle principale** :
   - Lecture de la valeur du potentiomètre (0-1023)
   - Conversion de cette valeur en volume (0-255)
   - Application du volume au buzzer via PWM
   - Affichage du pourcentage sur l'écran OLED
   - Affichage de messages conditionnels selon le volume

## Fonctionnement

1. L'Arduino démarre et initialise l'écran OLED
2. Dans la boucle principale :
   - Le potentiomètre est lu (valeur entre 0 et 1023)
   - Cette valeur est convertie en volume (entre 0 et 255)
   - Le buzzer est contrôlé avec ce volume via PWM
   - Le pourcentage est affiché sur l'écran OLED
   - Des messages conditionnels sont affichés selon le volume :
     - "Aie j'ai mal!" si le volume est ≥ 50%
     - "STOP STP!" si le volume est ≥ 90%

## Modifications possibles

Vous pouvez modifier le code pour changer le comportement du buzzer et de l'affichage :

- Changer les seuils pour les messages conditionnels
- Ajouter d'autres messages ou animations
- Utiliser d'autres pins pour le buzzer, le potentiomètre ou l'écran OLED
- Ajouter des effets sonores différents selon le volume

## Notes importantes

- La bibliothèque SoftWire est nécessaire pour utiliser des pins I2C personnalisés
- Si l'écran OLED ne s'affiche pas, vérifiez les connexions et l'adresse I2C
- Le buzzer peut être contrôlé directement par le pin de l'Arduino car il consomme peu de courant
- Si vous utilisez un Arduino UNO, notez que le pin 15 n'existe pas. Utilisez un autre pin analogique comme A1 