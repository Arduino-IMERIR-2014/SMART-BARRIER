/*
 * File:   main.cpp
 * Author: Nicolas
 *
 * Created on 14 décembre 2014, 20:22
 */


//gestion qrcode et affichage image caméra place restante  calcul des durées et cout definition horaire acces
#include <QApplication>
#include "C_SERVEUR.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    C_SERVEUR Le_serveur;
    Le_serveur.show();

    return app.exec();
}
