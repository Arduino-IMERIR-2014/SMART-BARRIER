/* 
 * File:   C_POTENTIOMETRE.cpp
 * Author: Ttibo
 * 
 * Created on 12 décembre 2014, 08:25
 */

#include "C_POTENTIOMETRE.h"
#include "Arduino.h"

int C_POTENTIOMETRE::Get_Intensite(){
    return analogRead(Index_Entree);
}

bool C_POTENTIOMETRE::Get_Activite(){
    
}