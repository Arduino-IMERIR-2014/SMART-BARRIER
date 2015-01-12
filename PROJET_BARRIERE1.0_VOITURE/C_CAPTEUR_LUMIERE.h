#ifndef C_CAPTEUR_LUMIERE_H
#define	C_CAPTEUR_LUMIERE_H
/*!
 * \file C_CAPTEUR_LUMIERE.h
 * \brief Classe de gestion des Capteurs de Lumiere.
 * \author Thibaut.C
 * \version 1.0
 *
 */
#include "C_OBJET_ENTREE.h"
 /*! \class C_CAPTEUR_LUMIERE : protected C_OBJET_ENTREE
   * \brief Permettant de gérer un capteur de lumiere.
   *
   *  La Classe héritée de la classe C_OBJET_ENTREE permet de représenter un capteur de lumiere.
   */
class C_CAPTEUR_LUMIERE : protected C_OBJET_ENTREE {
    friend class C_ENTREE;
protected:
    /*!
     *  \brief Permet de récupérer l'intensité.
     *
     *  Methode qui permet de récupérer l'intensité du capteur de lumiere.
     *
     *  \return un entier entre 0 est 1023 représentant le degré de luminosité.
     */
    int Get_Intensite();
    /*!
     *  \brief Permet de récupérer l'activité.
     *
     *  Methode surchargée qui permet de récupérer l'activité du capteur de lumiere.
     *
     *  \return un booléen représentant l'état du capteur de lumiere(jour ou nuit).
     */
    bool Get_Activite();
};

#endif	/* C_CAPTEUR_LUMIERE_H */