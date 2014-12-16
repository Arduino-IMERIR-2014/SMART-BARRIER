/* 
 * File:   C_MOTEUR.cpp
 * Author: Ttibo
 * 
 * Created on 9 décembre 2014, 09:25
 */

#include "C_MOTEUR.h"
#include "Arduino.h"
#include "Servo.cpp"

void C_MOTEUR::Init(int L_Entree) {
    moteur.attach(L_Entree);
    Desactive();
}

void C_MOTEUR::Change_Valeur(int P_Valeur) {
    P_Valeur /= 5.68;
    P_Valeur /= 2.0;
    moteur.write(P_Valeur);
}

void C_MOTEUR::Active() {
    for (int i = 0; i < 90; i++) {
        moteur.write(i);
        delay(10);
    }
}

void C_MOTEUR::Desactive() {
    for (int i = 90; i > 0; i--) {
        moteur.write(i);
        delay(10);
    }
}
