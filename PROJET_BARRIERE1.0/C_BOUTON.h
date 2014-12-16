#ifndef C_BOUTON_H
#define	C_BOUTON_H
/*!
 * \file C_BOUTON.h
 * \brief Classe de gestion des Boutons.
 * \author Thibaut.C
 * \version 1.0
 *
 */
#include "C_OBJET_ENTREE.h"
 /*! \class C_BOUTON : protected C_OBJET_ENTREE
   * \brief Classe permettant de gérer un bouton.
   *
   *  La Classe héritée de la classe C_OBJET_ENTREE permet de représenter un bouton.
   */
class C_BOUTON : protected C_OBJET_ENTREE{
    friend class C_ENTREE;
protected:
    /*!
     *  \brief Permet de récupérer l'activitée.
     *
     *  Methode surchargé qui permet de récupérer l'activité du bouton.
     *
     *  \return un booléen représentant l'état du bouton(activé ou désactivé).
     */
    bool Get_Activite();
};

#endif	/* C_BOUTON_H */

