/**
 * \file main.c
 * \brief Programme à téléverser dans la carte Arduino.
 * \author Thibaut.C
 * \version 1.0
 * \date 12 décembre 2015
 *
 * Programme permettant à la carte de faire toutes les actions souhaités 
 *
 */
#include <Arduino.h>

#include "C_CARTE.h"
#include "DEFINE.h"
#include <Wire.h>


C_CARTE la_carte; //Creer l'objet de la carte


int val = 0;

void receiveEvent(int howMany) {
    while (Wire.available()) {
        val = Wire.read();
        switch (val) {
            case ACTIVE_LED_PORTAIL:
                la_carte.Get_Sortie().Active_Led_Portail();
                break;
            case DESACTIVE_LED_PORTAIL:
                la_carte.Get_Sortie().Desactive_Led_Portail();
                break;
            case ACTIVE_MOTEUR:
                la_carte.Get_Sortie().Active_Moteur();
                break;
            case DESACTIVE_MOTEUR:
                la_carte.Get_Sortie().Desactive_Moteur();
                break;
            case ACTIVE_BUZZER:
                la_carte.Get_Sortie().Active_Buzzer();
                break;
            case DESACTIVE_BUZZER:
                la_carte.Get_Sortie().Desactive_Buzzer();
                break;
            case ACTIVE_LED_FLASH:
                la_carte.Get_Sortie().Active_Led_Photo();
                break;
            case DESACTIVE_LED_FLASH:
                la_carte.Get_Sortie().Desactive_Led_Photo();
                break;
            default:
                break;
        }
    }
}

void setup() { //initialisation de la carte
    Wire.begin(5);
    Wire.onReceive(receiveEvent);
    la_carte.init(); //Initialise la carte
}

void loop() {

}