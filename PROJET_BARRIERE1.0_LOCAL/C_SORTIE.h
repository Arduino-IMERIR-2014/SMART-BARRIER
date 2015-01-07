#ifndef C_SORTIE_H
#define	C_SORTIE_H
/*!
 * \file C_SORTIE.h
 * \brief Classe de gestion des sorties de la carte Arduino.
 * \author Thibaut.C
 * \version 1.0
 *
 */
#include "C_LED.h"
#include "C_MOTEUR.h"
#include "C_ECRAN.h"
#include "C_BUZZER.h"
#include "DEFINE.h" 
/*! \class C_SORTIE
   * \brief classe representant la sortie de la carte.
   *
   *  La classe gère les modules de sortie de la carte.
   */
class C_SORTIE {
public:
#ifdef DEBUG_COM_USB

    inline C_ECRAN* Get_Ecran() {
        return Ecran;
    }
#endif
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe C_SORTIE, créé et initialise tout les objets en sortie.
     *
     */
    C_SORTIE();
    /*!
     *  \brief Récupere la valeur du Potentiometre.
     *
     *  Methode qui appelle la méthode Get_Intensité du potentiometre.
     *
     *  \return un entier représentant la valeur du potentiometre.
     */
    void Active_Led_Portail();
    void Desactive_Led_Portail();
    void Active_Led_Photo();
    void Desactive_Led_Photo();
    void Active_Moteur();
    void Desactive_Moteur();
    void Change_Valeur_Moteur(int);
    void Active_Ecran();
    void Desactive_Ecran();
    void Affiche(String);
    void Affiche(int);
    void Active_Buzzer();
    void Desactive_Buzzer();
protected:
    C_MOTEUR* Moteur;
    C_LED* Led_Portail;
    C_LED* Led_Photo;
    C_ECRAN* Ecran;
    C_BUZZER* Le_Buzzer;
};

#endif	/* C_SORTIE_H */

