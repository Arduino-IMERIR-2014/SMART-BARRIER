/* 
 * File:   C_SORTIE.cpp
 * Author: Ttibo
 * 
 * Created on 9 décembre 2014, 09:11
 */

#include <avr/pgmspace.h>

#include "C_SORTIE.h"
#include "DEFINE.h"

C_SORTIE::C_SORTIE() {
    Led_Portail = new C_LED;
    Led_Portail->Init(PORT_LED_PORTAIL);
    Led_Photo = new C_LED;
    Led_Photo->Init(PORT_LED_PHOTO);
    Moteur = new C_MOTEUR;
    Moteur->Init(PORT_MOTEUR);
    Ecran = new C_ECRAN;
    Ecran->Init(0);
    Ecran->Active();
    Le_Buzzer = new C_BUZZER;
    Le_Buzzer->Init(PORT_BUZZER);

}

void C_SORTIE::Active_Led_Portail() {
    Led_Portail->Active();
}

void C_SORTIE::Desactive_Led_Portail() {
    Led_Portail->Desactive();
}

void C_SORTIE::Active_Led_Photo() {
    Led_Photo->Active();
}

void C_SORTIE::Desactive_Led_Photo() {
    Led_Photo->Desactive();
}

void C_SORTIE::Active_Moteur() {
    Moteur->Active();
}

void C_SORTIE::Desactive_Moteur() {
    Moteur->Desactive();
}

void C_SORTIE::Change_Valeur_Moteur(int P_Valeur) {
    Moteur->Change_Valeur(P_Valeur);
}

void C_SORTIE::Active_Ecran() {
    Ecran->Active();
}

void C_SORTIE::Desactive_Ecran() {
    Ecran->Desactive();
}

void C_SORTIE::Affiche(String P_Message) {
    Ecran->Affiche(P_Message);
}

void C_SORTIE::Affiche(int P_Nombre) {
    Ecran->Affiche(P_Nombre);
}

void C_SORTIE::Active_Buzzer() {
    Le_Buzzer->Active();
}

void C_SORTIE::Desactive_Buzzer() {
    Le_Buzzer->Desactive();
}