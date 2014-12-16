/* 
 * File:   C_CADRE.h
 * Author: Ttibo
 *
 * Created on 11 décembre 2014, 08:20
 */

#ifndef _C_CADRE_H
#define	_C_CADRE_H

#include "ui_C_CADRE.h"
#include "QTcpSocket"

class C_CADRE : public QMainWindow {
    Q_OBJECT
public:
    C_CADRE();
    void Set_Etat_Carte(bool);
    void Set_Info_Carte(int);
    bool change_etat_carte = false;
    bool ecrire = false;
    QString Message_Ecrire;
private:
    QString IP_Local = "172.31.1.148";
    QString Adresse_IP;
    QTcpSocket* Le_Socket;
    Ui::C_CADRE widget;
    bool Etat_Carte;
    bool Etat_Connexion;
protected slots:
    void Slot_Set_Info_Carte(int);
    void Slot_Connexion_Carte();
    void Slot_Connexion_Serveur();
    void Slot_Set_Etat_Carte();
    void Slot_On_Connexion();
    void Slot_On_Deconnexion();
    void Slot_On_Lecture_Dispo();
signals:
    void Signal_Set_Info_Carte(int);
    void Signal_Set_Etat_Carte();
};

#endif	/* _C_CADRE_H */
