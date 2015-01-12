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
#include "C_COMMUNICATION_USB.h"

C_CARTE la_carte; //Creer l'objet de la carte
C_COMMUNICATION_BLUETOOTH Com_BLUETOOTH; //Creer la communication USB

/**
 * \fn void(* Reset) (void) = 0
 * \brief Fonction permettant de réinitialiser la carte.
 *
 */
void(* Reset) (void) = 0;

/**
 * \fn setup()
 * \brief Fonction permettant l'initialisation de la carte
 *
 */
void setup() {
    la_carte.init();
    Com_BLUETOOTH.Init();
}


/**
 * \fn void loop()
 * \brief Fonction dans laquelle le programme tourne en boucle
 *
 */
int i;
void loop() {
    la_carte.Get_Sortie().Affiche(Com_BLUETOOTH.Reception());
}