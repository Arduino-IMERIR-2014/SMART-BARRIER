

#ifndef C_CARTE_H
#define	C_CARTE_H
/*!
 * \file C_CARTE.h
 * \brief Ckasse de gestion de la carte Arduino.
 * \author Thibaut.C
 * \version 1.0
 *
 */
#include "C_SORTIE.h"
#include "C_ENTREE.h"


 /*! \class C_CARTE
   * \brief classe representant la carte
   *
   *  La classe gere l'entrée et la sortie de la carte
   */
class C_CARTE {
public:
    /*!
     *  \brief initialise la carte
     *
     *  Methode qui permet d'initialiser la carte 
     */
    void init();
    /*!
     *  \brief Récupere la sortie
     *
     *  Methode qui permet de récupérer par référence l'objet de sortie
     *
     *  \return L'objet de sortie
     */
    C_SORTIE& Get_Sortie();
    /*!
     *  \brief Récupere l'entrée
     *
     *  Methode qui permet de récupérer par référence l'objet d'entrée
     *
     *  \return L'objet d'entrée
     */
    C_ENTREE& Get_Entree();
protected:
    C_ENTREE* Entree;/*!< Pointeur sur l'entrée*/
    C_SORTIE* la_sortie;/*!< Pointeur sur la sorte*/
};

#endif	/* C_CARTE_H */

