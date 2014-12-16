/* 
 * File:   DEFINE.h
 * Author: Ttibo
 *
 * Created on 9 décembre 2014, 09:23
 */

#ifndef DEFINE_H
#define	DEFINE_H

#define DEBUG_COM_USB 

#define PORT_LED_PORTAIL 4
#define PORT_LED_PHOTO 7
#define PORT_MOTEUR 8 
#define PORT_BOUTON 5
#define PORT_POTENTIOMETRE 2
#define PORT_BUZZER 3
#define PORT_CAPTEUR_LUMIERE 0
#define PORT_MICRO 2

#define SEUIL_JOUR 700


///////////////////////VALEUR POUVANT ETRE RECU A TRAVERS LE RESEAU/////////////////////

#define MODE_AUTOMATIQUE 1
#define MODE_MANUEL 2

#define ACTIVE_LED_PORTAIL 3
#define DESACTIVE_LED_PORTAIL 4
#define ACTIVE_MOTEUR 5
#define DESACTIVE_MOTEUR 6
#define ACTIVE_BUZZER 7
#define DESACTIVE_BUZZER 8
#define ACTIVE_LED_FLASH 9
#define DESACTIVE_LED_FLASH 10

#define RECUPERE_INFO_CAPTEUR_LUMIERE 11
#define RECUPERE_INFO_BOUTON 12

#define RESET 99

///////////////////////////////////////////////////////////////////////////////////////////

#endif	/* DEFINE_H */

