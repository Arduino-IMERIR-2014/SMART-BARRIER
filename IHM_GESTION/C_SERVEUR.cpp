/*
 * File:   C_SERVEUR.cpp
 * Author: Nicolas
 *
 * Created on 14 décembre 2014, 20:23
 */

#include "C_SERVEUR.h"
#include <iostream>
using namespace std;
//****************************************************************************//

C_SERVEUR::C_SERVEUR() {

    widget.setupUi(this);
    socket=NULL;
    serveur = new QTcpServer(this);
    client_connect = false;
    connect(serveur, SIGNAL(newConnection()), this, SLOT(Nouvelle_connexion()));
    
    if (!serveur->listen(QHostAddress::Any, 9999)) {
        QMessageBox::critical(0,tr("Erreur"),"Le serveur ne peut pas démarer. Raison: "+serveur->errorString());
        QString Message = "Le serveur ne peut pas démarer. Raison: ";
        Message += serveur->errorString();
        widget.listWidget->addItem(Message);

    } else {

        QString Message = "Le serveur est en route sur le port ";
        Message += QString::number(serveur->serverPort());
        widget.listWidget->addItem(Message);
    }
    Initialiser_bdd_info_client();
    Initialiser_bdd_parking();
    Parametre_fenetre();
    
}

//****************************************************************************//

void C_SERVEUR::Nouvelle_connexion() {

    if (socket == NULL) {
        socket = serveur->nextPendingConnection();
        QString Info = "Le client vient de se connecter.\n";
        widget.listWidget->addItem(Info);
    }
    
    client_connect = true;
    connect(socket, SIGNAL(readyRead()), this, SLOT(Donnees_recues()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(Deconnexion_client()));
}

//****************************************************************************//

void C_SERVEUR::Donnees_recues() {

    QString Info = "Reception des données: ";
    donnees = socket->readAll();  

    if((donnees.toInt() ==0) ||(donnees.toInt()==1)){
        widget.listWidget_3->addItem(Info);
        widget.listWidget_3->addItem(donnees+"\n");
        
    }else{
    widget.listWidget->addItem(Info);
    widget.listWidget->addItem(donnees+"\n");
    
    }

}

//****************************************************************************//

void C_SERVEUR::Envoyer_commande(int Commande) {


    if (client_connect == false) {
        QString Info = "Aucun client n'est connecté!";
        widget.listWidget->addItem(Info);
    } else {
      
        QByteArray donnees = QByteArray::number(Commande);   
        
        socket->write(donnees);
        socket->flush();
        socket->waitForBytesWritten(3000);
    }
}

//****************************************************************************//

void C_SERVEUR::Ajouter_client() {
    
    int i;
    
    if((widget.num_client->text().length()!=0)&&(widget.nom->text().length()!=0)&&(widget.prenom->text().length()!=0)
            &&(widget.voiture->isChecked())||(widget.moto_velo->isChecked())||(widget.utilitaire->isChecked())){
        
    for(i=0;i<model_client->rowCount();++i);
    
    model_client->insertRows(model_client->rowCount(), 1);
    model_client->setData(model_client->index(i, 0), widget.num_client->text());
    model_client->setData(model_client->index(i, 1), widget.nom->text());
    model_client->setData(model_client->index(i, 2), widget.prenom->text());
    model_client->setData(model_client->index(i, 3), QTime::currentTime());
    QString type_vehicule;
    
    
     foreach(QRadioButton *tous_les_boutons, findChildren<QRadioButton *>()){ //retourne tout les Qradiobutton dans tous_les_boutons
             if (tous_les_boutons->isChecked()){
                    type_vehicule = tous_les_boutons->text();
             }
     }
     
    model_client->setData(model_client->index(i, 5), type_vehicule);
    model_client->submitAll();
    
    QSqlRecord record = model_client->record(i);
    QMessageBox::information(0,QObject::tr("Information du client ajouté"),
        "Numéro du client: " + QString::number(record.value(0).toInt()) +
        "\nNom: " + record.value(1).toString() + "\nPrénom: "+record.value(2).toString()
        +"\nType véhicule: "+type_vehicule);   
    
    widget.listWidget_2->addItem("Numéro client: " +widget.num_client->text());
    widget.listWidget_2->addItem("Nom: "+widget.nom->text());
    widget.listWidget_2->addItem("Prenom: "+widget.prenom->text()+"\n");
    
    widget.num_client->clear();
    widget.nom->clear();
    widget.prenom->clear(); 
    }else
    {
           if(widget.num_client->text().length()==0){
                QMessageBox::information(0,QObject::tr("Saisi non valide"),"Veuillez saisir un numéro client.");
           }
           
           if(widget.nom->text().length()==0){
                QMessageBox::information(0,QObject::tr("Saisi non valide"),"Veuillez saisir un nom.");
           }
           
           if(widget.prenom->text().length()==0){
                QMessageBox::information(0,QObject::tr("Saisi non valide"),"Veuillez saisir un prenom.");
           }
           
           if((!widget.voiture->isChecked())||(!widget.moto_velo->isChecked())||(!widget.utilitaire->isChecked())){
               QMessageBox::information(0,QObject::tr("Selection véhicule"),"Veuillez choisir le type de véhicule");
               
           }
    }
    
}

void C_SERVEUR::Rechercher_client(){
    
    int i;
    
    QSqlRecord record; 
    record = model_client->record(0);
    
    int saisi =widget.recherche->text().toInt();
    int valeur_recup = record.value(0).toInt();
    i=0;
    
    if(widget.recherche->text().length() !=0){
    while( (saisi!=valeur_recup)&& (i<model_client->rowCount())){
        i++;
        record = model_client->record(i);
        valeur_recup = record.value(0).toInt();
    }
      
    if(saisi==valeur_recup){
        QString num = record.value(0).toString();
        QString nom =record.value(1).toString();
        QString prenom = record.value(2).toString();
   
        QMessageBox::information(0,QObject::tr("Information du client recherché"),
                "Numéro du client: " +num  +"\nNom: " + nom + "\nPrénom: "+prenom);
    
        widget.listWidget_2->addItem("Numéro client: "+num +"\nNom: " +nom +"\nPrénom: "+ prenom+"\n");
    }else{
        QMessageBox::critical(0,QObject::tr("Client non trouvé!"),"Vérifier le numéro du client.");
        widget.listWidget_2->addItem("Client "+widget.recherche->text()+" non trouvé.\n");
    }
    widget.recherche->clear();
    }else{
        QMessageBox::information(0,QObject::tr("Information"),"Vous devez saisir un numéro client.");
        
    }
}

//***********************************slots************************************//

void C_SERVEUR::Mode_Automatique() {

    Envoyer_commande(MODE_AUTOMATIQUE);
    if (client_connect == true) {
        QString Info = "Mode automatique.\n";
        widget.listWidget->addItem(Info);
    } else {
        QString Info = "Impossible d'envoyer la commande.\n";
        widget.listWidget->addItem(Info);
    }
}

void C_SERVEUR::Mode_manuel() {

    Envoyer_commande(MODE_MANUEL);
    if (client_connect == true) {
        QString Info = "Mode manuel.\n";
        widget.listWidget->addItem(Info);
    } else {
        QString Info = "Impossible d'envoyer la commande.\n";
        widget.listWidget->addItem(Info);
    }
}

void C_SERVEUR::Active_led_portail() {


    Envoyer_commande(ACTIVE_LED_PORTAIL);
    if (client_connect == true) {
        QString Info = "Commande activer led envoyee.\n";
        widget.listWidget_3->addItem(Info);
    } else {
        QString Info = "Impossible d'envoyer la commande.\n";
        widget.listWidget_3->addItem(Info);
    }
}

void C_SERVEUR::Desactive_led_portail() {


    Envoyer_commande(DESACTIVE_LED_PORTAIL);
    if (client_connect == true) {
        QString Info = "Commande desactiver led envoyee.\n";
        widget.listWidget_3->addItem(Info);
    } else {
        QString Info = "Impossible d'envoyer la commande.\n";
        widget.listWidget_3->addItem(Info);
    }
}

void C_SERVEUR::Active_moteur() {

    Envoyer_commande(ACTIVE_MOTEUR);
    if (client_connect == true) {
        QString Info = "Commande activer moteur envoyee.\n";
        widget.listWidget_3->addItem(Info);
    } else {
        QString Info = "Impossible d'envoyer la commande.\n";
        widget.listWidget_3->addItem(Info);
    }
}

void C_SERVEUR::Desactive_moteur() {

    Envoyer_commande(DESACTIVE_MOTEUR);
    if (client_connect == true) {
        QString Info = "Commande desactiver moteur envoyee.\n";
        widget.listWidget_3->addItem(Info);
    } else {
        QString Info = "Impossible d'envoyer la commande.\n";
        widget.listWidget_3->addItem(Info);
    }
}

void C_SERVEUR::Active_buzzer() {

    Envoyer_commande(ACTIVE_BUZZER);
    if (client_connect == true) {
        QString Info = "Commande activer buzzer envoyee.\n";
        widget.listWidget_3->addItem(Info);
    } else {
        QString Info = "Impossible d'envoyer la commande.\n";
        widget.listWidget_3->addItem(Info);
    }
}

void C_SERVEUR::Desactive_buzzer() {

    Envoyer_commande(DESACTIVE_BUZZER);
    if (client_connect == true) {
        QString Info = "Commande desactiver buzzer envoyee.\n";
        widget.listWidget_3->addItem(Info);
    } else {
        QString Info = "Impossible d'envoyer la commande.\n";
        widget.listWidget_3->addItem(Info);
    }
}

void C_SERVEUR::Active_led_flash() {

    Envoyer_commande(ACTIVE_LED_FLASH);
    if (client_connect == true) {
        QString Info = "Commande activer led flash envoyee.\n";
        widget.listWidget_3->addItem(Info);
    } else {
        QString Info = "Impossible d'envoyer la commande.\n";
        widget.listWidget_3->addItem(Info);
    }
}

void C_SERVEUR::Desactive_led_flash() {

    Envoyer_commande(DESACTIVE_LED_FLASH);
    if (client_connect == true) {
        QString Info = "Commande desactiver led flash envoyee.\n";
        widget.listWidget_3->addItem(Info);
    } else {
        QString Info = "Impossible d'envoyer la commande.\n";
        widget.listWidget_3->addItem(Info);
    }
}


void C_SERVEUR::Deconnexion_client(){
   
    client_connect =false;
    QString Message = "Le client vient de se déconnecter.\n";
    widget.listWidget->addItem(Message);
    socket=NULL;
    
}


void C_SERVEUR::Initialiser_bdd_info_client(){
    
    bdd_info_client = QSqlDatabase::addDatabase("QSQLITE");
    bdd_info_client.setHostName("localhost");
    bdd_info_client.setUserName("root");
    bdd_info_client.setPassword("");
    bdd_info_client.setDatabaseName("info_client");
    if(!bdd_info_client.open()){
        QString info = "Impossible de se connecter à la base de donnée 'info_client'.\n";
        info+=bdd_info_client.lastError().text();
        QMessageBox::critical(NULL, "Erreur", info);
    }else{
        QString Message = "Connexion à la base de donnée 'info_client' réusite.";
        widget.listWidget->addItem(Message); 
            model_client = new QSqlTableModel;
    model_client->setTable("client");
    model_client->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_client->select();
    model_client->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero client"));
    model_client->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model_client->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model_client->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure passage"));
    model_client->setHeaderData(4, Qt::Horizontal, QObject::tr("Qr code"));
    model_client->setHeaderData(5, Qt::Horizontal, QObject::tr("Type véhicule"));
    model_client->setHeaderData(6, Qt::Horizontal, QObject::tr("Temps stationnement"));
    model_client->setHeaderData(7, Qt::Horizontal, QObject::tr("Type véhicule"));
    
    
    
    }
}

void C_SERVEUR::Creer_vue_info(){
     
    vue_info_client = new QTableView;
     QHeaderView* headerView = new QHeaderView(Qt::Horizontal);
    vue_info_client->setModel(model_client);
    vue_info_client->setWindowTitle("Base de donnée informations clients");
    vue_info_client->setMinimumSize(780,400);
    vue_info_client->setAlternatingRowColors(true);
    vue_info_client->setEditTriggers(QAbstractItemView::NoEditTriggers);
    vue_info_client->resizeColumnToContents(7);
   
    /*header sont adapté à la taille de la fenêtre impossible de redimentionner la largeur*/
    headerView->setSectionResizeMode(QHeaderView::Stretch);
    vue_info_client->setHorizontalHeader(headerView);

    vue_info_client->verticalHeader()->hide();
    
    vue_info_client->show();
}

void C_SERVEUR::Supprimer_client(){
    
    int i;
    
    QSqlRecord record; 
    record = model_client->record(0);
    
    int saisi =widget.supp_2->text().toInt();
    int valeur_recup = record.value(0).toInt();
    i=0;
    
    if(widget.supp_2->text().length() !=0){
    while( (saisi!=valeur_recup)&& (i<model_client->rowCount())){
        i++;
        record = model_client->record(i);
        valeur_recup = record.value(0).toInt();
    }
      
    if(saisi==valeur_recup){
        QString num = record.value(0).toString();
        QString nom =record.value(1).toString();
        QString prenom = record.value(2).toString();
   
        QMessageBox::information(0,QObject::tr("Information du client supprimé"),
                "Numéro du client: " +num  +"\nNom: " + nom + "\nPrénom: "+prenom);
    
        widget.listWidget_2->addItem("Numéro client: "+num +"\nNom: " +nom +"\nPrénom: "+ prenom+"\n");
        model_client->removeRow(i);
        model_client->submitAll();
    }else{
        QMessageBox::critical(0,QObject::tr("Client non trouvé!"),"Vérifier le numéro du client.");
        widget.listWidget_2->addItem("Client "+widget.supp_2->text()+" non trouvé.\n");
    }
    widget.supp_2->clear();
    }else{
        QMessageBox::information(0,QObject::tr("Information"),"Vous devez saisir un numéro client.");
        
    }
 

    
}


void C_SERVEUR::Parametre_fenetre(){
    
    QString Info1 = "Historique des modifications:\n";
    QString Info2 = "Historique des commandes envoyées:\n";
    widget.listWidget_2->addItem(Info1);
    widget.listWidget_3 ->addItem(Info2);
    widget.recherche->setValidator(new QIntValidator(1, 999999));
    widget.num_client->setValidator(new QIntValidator(1, 999999));
    widget.supp_2->setValidator(new QIntValidator(1, 999999));
    
  
}

void C_SERVEUR::Mettre_majuscule(){
    
    QString Nom =widget.nom->text();
     if((Nom.length()==1) && (Nom != Nom.toUpper()))    {
        
        widget.nom->setText(widget.nom->text().toUpper());

    }
    
     QString Prenom =widget.prenom->text();
     if((Prenom.length()==1) && (Prenom != Prenom.toUpper()))    {
        
        widget.prenom->setText(widget.prenom->text().toUpper());

    }
}

void C_SERVEUR::Initialiser_bdd_parking(){
    
    bdd_parking = QSqlDatabase::addDatabase("QSQLITE");
    bdd_parking.setHostName("localhost");
    bdd_parking.setUserName("root");
    bdd_parking.setPassword("");
    bdd_parking.setDatabaseName("parametre_parking");
    if(!bdd_parking.open()){
        QString info = "Impossible de se connecter à la base de donnée 'parametre_parking'.\n";
        info+=bdd_parking.lastError().text();
        QMessageBox::critical(NULL, "Erreur", info);
    }else{
        QString Message = "Connexion à la base de donnée 'parametre_parking' réusite.\n";
        widget.listWidget->addItem(Message); 
            model_parking = new QSqlTableModel;
    model_parking->setTable("parametres");
    model_parking->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_parking->select();
    model_parking->setHeaderData(0, Qt::Horizontal, QObject::tr("Nombre place totale"));
    model_parking->setHeaderData(1, Qt::Horizontal, QObject::tr("Disponible"));
    model_parking->setHeaderData(2, Qt::Horizontal, QObject::tr("Horaire"));
    
    //récupération donnée place parking
    QSqlRecord record; 
    record = model_parking->record(0);
    
    
    
    }
}

void C_SERVEUR::Creer_vue_parking(){
    
    vue_info_parking = new QTableView;
    QHeaderView* headerView = new QHeaderView(Qt::Horizontal);
    QHeaderView* headerView1 = new QHeaderView(Qt::Vertical);
    
    vue_info_parking->setModel(model_parking);
    vue_info_parking->setWindowTitle("Base de donnée informations parking");
    vue_info_parking->setMinimumSize(600,200);
    vue_info_parking->setAlternatingRowColors(true);
    vue_info_parking->setEditTriggers(QAbstractItemView::NoEditTriggers);

    
    vue_info_parking->verticalHeader()->resizeSections(QHeaderView::Stretch);
    /*header sont adapté à la taille de la fenêtre impossible de redimentionner la largeur*/
    headerView->setSectionResizeMode(QHeaderView::Stretch);
    
    vue_info_parking->verticalHeader()->resizeSections(QHeaderView::Stretch);
    
    vue_info_parking->setHorizontalHeader(headerView);
    vue_info_parking->verticalHeader()->hide();
    
    vue_info_parking->show();
    
}

void C_SERVEUR::Demande_etat_bouton(){
    
    Envoyer_commande(ETAT_BOUTON);
    
}

void C_SERVEUR::Demande_etat_capteur_lumiere(){
    
    Envoyer_commande(ETAT_CAPTEUR_LUMIERE);
}

void C_SERVEUR::Reset(){
    Envoyer_commande(RESET);
    
}

