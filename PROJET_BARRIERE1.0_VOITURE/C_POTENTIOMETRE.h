#ifndef C_POTENTIOMETRE_H
#define	C_POTENTIOMETRE_H
/*!
 * \file C_POTENTIOMETRE.h
 * \brief Classe de gestion des Potentiometres.
 * \author Thibaut.C
 * \version 1.0
 *
 */
#include "C_OBJET_ENTREE.h"
 /*! \class C_POTENTIOMETRE : protected C_OBJET_ENTREE
   * \brief Permettant de gérer un potentiometre.
   *
   *  La Classe héritée de la classe C_OBJET_ENTREE permet de représenter un Potentiometre.
   */
class C_POTENTIOMETRE : protected C_OBJET_ENTREE {
    friend class C_ENTREE;
protected:
    /*!
     *  \brief Permet de récupérer l'intensité.
     *
     *  Methode qui permet de récupérer l'intensité du Potentiometre.
     *
     *  \return un entier entre 0 est 1023 représentant le degré de luminosité.
     */
    int Get_Intensite();
    /*!
     *  \brief Méthode inutile.
     *
     *  Methode surchargé inutilisée mais obligatoire car elle est en virtuelle pure dans la classe mere.
     *
     */
    bool Get_Activite();
};

#endif	/* C_POTENTIOMETRE_H */

