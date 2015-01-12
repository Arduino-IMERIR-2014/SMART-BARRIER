/* 
 * File:   C_OBJET_SORTIE.cpp
 * Author: Ttibo
 * 
 * Created on 9 décembre 2014, 09:27
 */

#include "C_OBJET_SORTIE.h"
#include "Arduino.h"


void C_OBJET_SORTIE::Init(int L_Entree){
    Index_Entree = L_Entree;
    pinMode(Index_Entree, INPUT);
}