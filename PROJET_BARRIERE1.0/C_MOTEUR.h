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

class C_MOTEUR : C_OBJET_SORTIE {
    friend class C_SORTIE;
protected:
    Servo moteur;
    void Init(int);
    void Change_Valeur(int);
    void Active();
    void Desactive();
};

#endif	/* C_MOTEUR_H */

