/* 
 * File:   C_ECRAN.cpp
 * Author: Ttibo
 * 
 * Created on 9 décembre 2014, 10:53
 */

#include "C_ECRAN.h"
#include "C_CARTE.h"
#include "rgb_lcd.cpp"
#include "Wire.cpp"
#include "twi.c"

void C_ECRAN::Init(int Parametre_Inutile) { //On n'utilise pas le parametre, mais il est nécessaire car il est prototypé ainsi
    Ecran.begin(0, 0);
}

void C_ECRAN::Affiche(String P_Message) {
    Ecran.clear();
    Ecran.print(P_Message);
}

void C_ECRAN::Affiche(int P_Nombre) {
    Ecran.clear();
    Ecran.print(P_Nombre);
}

void C_ECRAN::Active() {
    Ecran.display();
}

void C_ECRAN::Desactive() {
    Ecran.noDisplay();
}
