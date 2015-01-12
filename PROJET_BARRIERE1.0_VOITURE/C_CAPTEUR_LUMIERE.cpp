    /* 
 * File:   C_LIGHT_SENSOR.cpp
 * Author: Ttibo
 * 
 * Created on 9 décembre 2014, 14:51
 */

#include "C_CAPTEUR_LUMIERE.h"
#include "C_OBJET_ENTREE.h"
#include "DEFINE.h"
#include "Arduino.h"


bool C_CAPTEUR_LUMIERE::Get_Activite() {
    if (analogRead(Index_Entree) > SEUIL_JOUR) return true;
    else return false;
}

int C_CAPTEUR_LUMIERE::Get_Intensite(){
    return analogRead(Index_Entree);
}