#ifndef C_ENTREE_H
#define	C_ENTREE_H
/*!
 * \file C_ENTREE.h
 * \brief Classe de gestion des entrées de la carte Arduino.
 * \author Thibaut.C
 * \version 1.0
 *
 */
#include "C_BOUTON.h"
#include "C_CAPTEUR_LUMIERE.h"
#include "C_POTENTIOMETRE.h"
 /*! \class C_ENTREE
   * \brief classe representant l'entrée de la carte.
   *
   *  La classe gère les modules d'entrée de la carte.
   */
class C_ENTREE {
public:
    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe C_ENTREE, créé et initialise tout les objets en entrée.
     *
     */
    C_ENTREE();
    /*!
     *  \brief Récupere la valeur du Potentiometre.
     *
     *  Methode qui appelle la méthode Get_Intensité du potentiometre.
     *
     *  \return un entier représentant la valeur du potentiometre.
     */
    int Get_Valeur_Potentiometre();
    /*!
     *  \brief Récupere l'état du bouton.
     *
     *  Methode qui appelle la méthode Get_Activite du Bouton.
     *
     *  \return un booléen représentant l'état du bouton (vrai pour activé, faux pour désactivé).
     */
    bool Get_Etat_Bouton();
    /*!
     *  \brief Récupere l'état du capteur de lumiere.
     *
     *  Methode qui appelle la méthode Get_Activite du Capteur de Lumiere.
     *
     *  \return un booléen représentant l'état du bouton (vrai pour jour, faux pour nuit).
     */
    bool Get_Si_Jour();
private:
    C_POTENTIOMETRE* Le_Potentiometre;/*!< Pointeur sur le Potentiometre*/
    C_BOUTON* Le_Bouton;/*!< Pointeur sur le Bouton*/
    C_CAPTEUR_LUMIERE* Le_Capteur_Lumiere;/*!< Pointeur sur le Capteur de Lumiere*/
};

#endif	/* C_ENTREE_H */

