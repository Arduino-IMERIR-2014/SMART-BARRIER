/* 
 * File:   C_OBJET_ENTREE.cpp
 * Author: Ttibo
 * 
 * Created on 9 décembre 2014, 13:51
 */

#include "C_OBJET_ENTREE.h"
#include "Arduino.h"

void C_OBJET_ENTREE::Init(int L_Entree){
    Index_Entree = L_Entree;
    pinMode(Index_Entree, INPUT);
}