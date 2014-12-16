#ifndef C_OBJET_ENTREE_H
#define	C_OBJET_ENTREE_H
/*!
 * \file C_OBJET_ENTREE.h
 * \brief Ckasse de gestion des entrées de la carte Arduino.
 * \author Thibaut.C
 * \version 1.0
 *
 */

 /*! \class C_OBJET_ENTREE
   * \brief Classe Abstraite représentant le Modele des objets en entrée.
   *
   *  La classe représente les Objets en Entrée.
   */
class C_OBJET_ENTREE {
protected:
    int Index_Entree;/*!<Entier représentant l'emplacement de l'entree sur le Pin*/
    /*!
     *  \brief Initialisation des informations.
     *
     *  Methode virtuelle qui permet d'initialiser l'entier Index_Entree et le pin associé à l'index en mode entrée.
     *
     */
    virtual void Init(int);
    /*!
     *  \brief Recupere l'activite.
     *
     *  Methode virtuelle pure qui permet de récuperer l'état renvoyé par l'entrée.
     *
     */
    virtual bool Get_Activite()=0;
};

#endif	/* C_OBJET_ENTREE_H */

