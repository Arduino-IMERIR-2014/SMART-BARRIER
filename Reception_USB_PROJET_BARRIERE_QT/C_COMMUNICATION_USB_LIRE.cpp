/* 
 * File:   C_COMMUNICATION_USB_LIRE.cpp
 * Author: Ttibo
 * 
 * Created on 11 décembre 2014, 14:53
 */

#include "C_COMMUNICATION_USB_LIRE.h"
#include <windows.h>
#include <iostream>
using namespace std;

void C_COMMUNICATION_USB_LIRE::Run() {
    while (1) {
        if (C_COMMUNICATION_USB::Get_Instance()->Etat_carte) {
            if (C_COMMUNICATION_USB::Get_Instance()->Get_Mode_Lecture()) {
                C_COMMUNICATION_USB::Get_Instance()->Set_Mode_Lecture(false);
                char texte[5];
                int nBytesToRead = 5;
                cout<<"---------------MODE LECTURE----------------"<<endl;
                ReadFile(C_COMMUNICATION_USB::Get_Instance()->hCom, texte, nBytesToRead, (PDWORD) & nBytesToRead, NULL);
                cout << "LECTURE USB : " << texte << " TAILLE : " << nBytesToRead << endl;

                C_COMMUNICATION_USB::Get_Instance()->Le_Cadre->Set_Info_Carte(atoi(texte));
            }
        } else {
            if (C_COMMUNICATION_USB::Get_Instance()->Le_Cadre->change_etat_carte) {
                C_COMMUNICATION_USB::Get_Instance()->Le_Cadre->change_etat_carte = false;
                C_COMMUNICATION_USB::Get_Instance()->Init();
            }
        }
    }
}