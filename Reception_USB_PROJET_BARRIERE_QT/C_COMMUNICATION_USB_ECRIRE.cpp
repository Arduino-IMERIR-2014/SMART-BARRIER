/* 
 * File:   C_COMMUNICATION_USB_ECRIRE.cpp
 * Author: Ttibo
 * 
 * Created on 11 décembre 2014, 14:57
 */

#include "C_COMMUNICATION_USB_ECRIRE.h"
#include <iostream>
using namespace std;

void C_COMMUNICATION_USB_ECRIRE::Run() {
    C_COMMUNICATION_USB::Get_Instance()->Le_Cadre->Set_Etat_Carte(C_COMMUNICATION_USB::Get_Instance()->Get_Etat_Carte());
    while (1) {
        if (C_COMMUNICATION_USB::Get_Instance()->Etat_carte) {
            if (C_COMMUNICATION_USB::Get_Instance()->Le_Cadre->ecrire) {
                C_COMMUNICATION_USB::Get_Instance()->Le_Cadre->ecrire = false;
//                bool ok = true;
                int nByteToWrite = C_COMMUNICATION_USB::Get_Instance()->Le_Cadre->Message_Ecrire.size();
                cout << "ECRITURE USB : " << C_COMMUNICATION_USB::Get_Instance()->Le_Cadre->Message_Ecrire.toStdString() << " TAILLE : " << nByteToWrite << endl;
                if (WriteFile(C_COMMUNICATION_USB::Get_Instance()->hCom, C_COMMUNICATION_USB::Get_Instance()->Le_Cadre->Message_Ecrire.toStdString().c_str(), nByteToWrite, (PDWORD) & nByteToWrite, NULL) != 0) {
                    C_COMMUNICATION_USB::Get_Instance()->Affiche_Erreur();
                }
                if((C_COMMUNICATION_USB::Get_Instance()->Le_Cadre->Message_Ecrire.toInt() == 11) || (C_COMMUNICATION_USB::Get_Instance()->Le_Cadre->Message_Ecrire.toInt() == 12)){
                    C_COMMUNICATION_USB::Get_Instance()->Set_Mode_Lecture(true);
                }
            }
        }
    }
}