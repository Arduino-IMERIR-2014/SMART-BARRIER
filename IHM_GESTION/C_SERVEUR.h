/* 
 * File:   C_SERVEUR.h
 * Author: Nicolas
 *
 * Created on 14 décembre 2014, 20:23
 */

#ifndef _C_SERVEUR_H
#define	_C_SERVEUR_H

#include "ui_C_SERVEUR.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QDialog>
#include <QString>
#include <QMessageBox>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QTime>
#include <QHeaderView>
#include <QSqlQuery>
#include "COMMANDE.h"


class C_SERVEUR : public QMainWindow {
    Q_OBJECT
    
public:
    C_SERVEUR();
    void Envoyer_commande(int Commande);
    char *buffer;
private:
    Ui::C_SERVEUR widget;
 
    protected:
    QTcpServer *serveur;
    QTcpSocket *socket;
    QByteArray donnees;
    bool client_connect;
    QSqlDatabase bdd_info_client;
    QSqlDatabase bdd_parking;
    QSqlTableModel *model_client;
    QSqlTableModel * model_parking;
    QTableView *vue_info_client;
    QTableView *vue_info_parking;
    
   
    void Initialiser_bdd_info_client();
    void Initialiser_bdd_parking();
    void Parametre_fenetre();
    void Parametre_parking();
    
public slots:

    void Nouvelle_connexion();
    void Donnees_recues();
    void Mode_manuel();
    void Mode_Automatique();
    void Active_led_portail();
    void Desactive_led_portail();
    void Active_moteur();
    void Desactive_moteur();
    void Active_buzzer();
    void Desactive_buzzer();
    void Active_led_flash();
    void Desactive_led_flash();
    void Ajouter_client();
    void Rechercher_client();
    void Deconnexion_client();
    void Creer_vue_info();
    void Creer_vue_parking();
    void Supprimer_client();
    void Mettre_majuscule();
    void Demande_etat_bouton();
    void Demande_etat_capteur_lumiere();
    void Reset();
};

#endif	/* _C_SERVEUR_H */
