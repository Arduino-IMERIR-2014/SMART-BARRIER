/* 
 * File:   C_BOUTON.cpp
 * Author: Ttibo
 * 
 * Created on 9 décembre 2014, 13:55
 */

#include "C_BOUTON.h"
#include "Arduino.h"

bool C_BOUTON::Get_Activite() {
    if (digitalRead(Index_Entree) == HIGH) {
        return true;
    } else {
        return false;
    }
}