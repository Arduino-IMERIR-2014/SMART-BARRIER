/*
 * File:   C_CADRE.cpp
 * Author: Ttibo
 *
 * Created on 11 décembre 2014, 08:20
 */

#include "C_CADRE.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

C_CADRE::C_CADRE() {
    widget.setupUi(this);
    Le_Socket = new QTcpSocket(this);
    QObject::connect(this, SIGNAL(Signal_Set_Etat_Carte()), this, SLOT(Slot_Set_Etat_Carte()));
    QObject::connect(this, SIGNAL(Signal_Set_Info_Carte(int)), this, SLOT(Slot_Set_Info_Carte(int)));

    QObject::connect(Le_Socket, SIGNAL(connected()), this, SLOT(Slot_On_Connexion()));
    QObject::connect(Le_Socket, SIGNAL(disconnected()), this, SLOT(Slot_On_Deconnexion()));
    QObject::connect(Le_Socket, SIGNAL(readyRead()), this, SLOT(Slot_On_Lecture_Dispo()));

    Adresse_IP = "172.31.1.34";

    Le_Socket->connectToHost(IP_Local, 9999);

    widget.Etat_Carte->clear();
    widget.Etat_Carte->addItem("Deconnecte");
    widget.Etat_Serveur->clear();
    widget.Etat_Serveur->addItem("Deconnecte");

    widget.Info_Carte->hide();
    widget.Info_Serveur->hide();
}

void C_CADRE::Set_Etat_Carte(bool P_Etat) {
    Etat_Carte = P_Etat;
    emit Signal_Set_Etat_Carte();
}

void C_CADRE::Set_Info_Carte(int P_Nombre) {
    emit Signal_Set_Info_Carte(P_Nombre);
}

void C_CADRE::Slot_Set_Info_Carte(int P_Nombre) {
    widget.Info_Carte->clear();
    //    cout << "---" << P_Nombre << endl;
    widget.Info_Carte->addItem(QString::number(P_Nombre));
    if (Etat_Connexion) {
        char buffer[5];
        sprintf(buffer, "%d", P_Nombre);
        Le_Socket->write(buffer);
    }
}

void C_CADRE::Slot_Set_Etat_Carte() {
    widget.Etat_Carte->clear();
    if (Etat_Carte) {
        widget.Etat_Carte->addItem("Connecte");
        widget.Info_Carte->clear();
        widget.Info_Carte->show();
    } else {
        widget.Etat_Carte->addItem("Deconnecte");
        widget.Info_Carte->hide();
    }
}

void C_CADRE::Slot_On_Connexion() {
    Etat_Connexion = true;
    widget.Etat_Serveur->clear();
    widget.Etat_Serveur->addItem("Connecte");
    widget.Info_Serveur->show();
    //    Le_Socket->write("coucou");
}

void C_CADRE::Slot_On_Deconnexion() {
    Etat_Connexion = false;
    widget.Etat_Serveur->clear();
    widget.Etat_Serveur->addItem("Deconnecte");
    widget.Info_Serveur->clear();
    widget.Info_Serveur->hide();
}

void C_CADRE::Slot_On_Lecture_Dispo() {
    QByteArray message;
    message = Le_Socket->readAll();
    widget.Info_Serveur->clear();
    widget.Info_Serveur->addItem(message);
    Message_Ecrire = message;
    ecrire = true;
}

void C_CADRE::Slot_Connexion_Serveur() {
    if (!Etat_Connexion)Le_Socket->connectToHost(IP_Local, 9999);
    else {
        widget.Etat_Serveur->clear();
        widget.Etat_Serveur->addItem("Deja Connecte");
    }
}

void C_CADRE::Slot_Connexion_Carte() {
    if (!Etat_Carte) change_etat_carte = true;
    else {
        widget.Etat_Carte->clear();
        widget.Etat_Carte->addItem("Deja Connecte");
    }
}