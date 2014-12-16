/* 
 * File:   C_COMMUNICATION_USB.cpp
 * Author: Ttibo
 * 
 * Created on 10 décembre 2014, 13:03
 */

#include "C_COMMUNICATION_USB.h"
#include <iostream>
using namespace std;

C_COMMUNICATION_USB* C_COMMUNICATION_USB::Instance = nullptr;

C_COMMUNICATION_USB::C_COMMUNICATION_USB() : Mode_Lecture_USB(false){
    Init();
}

void C_COMMUNICATION_USB::Set_Cadre(C_CADRE* P_Cadre){
    Le_Cadre=P_Cadre;
}

bool C_COMMUNICATION_USB::Get_Etat_Carte(){
    return Etat_carte;
}

void C_COMMUNICATION_USB::Set_Mode_Lecture(bool P_Autorisation){
    Mode_Lecture_USB=P_Autorisation;
}

bool C_COMMUNICATION_USB::Get_Mode_Lecture(){
    return Mode_Lecture_USB;
}

void C_COMMUNICATION_USB::Affiche_Erreur() {
    DWORD L_Code_Erreur = GetLastError();

    char L_Message[512];

    FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, L_Code_Erreur,
            0, (LPWSTR) L_Message, 511, NULL);
    cerr << " -Erreur [" << L_Code_Erreur << "]   :  " << L_Message << endl;
}

void C_COMMUNICATION_USB::Init() {
    strcpy(Nom_Port_COM, "COM5");
    hCom = CreateFileA(Nom_Port_COM, //le nom du port dans lequel on veut rediriger le flux
            GENERIC_READ | GENERIC_WRITE, //On va pouvoir lire et écrie
            0, //le port dois etre ouvert en acces exclusif
            NULL, // pas d'attribut de sécurité
            OPEN_EXISTING, // un port COM doit etre ouvert en OPEN_EXISTING
            0, // not overlapped I/O
            NULL // le hTemplate dois etre en NULL pour un port com
            );
    if (hCom == INVALID_HANDLE_VALUE) {
        Affiche_Erreur();
        Etat_carte = false;
    } else {
        Connection_Reussie = GetCommState(hCom, &dcb);

        if (!Connection_Reussie) {
            Affiche_Erreur();
            Etat_carte = false;
        } else {
            dcb.BaudRate = CBR_9600; // baud rate
            dcb.ByteSize = 8; // taille de la data
            dcb.Parity = NOPARITY; // pas de bit de parité
            dcb.StopBits = ONESTOPBIT; // un bit de stop

            Connection_Reussie = SetCommState(hCom, &dcb);
            if (!Connection_Reussie)Affiche_Erreur();
            else {
                Etat_carte = true;
            }
        }
    }
//    Le_Cadre->Set_Etat_Carte(Etat_carte);
}

