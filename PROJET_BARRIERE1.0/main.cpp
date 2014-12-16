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
#include "C_COMMUNICATION_USB.h"
#include "DEFINE.h"


C_CARTE la_carte; //Creer l'objet de la carte
C_COMMUNICATION_USB Com_USB; //Creer la communication USB
bool manuel_active = false; //permet de savoir si le mode manuel est active, initialisé a faux car le mode automatique est par défaut
String Mode = "1"; //MODE AUTOMATIQUE PAR DEFAUT
int mode_precedent = 0; //Pour ne pas faire deux fois la meme chose
String Message_Recu; //Message recu par la com_USB (0 si rien recu)

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
void setup() { //initialisation de la carte
    Com_USB.Init(); //Initialise la communication USB
    la_carte.init(); //Initialise la carte
}

/**
 * \fn Mode_Automatique()
 * \brief La carte est en mode Automatique
 *
 */
void Mode_Automatique() { //Passage en Mode Automatique
}

/**
 * \fn Mode_Manuel(String P_Action)
 * \brief La carte est en mode Manuel
 *
 * \param String P_Action, Chaine de caratere permettant de savoir quelle commande activer ou désaciver
 */
void Mode_Manuel(String P_Action) { //Passage en Mode Manuel
    switch (P_Action.toInt()) { //Suivant ce que l'action casté en entier :
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
        case RECUPERE_INFO_CAPTEUR_LUMIERE:
            Com_USB.Envoi(la_carte.Get_Entree().Get_Si_Jour());
            break;
        case RECUPERE_INFO_BOUTON:
            Com_USB.Envoi(la_carte.Get_Entree().Get_Etat_Bouton());
            break;
        case RESET:
            la_carte.Get_Sortie().Affiche("! ! !RESET! ! !");
            delay(1000); //On attend 1000 Millisecondes
            la_carte.Get_Sortie().Desactive_Led_Photo();
            la_carte.Get_Sortie().Desactive_Buzzer(); //On désactive le tout
            la_carte.Get_Sortie().Desactive_Moteur();
            la_carte.Get_Sortie().Desactive_Led_Portail();
            Mode = "1"; //On remet le mode en automatique
            Reset(); //On réinitialise le tout
            break;
    }
}

/**
 * \fn void Menu_Principal()
 * \brief Menu dans lequel on récupere les informations passées par USB et permet a la carte de passer en mode Automatique ou Manuel
 *
 */
void Menu_Principal() {
#ifdef DEBUG_COM_USB
    Com_USB.Set_Ecran(la_carte.Get_Sortie().Get_Ecran()); //Permet a la classe de com USB de connaitre l'écran
#endif
    Message_Recu = Com_USB.Reception();
    if (Message_Recu.toInt() != 0)Mode = Message_Recu; //Si il y a 0, c'est qu'on n'a rien recu
    switch (Mode.toInt()) {
        case MODE_AUTOMATIQUE:
            la_carte.Get_Sortie().Affiche("Mode Automatique");
            Mode_Automatique();
            manuel_active = false;
            break;
        case MODE_MANUEL:
            la_carte.Get_Sortie().Affiche("Mode Manuel");
            manuel_active = true;
            break;
        default:
            if (manuel_active == true) {
                if (Mode.toInt() != mode_precedent)Mode_Manuel(Mode);
                mode_precedent = Mode.toInt();
            } else {
                la_carte.Get_Sortie().Affiche("IL FAUT ACTIVER LE MODE MANUEL !");
            }
            break;

    }
}

/**
 * \fn void loop()
 * \brief Fonction dans laquelle le programme tourne en boucle
 *
 */
void loop() {
    int valeur;
    valeur = la_carte.Get_Entree().Get_Valeur_Potentiometre();
    la_carte.Get_Sortie().Change_Valeur_Moteur(valeur);
//    Menu_Principal();
}