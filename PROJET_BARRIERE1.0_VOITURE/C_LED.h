#ifndef C_LED_H
#define	C_LED_H
/*!
 * \file C_LED.h
 * \brief Classe de gestion des LEDS.
 * \author Thibaut.C
 * \version 1.0
 *
 */
#include "C_OBJET_SORTIE.h"
 /*! \class C_LED : protected C_OBJET_SORTIE
   * \brief Classe permettant de gérer un bouton.
   *
   *  La Classe héritée de la classe C_OBJET_SORTIE permet de représenter une LED.
   */
class C_LED : protected C_OBJET_SORTIE{
    friend class C_MOTEUR;
    friend class C_SORTIE;
protected:
    /*!
     *  \brief Permet d'activer la LED.
     *
     *  Methode surchargé qui permet d'activer la LED.
     *
     */
    void Active();
    /*!
     *  \brief Permet de désactiver la LED.
     *
     *  Methode surchargé qui permet de désactiver la LED.
     *
     */
    void Desactive();
};

#endif	/* C_LED_H */

