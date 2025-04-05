const int moteurPin = 9;
const int potentiometrePin = A0;

void setup() {
  pinMode(moteurPin, OUTPUT);
  Serial.begin(9600);
  
  Serial.println("Initialisation du controle de moteur...");
}

void loop() {
  int valeurPot = analogRead(potentiometrePin);
  int vitesseMoteur = map(valeurPot, 0, 1023, 0, 255);
  
  analogWrite(moteurPin, vitesseMoteur);
  
  Serial.print("Valeur potentiometre: ");
  Serial.print(valeurPot);
  Serial.print(" Vitesse moteur: ");
  Serial.println(vitesseMoteur);
  
  delay(100);
} 