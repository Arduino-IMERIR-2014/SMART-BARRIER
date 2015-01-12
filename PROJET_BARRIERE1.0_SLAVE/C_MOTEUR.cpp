/* 
 * File:   C_MOTEUR.cpp
 * Author: Ttibo
 * 
 * Created on 9 décembre 2014, 09:25
 */

#include "C_MOTEUR.h"
#include "Arduino.h"
#include "Servo.cpp"
#include "DEFINE.h"

void C_MOTEUR::Set_Buzzer_Led(C_BUZZER* P_Buzzer, C_LED* P_Led) {
    Buzzer = P_Buzzer;
    Led = P_Led;
}

void C_MOTEUR::Init(int L_Entree) {
    moteur.attach(L_Entree);
    Active();
    Etat = MOTEUR_ACTIVE;
}

void C_MOTEUR::Change_Valeur(int P_Valeur) {
    P_Valeur /= 5.68;
    P_Valeur /= 2.0;
    P_Valeur += 75;
    moteur.write(P_Valeur);
}

void C_MOTEUR::Active_Plus_Led_Plus_Buzzer() {
    if (Etat != MOTEUR_ACTIVE) {
        moteur.attach(PORT_MOTEUR);
        for (int i = 90; i > 0; i--) {
            if ((i % 20) == 0) {
                Led->Active();
                Buzzer->Active();
            } else {
                if ((i % 10) == 0) {
                    Led->Desactive();
                    Buzzer->Desactive();
                }
            }
            moteur.write(i + 75);
            delay(50);
            //        delay(10);
        }
        moteur.detach();
        Led->Desactive();
        Buzzer->Desactive();
        Etat = MOTEUR_ACTIVE;
    }
}

void C_MOTEUR::Desactive_Plus_Led_Plus_Buzzer() {
    if (Etat != MOTEUR_DESACTIVE) {
        moteur.attach(PORT_MOTEUR);
        for (int i = 0; i < 90; i++) {
            if ((i % 20) == 0) {
                Led->Active();
                Buzzer->Active();
            } else {
                if ((i % 10) == 0) {
                    Led->Desactive();
                    Buzzer->Desactive();
                }
            }
            moteur.write(i + 75);
            delay(50);
            //        delay(10);
        }
        moteur.detach();
        Led->Desactive();
        Buzzer->Desactive();
        Etat = MOTEUR_DESACTIVE;
    }
}

void C_MOTEUR::Active() {
    if (Etat != MOTEUR_ACTIVE) {
        for (int i = 90; i > 0; i--) {
            moteur.write(i + 75);
            delay(10);
            Etat = MOTEUR_ACTIVE;
        }
    }
}

void C_MOTEUR::Desactive() {
    if (Etat != MOTEUR_DESACTIVE) {
        for (int i = 0; i < 90; i++) {
            moteur.write(i + 75);
            delay(10);
            Etat = MOTEUR_DESACTIVE;
        }
    }
}
