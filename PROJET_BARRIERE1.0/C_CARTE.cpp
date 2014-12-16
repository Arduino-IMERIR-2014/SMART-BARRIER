/* 
 * File:   C_CARTE.cpp
 * Author: Ttibo
 * 
 * Created on 9 décembre 2014, 09:10
 */

#include "C_CARTE.h"

void C_CARTE::init() {
    la_sortie = new C_SORTIE;
    Entree = new C_ENTREE;
}

C_SORTIE& C_CARTE::Get_Sortie() {
    return *la_sortie;
}

C_ENTREE& C_CARTE::Get_Entree() {
    return *Entree;
}