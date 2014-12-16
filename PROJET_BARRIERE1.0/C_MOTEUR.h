/* 
 * File:   C_MOTEUR.h
 * Author: Ttibo
 *
 * Created on 9 décembre 2014, 09:25
 */

#ifndef C_MOTEUR_H
#define	C_MOTEUR_H

#include "C_OBJET_SORTIE.h"
#include "Servo.h"
#include "C_BUZZER.h"
#include "C_LED.h"

class C_MOTEUR : C_OBJET_SORTIE {
    friend class C_SORTIE;
protected:
    Servo moteur;
    void Set_Buzzer_Led(C_BUZZER*,C_LED*);
    void Init(int);
    void Change_Valeur(int);
    void Active_Plus_Led_Plus_Buzzer();
    void Desactive_Plus_Led_Plus_Buzzer();
    void Active();
    void Desactive();
    C_BUZZER* Buzzer;
    C_LED* Led;
};

#endif	/* C_MOTEUR_H */

