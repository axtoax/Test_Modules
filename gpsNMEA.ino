/*
  Sketch : pm_gps_test_brut-11072020
  Description : test du module GPS neo-6M avec un Arduino
  Création : PHMARDUINO le 11 07 2020
  Mise a jour : ...
*/
#include <TinyGPS++.h> 
#include <SoftwareSerial.h> // Insertion de la bibliothèque serie logicielle
TinyGPSPlus tinyGPS;
                            // entre l'Arduino et le module GPS
#define RX 11 // Affectation des broches pour la liaison série logicielle
#define TX 13 // de l'Arduino
SoftwareSerial GPS(RX, TX); // Création de l'objet GPS pour la liaison série
byte recu; // Variable pour le stockage des données recues du module

void setup()
// Initialisations
{
  Serial.begin(9600); // Initialisation liaison série materielle Arduino pour affichage
  GPS.begin(9600);    // initialisation de la liaison série du GPS pour reception données

}

void loop()
// Boucle de lecture des données
  {
   if (GPS.available() > 0 )  {
    recu = GPS.read();  // Lecture de la trame envoyée par le module GPS
    Serial.write(recu); // Affichage dans le moniteur série
    // Serial.print("Lat: "); Serial.println(tinyGPS.location.lat(), 6);

    
    }
}
