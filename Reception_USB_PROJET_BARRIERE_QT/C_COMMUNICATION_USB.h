/* 
 * File:   C_COMMUNICATION_USB.h
 * Author: Ttibo
 *
 * Created on 10 décembre 2014, 13:03
 */

#ifndef C_COMMUNICATION_USB_H
#define	C_COMMUNICATION_USB_H

#include "C_THREAD.h"
#include "C_CADRE.h"


class C_COMMUNICATION_USB{
    friend class C_COMMUNICATION_USB_ECRIRE;
    friend class C_COMMUNICATION_USB_LIRE;
public: 
    bool Get_Etat_Carte();
    void Set_Cadre(C_CADRE*);
    inline static C_COMMUNICATION_USB* Get_Instance(){
        if(Instance == NULL)Instance = new C_COMMUNICATION_USB();
        return Instance;
    }
    void Set_Mode_Lecture(bool);
    bool Get_Mode_Lecture();
protected:
    bool Mode_Lecture_USB;
    static C_COMMUNICATION_USB* Instance;
    C_COMMUNICATION_USB();
    void Affiche_Erreur();
    void Init();
    C_CADRE* Le_Cadre;
    DCB dcb;
    HANDLE hCom;
    bool Etat_carte;
    BOOL Connection_Reussie;
    char Nom_Port_COM[6];
};

#endif	/* C_COMMUNICATION_USB_H */

