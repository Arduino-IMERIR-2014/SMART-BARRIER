/*
 * File:   main.cpp
 * Author: Ttibo
 *
 * Created on 11 décembre 2014, 08:19
 */

#include <QApplication>

#include "C_CADRE.h"
#include "C_COMMUNICATION_USB.h"
#include "C_COMMUNICATION_USB_ECRIRE.h"
#include "C_COMMUNICATION_USB_LIRE.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    C_CADRE le_cadre;
    le_cadre.show();
    C_COMMUNICATION_USB::Get_Instance()->Set_Cadre(&le_cadre);

    C_COMMUNICATION_USB_LIRE la_com_lire;
    la_com_lire.Demmares_Toi();
        C_COMMUNICATION_USB_ECRIRE la_com_ecrire;
    la_com_ecrire.Demmares_Toi();
    
    // create and show your widgets here

    return app.exec();
}
