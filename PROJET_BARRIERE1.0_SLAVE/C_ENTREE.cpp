/* 
 * File:   C_ENTREE.cpp
 * Author: Ttibo
 * 
 * Created on 9 décembre 2014, 13:54
 */

#include "C_ENTREE.h"
#include "DEFINE.h"
#include "C_CAPTEUR_LUMIERE.h"

C_ENTREE::C_ENTREE() {
    Le_Potentiometre = new C_POTENTIOMETRE;
    Le_Potentiometre->Init(PORT_POTENTIOMETRE);
    Le_Bouton = new C_BOUTON;
    Le_Bouton->Init(PORT_BOUTON);
    Le_Capteur_Lumiere = new C_CAPTEUR_LUMIERE;
    Le_Capteur_Lumiere->Init(PORT_CAPTEUR_LUMIERE);
}

int C_ENTREE::Get_Valeur_Potentiometre(){
    return Le_Potentiometre->Get_Intensite();
}

bool C_ENTREE::Get_Etat_Bouton(){
    return Le_Bouton->Get_Activite();
}

bool C_ENTREE::Get_Si_Jour(){
    return Le_Capteur_Lumiere->Get_Activite();
}