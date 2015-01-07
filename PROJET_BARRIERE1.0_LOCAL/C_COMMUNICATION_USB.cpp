/* 
 * File:   C_ENVOI_USB.cpp
 * Author: Ttibo
 * 
 * Created on 9 décembre 2014, 16:15
 */

#include "C_COMMUNICATION_USB.h"
#include <SoftwareSerial.cpp>
#include "DEFINE.h"
void C_COMMUNICATION_USB::Init() {
    Mon_Serial = new SoftwareSerial(0, 1);
    Mon_Serial->begin(9600);
}

void C_COMMUNICATION_USB::Envoi(int msg) {
#ifdef DEBUG_COM_USB
    Ecran->Affiche("Envoye");
#endif
    Mon_Serial->print(msg);
}

String C_COMMUNICATION_USB::Reception() {
    if (Mon_Serial->available()) {//il y a des choses a lire
        Message = Mon_Serial->readString();
    }
    else Message = "0";
    return Message;
}
