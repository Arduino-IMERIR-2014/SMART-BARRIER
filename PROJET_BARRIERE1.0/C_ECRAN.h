#ifndef C_ECRAN_H
#define	C_ECRAN_H

/*!
 * \file C_ECRAN.h
 * \brief Classe de gestion des écrans.
 * \author Thibaut.C
 * \version 1.0
 *
 */
#include "C_OBJET_SORTIE.h"
#include "rgb_lcd.h"
#include "DEFINE.h"
 /*! \class C_BUZZER : protected C_OBJET_SORTIE
   * \brief Classe permettant de gérer un buzzer.
   *
   *  La Classe héritée de la classe C_OBJET_SORTIE permet de représenter une buzzer.
   */
class C_ECRAN : C_OBJET_SORTIE {
    friend class C_SORTIE;
#ifdef DEBUG_COM_USB
    friend class C_COMMUNICATION_USB;
#endif
protected:
    rgb_lcd Ecran;
    /*!
     *  \brief Permet d'afficher une chaine de caractere sur l'ecran.
     *
     *  \param Chaine de caractere à afficher.
     *
     */
    void Affiche(String);
    /*!
     *  \brief Permet d'afficher un entier sur l'ecran.
     *
     *  \param Entier à afficher.
     *
     */
    void Affiche(int);
    /*!
     *  \brief Permet d'initialiser l'écran.
     *
     *  \param Parametre non utilisé.
     *
     */
    void Init(int);
    /*!
     *  \brief Permet d'activer l'écran.
     *
     *  Methode surchargé qui permet d'activer l'écran.
     *
     */
    void Active();
    /*!
     *  \brief Permet de désactiver l'écran.
     *
     *  Methode surchargé qui permet de désactiver l'écran.
     *
     */
    void Desactive();
};

#endif	/* C_ECRAN_H */

