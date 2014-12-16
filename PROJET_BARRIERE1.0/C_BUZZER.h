#ifndef C_BUZZER_H
#define	C_BUZZER_H
/*!
 * \file C_BUZZER.h
 * \brief Classe de gestion des Buzzers.
 * \author Thibaut.C
 * \version 1.0
 *
 */
#include "C_OBJET_SORTIE.h"
 /*! \class C_BUZZER : protected C_OBJET_SORTIE
   * \brief Classe permettant de gérer un buzzer.
   *
   *  La Classe héritée de la classe C_OBJET_SORTIE permet de représenter une buzzer.
   */
class C_BUZZER : protected C_OBJET_SORTIE{
    friend class C_MOTEUR;
    friend class C_SORTIE;
protected:
    /*!
     *  \brief Permet d'activer le buzzer.
     *
     *  Methode surchargé qui permet d'activer le buzzer.
     *
     */
    void Active();
    /*!
     *  \brief Permet de désactiver le buzzer.
     *
     *  Methode surchargé qui permet de désactiver le buzzer.
     *
     */
    void Desactive();
};

#endif	/* C_BUZZER_H */

