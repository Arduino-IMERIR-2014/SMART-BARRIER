/**
 * \file C_SERVEUR.h
 * \brief Entête
 * \author Nicolas.D
 * \version 1.0
 * \date 07 Janvier 2015
 */

#ifndef _C_SERVEUR_H
#define	_C_SERVEUR_H

#include "ui_C_SERVEUR.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QDialog>
#include <QString>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QTime>
#include <QTimer>
#include <QHeaderView>
#include <QSqlQuery>
#include <ctime>
#include <time.h>
#include <string>
#include "COMMANDE.h"
#include <iostream>


  /*! \class C_SERVEUR
   * \brief Classe representant la fenetre principale.La classe gere le serveur et les bases de données.
   */

class C_SERVEUR : public QMainWindow {
    Q_OBJECT
    
public:
    
     /*!
     *  \brief Constructeur de la classe C_SERVEUR.
     *  Constructeur de la classe C_SERVEUR qui initialise et connecte le serveur.
     *  Initialise également les bases de données des clients et du parking.
     */
    C_SERVEUR();
    /**
 * \brief Methode permettant d'envoyer les commandes à l'arduino.
 *
 * \param Commande Entier représentant la commande à réaliser.
 */
    void Envoyer_commande(int Commande);

private:
    Ui::C_SERVEUR widget;  /*!< Objet de la classe Ui_C_SERVEUR permettant de mettre en place tous
                            *   les widgets et composants graphiques. */
 
    protected:
    QTcpServer *serveur;   /*!< Objet représentant le serveur. */
    QTcpSocket *socket;    /*!< Objet réprésentant la socket de connection. */
    QByteArray donnees;    /*!< Objet représentant les données reçues par le client. */
    bool client_connect;   /*!< Booleen permettant de savoir si un client est connect. */
    QSqlDatabase bdd_info_client;   /*!< Objet permettant de se connecter à la base de donnée des clients. */
    QSqlDatabase bdd_parking;       /*!< Objet permettant de se connecter à la base de donnée du parking. */
    QSqlTableModel *model_client;   /*!< Objet permettant de représenter la base client sous forme de tableau. */
    QSqlTableModel * model_parking; /*!< Objet permettant de représenter la base parking sous forme de tableau. */
    QTableView *vue_info_client;    /*!< Objet permettant d'afficher la base de donnée client. */
    QTableView *vue_info_parking;   /*!< Objet permettant d'afficher la base de donnée parking.t */
    QTimer timer;
    QString Horaire_du_jour;
    QByteArray options_parking;
    QString Places_parking;
    char buff_date[50];
    char buff_heure[20];
    struct tm date;
    time_t temps;
    int jour=99;
    int heure=0;
    int Total_place_dispo;
    int Nb_place_voiture_total;
    int Nb_place_utilitaire_total;
    int Nb_place_moto_velo_total;
    int Nb_place_poid_lourd_total;
    int Nb_place_total;
    int Nb_place_voiture_presente;
    int Nb_place_utilitaire_present;
    int Nb_place_moto_velo_present;
    int Nb_place_poid_lourd_present;
    QTimer timer1;
    bool ok;
 /**
 * \brief Methode permettant de se connecter à la base de donnée client. 
 */  
    void Initialiser_bdd_info_client();
    
 /**
 * \brief Methode permettant de se connecter à la base de donnée parking. 
 */   
    void Initialiser_bdd_parking();
    
 /**
 * \brief Methode ajoutant des contraintes sur la saisi des numéros clients. 
 */  
    void Parametre_fenetre();
    
    void Requette_horaire();
    
    void Requette_modif_bdd_parking(int choix);
    
    void Initialisation_timer();
    
    void Passage_vehicule_MAJ_BDD(QString passage);
    
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
    void Affichage_horaire_date();
    void Requete_affiche_options_parking();
    void Affichage_options_parking(QString Requete);
    void Modification_places_parking();
    void Effacer_afficheur_accueil();
    void Effacer_afficheur_modif_donnees();
    void Effacer_afficheur_mode_manuel();
    void Effacer_afficheur_modif_bdd();
    
};

#endif	/* _C_SERVEUR_H */
