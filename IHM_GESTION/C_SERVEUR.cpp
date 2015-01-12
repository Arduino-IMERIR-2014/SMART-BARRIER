/*
 * File:   C_SERVEUR.cpp
 * Author: Nicolas
 *
 * Created on 14 décembre 2014, 20:23
 */

#include "C_SERVEUR.h"

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
    
    //connecte les signaux pour les timer
    Initialisation_timer();
    Requete_affiche_options_parking();   
    
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
    QString compare_donnee_recu;
    string compare_entree("entree");
    string compare_sortie ("sortie");
    donnees = socket->readAll();  
    compare_donnee_recu = donnees.left(6);
    
    if((compare_entree.compare(compare_donnee_recu.toStdString())==0)||(compare_sortie.compare(compare_donnee_recu.toStdString())==0)){
        Passage_vehicule_MAJ_BDD(compare_donnee_recu);
        
    }else{
    
        if((donnees.toInt() ==0) ||(donnees.toInt()==1)){
            widget.listWidget_3->addItem(Info);
            widget.listWidget_3->addItem(donnees+"\n");
        
        }else{
            widget.listWidget->addItem(Info);
            widget.listWidget->addItem(donnees+"\n");
    
        }
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
    
    if(((widget.num_client->text().length()!=0)&&(widget.nom->text().length()!=0)&&(widget.prenom->text().length()!=0)
            &&(widget.voiture->isChecked()))||((widget.moto_velo->isChecked())||(widget.utilitaire->isChecked())||(widget.poids_lourd->isChecked()!=0))){
        
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
           
           if((!widget.voiture->isChecked())||(!widget.moto_velo->isChecked())||(!widget.utilitaire->isChecked())||(!widget.poids_lourd->isChecked())){
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
    
    widget.listWidget_2->addItem("Historique des modifications:\n");
    widget.listWidget_3 ->addItem("Historique des commandes envoyées:\n");
    widget.listWidget_4->addItem("Historique des modifications:\n");
    widget.recherche->setValidator(new QIntValidator(1, 999999));
    widget.num_client->setValidator(new QIntValidator(1, 999999));
    widget.supp_2->setValidator(new QIntValidator(1, 999999));
    widget.modif_place_voiture->setValidator(new QIntValidator(1, 999999));
    widget.modif_place_motos_velos->setValidator(new QIntValidator(1, 999999));
    widget.modif_place_poidslourd->setValidator(new QIntValidator(1, 999999));
    widget.modif_place_utilitaire->setValidator(new QIntValidator(1, 999999));
    widget.modif_total->setValidator(new QIntValidator(1, 999999));
  
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
        model_client->setHeaderData(5, Qt::Horizontal, QObject::tr("Catégorie véhicule"));
        model_client->setHeaderData(6, Qt::Horizontal, QObject::tr("Temps stationnement"));
    }
}

void C_SERVEUR::Creer_vue_info(){
     
    vue_info_client = new QTableView;
     QHeaderView* headerView = new QHeaderView(Qt::Horizontal);
    vue_info_client->setModel(model_client);
    vue_info_client->setWindowTitle("Base de donnée informations clients");
    vue_info_client->setMinimumSize(850,400);
    vue_info_client->setAlternatingRowColors(true);
    vue_info_client->setEditTriggers(QAbstractItemView::NoEditTriggers);
   
    /*header sont adapté à la taille de la fenêtre impossible de redimentionner la largeur*/
    headerView->setSectionResizeMode(QHeaderView::Stretch);
    vue_info_client->setHorizontalHeader(headerView);

    vue_info_client->verticalHeader()->hide();
    
    vue_info_client->show();
}

void C_SERVEUR::Initialiser_bdd_parking(){
    
    model_parking = new QSqlTableModel;
    model_parking->setTable("parametres");
    model_parking->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model_parking->select();
    model_parking->setHeaderData(0, Qt::Horizontal, QObject::tr("Catégorie véhicule"));
    model_parking->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre places totale"));
    model_parking->setHeaderData(2, Qt::Horizontal, QObject::tr("Disponible"));
    model_parking->setHeaderData(3, Qt::Horizontal, QObject::tr("Horaire"));        

     
}

void C_SERVEUR::Creer_vue_parking(){
    
    vue_info_parking = new QTableView;
    QHeaderView* headerView = new QHeaderView(Qt::Horizontal);
    
    vue_info_parking->setModel(model_parking);
    vue_info_parking->setWindowTitle("Base de donnée informations parking");
    vue_info_parking->setMinimumSize(600,250);
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


void C_SERVEUR::Affichage_horaire_date(){
    
    QSqlQuery Requete;
    
    time(&temps);
    date =*localtime(&temps);
    
    if(date.tm_wday != jour){
   
        //affiche date
        strftime(buff_date, 50, "%A %d\\%m\\%y\n", &date);
        widget.horaire_date->clear();
        widget.horaire_date->addItem(buff_date);
        
        //affiche horaire dans BDD
        Requette_horaire();
        
        QString horaire ="Horaire: ";
        horaire +=" "+Horaire_du_jour;
        widget.horaire_date->addItem(horaire);
        jour = date.tm_wday;
        
    }
   
    if(date.tm_sec != heure){
     
        strftime(buff_heure, 20, "%X", &date);
        widget.heure->clear();
        widget.heure->addItem(buff_heure);
        heure = date.tm_sec;
    }
    
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

void C_SERVEUR::Requette_horaire(){
    
    QSqlQuery Requete;
    
    QString query = "SELECT Horaire FROM parametres where jour=";
    
    query += QString::number(date.tm_wday);
    
    if(Requete.exec(query)){
        
        while (Requete.next()) {
             Horaire_du_jour = Requete.value(0).toString();
        } 

    }else{
        widget.listWidget->addItem(Requete.lastError().text());
        QMessageBox::critical(0,QObject::tr("Horaire indisponible: erreur!"),"Erreur lors de ma récupération des horaires dans la base de données.");

    }
}

void C_SERVEUR::Requete_affiche_options_parking(){
      
    QString Requete; 
    Total_place_dispo = 0;

    Requete ="SELECT Nb_places_total FROM parametres WHERE Catégorie_véhicule ='Voiture'";
    Affichage_options_parking(Requete);
    widget.p_veh_legers_total->clear();
    widget.p_veh_legers_total->addItem(Places_parking);
    Nb_place_voiture_total = Places_parking.toInt();
    Requete.clear();

    Requete ="SELECT Nb_places_total FROM parametres WHERE Catégorie_véhicule ='Moto/Vélo'";
    Affichage_options_parking(Requete);
    widget.moto_velo_total->clear();
    widget.moto_velo_total->addItem(Places_parking);
    Nb_place_moto_velo_total = Places_parking.toInt();
    Requete.clear();
    
    Requete ="SELECT Nb_places_total FROM parametres WHERE Catégorie_véhicule ='Utilitaire'";
    Affichage_options_parking(Requete);
    widget.p_veh_utilitaire_total->clear();
    widget.p_veh_utilitaire_total->addItem(Places_parking);
    Nb_place_utilitaire_total =Places_parking.toInt();
    Requete.clear();
    
    Requete ="SELECT Nb_places_total FROM parametres WHERE Catégorie_véhicule ='Poids-lourd'";
    Affichage_options_parking(Requete);
    widget.poid_lourd_total->clear();
    widget.poid_lourd_total->addItem(Places_parking);
    Nb_place_poid_lourd_total =Places_parking.toInt();
    Requete.clear();
 
    Requete ="SELECT Nb_places_total FROM parametres WHERE Catégorie_véhicule ='Total'";
    Affichage_options_parking(Requete);
    widget.total->clear();
    widget.total->addItem(Places_parking);
    Nb_place_total =Places_parking.toInt();
    Requete.clear();
    
    Requete ="SELECT Disponible FROM parametres WHERE Catégorie_véhicule ='Voiture'";
    Affichage_options_parking(Requete);
    widget.p_veh_legers_dispo->clear();
    widget.p_veh_legers_dispo->addItem(Places_parking);
    Total_place_dispo= Total_place_dispo+Places_parking.toInt();
    Nb_place_voiture_presente =Nb_place_voiture_total -Places_parking.toInt();
    Requete.clear();
   
    Requete ="SELECT Disponible FROM parametres WHERE Catégorie_véhicule ='Moto/Vélo'";
    Affichage_options_parking(Requete);
    widget.moto_velo_dispo->clear();
    widget.moto_velo_dispo->addItem(Places_parking);
    Total_place_dispo=Total_place_dispo+Places_parking.toInt();
    Nb_place_moto_velo_present = Nb_place_moto_velo_total-Places_parking.toInt();
    Requete.clear();    
    
    Requete ="SELECT Disponible FROM parametres WHERE Catégorie_véhicule ='Utilitaire'";
    Affichage_options_parking(Requete);
    widget.p_veh_utilitaire_dispo->clear();
    widget.p_veh_utilitaire_dispo->addItem(Places_parking);
    Total_place_dispo=Total_place_dispo+Places_parking.toInt();
    Nb_place_utilitaire_present = Nb_place_utilitaire_total-Places_parking.toInt();
    Requete.clear();

    Requete ="SELECT Disponible FROM parametres WHERE Catégorie_véhicule ='Poids-lourd'"; 
    Affichage_options_parking(Requete);
    widget.poid_lourd_dispo->clear();
    widget.poid_lourd_dispo->addItem(Places_parking);
    Total_place_dispo=Total_place_dispo+Places_parking.toInt();
    Nb_place_poid_lourd_present = Nb_place_poid_lourd_total-Places_parking.toInt();
    Requete.clear();
    
    widget.total_dispo->clear();
    widget.total_dispo->addItem(QString::number(Total_place_dispo));
    
}

void C_SERVEUR::Affichage_options_parking(QString Requete){
    
    QSqlQuery Requete_exec;
        if(Requete_exec.exec(Requete)){
        
        while (Requete_exec.next()) {
             Places_parking = Requete_exec.value(0).toString();
        } 

    }else{
        widget.listWidget->addItem(Requete_exec.lastError().text());
        QMessageBox::critical(0,QObject::tr("Horaire indisponible: erreur!"),"Erreur lors de ma récupération des places du parking dans la base de données.");

    }
    
}

void C_SERVEUR::Initialisation_timer(){
    
    connect(&timer,SIGNAL(timeout()),this,SLOT(Affichage_horaire_date()));
    timer.start(1000);
}

void C_SERVEUR::Passage_vehicule_MAJ_BDD(QString passage){

    QSqlQuery Requete_exec;
    QSqlRecord record;
    QString Categorie_vehicule;
    QString num_client_recupere;
    QString requete_1;
    int Place_vehicule,i;
    i=0;
    num_client_recupere = donnees.mid(6);
    //recherche catégorie véhicule
    
    requete_1 = "SELECT Catégorie_véhicule FROM client WHERE Numéro_client=";
    requete_1 +=num_client_recupere;
    
    if(Requete_exec.exec(requete_1)){
        while (Requete_exec.next()) {
             Categorie_vehicule = Requete_exec.value(0).toString();
        }        

    // recherche nb places dipo du véhicule en question pour décrémenter
        
    QString Requete_2 = "SELECT Disponible FROM parametres WHERE Catégorie_véhicule=";
    Requete_2 +="'"+Categorie_vehicule+"'";
     
     if(Requete_exec.exec(Requete_2)){
        while(Requete_exec.next()){
            Place_vehicule = Requete_exec.value(0).toInt();
        }
    
        QString Requete_3 = "UPDATE 'parametres' SET Disponible=";
        
        if(passage.compare("entree")==0){
            Requete_3 +=QString::number(Place_vehicule-1);
            widget.listWidget->addItem("Entrée véhicule, information client:");
        }else{
            Requete_3 +=QString::number(Place_vehicule+1);
            widget.listWidget->addItem("Sortie véhicule, information client:");
        }
        Requete_3 +=" WHERE Catégorie_véhicule=";
        Requete_3 +="'"+Categorie_vehicule+"'";
        
        if(Requete_exec.exec(Requete_3)){
           
            Initialiser_bdd_parking();
            QString num_client;
            num_client = record.value(0).toString();
            while( (num_client!=num_client_recupere)&& (i<model_client->rowCount())){
                i++;
                record = model_client->record(i);
                num_client = record.value(0).toString();
            }
            
            QString num = record.value(0).toString();
            QString nom =record.value(1).toString();
            QString prenom = record.value(2).toString();
            QString cate = record.value(5).toString();            
            widget.listWidget->addItem("Numéro client: "+num +"\nNom: " +nom +"\nPrénom: "+ prenom+"\n" +"Catégorie véhicule: "+cate+"\n");
            Requete_affiche_options_parking();
        }else{
            widget.listWidget->addItem(Requete_exec.lastError().text());            
        }
        
    }else{
        widget.listWidget->addItem(Requete_exec.lastError().text());
        
    }
     
    }else{
        widget.listWidget->addItem(Requete_exec.lastError().text());
        
    }

}


void C_SERVEUR::Modification_places_parking(){
    
    int choix;
    
    if((widget.modif_place_voiture->text().length()==0)&&(widget.modif_place_utilitaire->text().length()==0)
            &&(widget.modif_place_motos_velos->text().length() ==0)&&(widget.modif_place_poidslourd->text().length()==0)
            &&(widget.modif_total->text().length()==0)){
        
        QMessageBox::information(0,QObject::tr("Modification places"),"Aucune données n'a été saisie.");
        
    }else{
        
        if((widget.modif_place_voiture->text().length()!=0)&&(Nb_place_voiture_presente<widget.modif_place_voiture->text().toInt())){
            choix =1;
            Requette_modif_bdd_parking(choix);  
            QMessageBox::information(0,QObject::tr("Modification places"),"Vous venez de modifier le nombre total de place pour les voitures à "+widget.modif_place_voiture->text());
            widget.listWidget_4->addItem("Modification place total du nombre de voiture à: "+widget.modif_place_voiture->text());           
            
        }else{
            if(widget.modif_place_voiture->text().length()!=0){
                QMessageBox::critical(0,tr("Erreur"),"Impossible de saisir un nombre de place de voiture inférieure au nombre de voiture déjà présente.");
            }
        } 
        
        
        if((widget.modif_place_motos_velos->text().length()!=0)&&(Nb_place_moto_velo_present<widget.modif_place_motos_velos->text().toInt())){
            QMessageBox::information(0,QObject::tr("Modification places"),"Vous venez de modifier le nombre total de place pour les motos et vélos à "+widget.modif_place_motos_velos->text());
        }else{
            if(widget.modif_place_motos_velos->text().length()!=0){
                QMessageBox::critical(0,tr("Erreur"),"Impossible de saisir un nombre de place de motos et vélos inférieure au nombre de motos et vélos déjà présente.");
            }
        }   
        
        if((widget.modif_place_utilitaire->text().length()!=0)&&(Nb_place_utilitaire_present<widget.modif_place_utilitaire->text().toInt())){
            QMessageBox::information(0,QObject::tr("Modification places"),"Vous venez de modifier le nombre total de place pour les utilitaires à "+widget.modif_place_utilitaire->text());
        }else{
            if(widget.modif_place_utilitaire->text().length()!=0){
                QMessageBox::critical(0,tr("Erreur"),"Impossible de saisir un nombre de place d'utilitaires inférieure au nombre d'utilitaires déjà présente.");
            }
        }   
        
        
        if((widget.modif_place_poidslourd->text().length()!=0)&&(Nb_place_poid_lourd_present<widget.modif_place_poidslourd->text().toInt())){
            QMessageBox::information(0,QObject::tr("Modification places"),"Vous venez de modifier le nombre total de place pour les poids lourd à "+widget.modif_place_poidslourd->text());
        }else{
            if(widget.modif_place_poidslourd->text().length()!=0){
                QMessageBox::critical(0,tr("Erreur"),"Impossible de saisir un nombre de place de poids lourd inférieure au nombre de poids lourd déjà présente.");
            }
        }   
        
        
        if((widget.modif_total->text().length()!=0)&&(Nb_place_total<widget.modif_total->text().toInt())){
            QMessageBox::information(0,QObject::tr("Modification places"),"Vous venez de modifier le nombre total de place du parking à "+widget.modif_total->text());
        }else{
            if(widget.modif_total->text().length()!=0){
                QMessageBox::critical(0,tr("Erreur"),"Impossible de saisir un nombre de place total inférieure au nombre de véhicule déjà présente.");
            }
        }   
    }
    widget.modif_place_voiture->clear();
    widget.modif_place_motos_velos->clear();
    widget.modif_place_utilitaire->clear();
    widget.modif_place_poidslourd->clear();
    widget.modif_total->clear();
    
}

void C_SERVEUR::Effacer_afficheur_accueil(){
    
    widget.listWidget->clear();
    widget.listWidget->addItem("Historique des modifications:\n");
    
    
}

void C_SERVEUR::Effacer_afficheur_modif_donnees(){
    
    widget.listWidget_2->clear();
    widget.listWidget_2->addItem("Historique des modifications:\n");
}

void C_SERVEUR::Effacer_afficheur_modif_bdd(){
    
    widget.listWidget_4->clear();
    widget.listWidget_4->addItem("Historique des modifications:\n");
}

void C_SERVEUR::Effacer_afficheur_mode_manuel(){
    
    widget.listWidget_3 ->clear();
    widget.listWidget_3 ->addItem("Historique des commandes envoyées:\n");
}

void C_SERVEUR::Requette_modif_bdd_parking(){

    QSqlQuery Requete_exec;
    QString Requete;    
    
    Requete ="UPDATE 'parametres' SET NB_places_total=";
    Requete+=widget.modif_place_voiture->text();
    Requete+=" ";
    Requete+="WHERE Catégorie_véhicule ='Voiture'";
    
    if(Requete_exec.exec(Requete)){
        
        Requete.clear();
    }else{
        widget.listWidget->addItem(Requete_exec.lastError().text());
        QMessageBox::critical(0,tr("Erreur"),"La requete ne peut pas être exécuté. Raison: "+Requete_exec.lastError().text());
    }
}