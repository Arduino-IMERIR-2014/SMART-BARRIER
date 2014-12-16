/********************************************************************************
** Form generated from reading UI file 'C_SERVEUR.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_SERVEUR_H
#define UI_C_SERVEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_C_SERVEUR
{
public:
    QAction *actionQuitter;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *quitter;
    QPushButton *mode_auto;
    QPushButton *mode_manu;
    QPushButton *aff_bdd;
    QListWidget *listWidget;
    QGroupBox *groupBox_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QListWidget *p_veh_legers;
    QListWidget *p_veh_lourds;
    QListWidget *total;
    QLabel *label_5;
    QListWidget *total_2;
    QLabel *label_6;
    QListWidget *total_3;
    QGroupBox *groupBox_7;
    QPushButton *aff_bdd_2;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QLineEdit *recherche;
    QPushButton *rech_client;
    QGroupBox *groupBox_3;
    QPushButton *supp;
    QLineEdit *supp_2;
    QGroupBox *groupBox_2;
    QPushButton *ajout;
    QLineEdit *num_client;
    QLineEdit *nom;
    QLineEdit *prenom;
    QLabel *label_7;
    QRadioButton *voiture;
    QRadioButton *moto_velo;
    QRadioButton *utilitaire;
    QListWidget *listWidget_2;
    QWidget *tab_3;
    QListWidget *listWidget_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QWidget *tab_5;
    QWidget *tab_4;
    QMenuBar *menubar;
    QMenu *menu_Fichier;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *C_SERVEUR)
    {
        if (C_SERVEUR->objectName().isEmpty())
            C_SERVEUR->setObjectName(QStringLiteral("C_SERVEUR"));
        C_SERVEUR->setWindowModality(Qt::NonModal);
        C_SERVEUR->resize(775, 600);
        C_SERVEUR->setMinimumSize(QSize(775, 600));
        C_SERVEUR->setAutoFillBackground(false);
        actionQuitter = new QAction(C_SERVEUR);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralwidget = new QWidget(C_SERVEUR);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("font: 16pt \"Courier\";"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setAutoFillBackground(true);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        quitter = new QPushButton(tab);
        quitter->setObjectName(QStringLiteral("quitter"));
        quitter->setGeometry(QRect(600, 430, 101, 23));
        mode_auto = new QPushButton(tab);
        mode_auto->setObjectName(QStringLiteral("mode_auto"));
        mode_auto->setGeometry(QRect(70, 20, 131, 23));
        mode_manu = new QPushButton(tab);
        mode_manu->setObjectName(QStringLiteral("mode_manu"));
        mode_manu->setGeometry(QRect(70, 80, 131, 23));
        aff_bdd = new QPushButton(tab);
        aff_bdd->setObjectName(QStringLiteral("aff_bdd"));
        aff_bdd->setGeometry(QRect(70, 140, 131, 23));
        listWidget = new QListWidget(tab);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(370, 20, 341, 381));
        listWidget->setStyleSheet(QStringLiteral("color: #547546;"));
        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(50, 250, 191, 231));
        groupBox_6->setStyleSheet(QLatin1String("QGroupBox {\n"
"border: 1px solid gray;\n"
"border-radius: 10px;\n"
"}"));
        label = new QLabel(groupBox_6);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 101, 16));
        label->setStyleSheet(QStringLiteral("color: #547546;"));
        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 101, 16));
        label_2->setStyleSheet(QStringLiteral("color: #547546;"));
        label_4 = new QLabel(groupBox_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 190, 31, 16));
        label_4->setStyleSheet(QStringLiteral("color: #547546;"));
        p_veh_legers = new QListWidget(groupBox_6);
        p_veh_legers->setObjectName(QStringLiteral("p_veh_legers"));
        p_veh_legers->setGeometry(QRect(120, 30, 41, 21));
        p_veh_legers->setStyleSheet(QStringLiteral("color: #547546;"));
        p_veh_lourds = new QListWidget(groupBox_6);
        p_veh_lourds->setObjectName(QStringLiteral("p_veh_lourds"));
        p_veh_lourds->setGeometry(QRect(120, 70, 41, 21));
        p_veh_lourds->setStyleSheet(QStringLiteral("color: #547546;"));
        total = new QListWidget(groupBox_6);
        total->setObjectName(QStringLiteral("total"));
        total->setGeometry(QRect(120, 190, 41, 21));
        total->setStyleSheet(QStringLiteral("color: #547546;"));
        label_5 = new QLabel(groupBox_6);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 150, 31, 16));
        label_5->setStyleSheet(QStringLiteral("color: #547546;"));
        total_2 = new QListWidget(groupBox_6);
        total_2->setObjectName(QStringLiteral("total_2"));
        total_2->setGeometry(QRect(120, 150, 41, 21));
        total_2->setStyleSheet(QStringLiteral("color: #547546;"));
        label_6 = new QLabel(groupBox_6);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 110, 81, 16));
        label_6->setStyleSheet(QStringLiteral("color: #547546;"));
        total_3 = new QListWidget(groupBox_6);
        total_3->setObjectName(QStringLiteral("total_3"));
        total_3->setGeometry(QRect(120, 110, 41, 21));
        total_3->setStyleSheet(QStringLiteral("color: #547546;"));
        groupBox_7 = new QGroupBox(tab);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(270, 430, 161, 51));
        groupBox_7->setStyleSheet(QLatin1String("QGroupBox {\n"
"border: 1px solid gray;\n"
"border-radius: 10px;\n"
"}"));
        aff_bdd_2 = new QPushButton(tab);
        aff_bdd_2->setObjectName(QStringLiteral("aff_bdd_2"));
        aff_bdd_2->setGeometry(QRect(70, 200, 131, 23));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 30, 311, 81));
        groupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"border: 1px solid gray;\n"
"border-radius: 10px;\n"
"color: #547546;\n"
" }"));
        recherche = new QLineEdit(groupBox);
        recherche->setObjectName(QStringLiteral("recherche"));
        recherche->setGeometry(QRect(140, 30, 113, 20));
        QFont font;
        font.setItalic(true);
        recherche->setFont(font);
        rech_client = new QPushButton(groupBox);
        rech_client->setObjectName(QStringLiteral("rech_client"));
        rech_client->setGeometry(QRect(30, 30, 75, 23));
        rech_client->setAutoDefault(false);
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(50, 380, 311, 91));
        groupBox_3->setStyleSheet(QLatin1String("QGroupBox {\n"
"border: 1px solid gray;\n"
"border-radius: 10px;\n"
"color: #547546;\n"
" }"));
        supp = new QPushButton(groupBox_3);
        supp->setObjectName(QStringLiteral("supp"));
        supp->setGeometry(QRect(30, 30, 75, 23));
        supp_2 = new QLineEdit(groupBox_3);
        supp_2->setObjectName(QStringLiteral("supp_2"));
        supp_2->setGeometry(QRect(140, 30, 113, 20));
        supp_2->setFont(font);
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(50, 140, 311, 211));
        groupBox_2->setStyleSheet(QLatin1String("QGroupBox {\n"
"border: 1px solid gray;\n"
"border-radius: 10px;\n"
"color: #547546;\n"
" }"));
        ajout = new QPushButton(groupBox_2);
        ajout->setObjectName(QStringLiteral("ajout"));
        ajout->setGeometry(QRect(30, 30, 75, 23));
        num_client = new QLineEdit(groupBox_2);
        num_client->setObjectName(QStringLiteral("num_client"));
        num_client->setGeometry(QRect(140, 20, 113, 20));
        num_client->setFont(font);
        nom = new QLineEdit(groupBox_2);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(140, 60, 113, 20));
        nom->setFont(font);
        prenom = new QLineEdit(groupBox_2);
        prenom->setObjectName(QStringLiteral("prenom"));
        prenom->setGeometry(QRect(140, 100, 113, 20));
        prenom->setFont(font);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 130, 91, 16));
        voiture = new QRadioButton(groupBox_2);
        voiture->setObjectName(QStringLiteral("voiture"));
        voiture->setGeometry(QRect(140, 140, 82, 17));
        moto_velo = new QRadioButton(groupBox_2);
        moto_velo->setObjectName(QStringLiteral("moto_velo"));
        moto_velo->setGeometry(QRect(140, 160, 82, 17));
        utilitaire = new QRadioButton(groupBox_2);
        utilitaire->setObjectName(QStringLiteral("utilitaire"));
        utilitaire->setGeometry(QRect(140, 180, 82, 17));
        listWidget_2 = new QListWidget(tab_2);
        listWidget_2->setObjectName(QStringLiteral("listWidget_2"));
        listWidget_2->setGeometry(QRect(410, 30, 281, 441));
        listWidget_2->setStyleSheet(QStringLiteral("color: #547546;"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        listWidget_3 = new QListWidget(tab_3);
        listWidget_3->setObjectName(QStringLiteral("listWidget_3"));
        listWidget_3->setGeometry(QRect(230, 30, 261, 401));
        listWidget_3->setStyleSheet(QStringLiteral("color: #547546;"));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 50, 111, 23));
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 100, 111, 23));
        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 150, 111, 23));
        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 200, 111, 23));
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(40, 250, 111, 23));
        pushButton_7 = new QPushButton(tab_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(40, 300, 111, 23));
        pushButton_8 = new QPushButton(tab_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(40, 350, 111, 23));
        pushButton_9 = new QPushButton(tab_3);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(40, 400, 111, 23));
        groupBox_4 = new QGroupBox(tab_3);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 20, 171, 421));
        groupBox_4->setStyleSheet(QLatin1String("QGroupBox{\n"
"border: 1px solid gray;\n"
"border-radius: 10px;\n"
"color: #547546;\n"
"}"));
        groupBox_5 = new QGroupBox(tab_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(530, 20, 171, 421));
        groupBox_5->setStyleSheet(QLatin1String("QGroupBox{\n"
"border: 1px solid gray;\n"
"border-radius: 10px;\n"
"color: #547546;\n"
"}"));
        pushButton_3 = new QPushButton(groupBox_5);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 30, 111, 23));
        pushButton_10 = new QPushButton(groupBox_5);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(30, 80, 111, 23));
        pushButton_12 = new QPushButton(groupBox_5);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(30, 120, 111, 23));
        tabWidget->addTab(tab_3, QString());
        groupBox_4->raise();
        listWidget_3->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        pushButton_6->raise();
        pushButton_7->raise();
        pushButton_8->raise();
        pushButton_9->raise();
        groupBox_5->raise();
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);

        C_SERVEUR->setCentralWidget(centralwidget);
        menubar = new QMenuBar(C_SERVEUR);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 775, 21));
        menu_Fichier = new QMenu(menubar);
        menu_Fichier->setObjectName(QStringLiteral("menu_Fichier"));
        C_SERVEUR->setMenuBar(menubar);
        statusbar = new QStatusBar(C_SERVEUR);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        C_SERVEUR->setStatusBar(statusbar);

        menubar->addAction(menu_Fichier->menuAction());
        menu_Fichier->addAction(actionQuitter);

        retranslateUi(C_SERVEUR);
        QObject::connect(actionQuitter, SIGNAL(triggered()), C_SERVEUR, SLOT(close()));
        QObject::connect(mode_auto, SIGNAL(clicked()), C_SERVEUR, SLOT(Mode_Automatique()));
        QObject::connect(mode_manu, SIGNAL(clicked()), C_SERVEUR, SLOT(Mode_manuel()));
        QObject::connect(quitter, SIGNAL(clicked()), C_SERVEUR, SLOT(close()));
        QObject::connect(rech_client, SIGNAL(clicked()), C_SERVEUR, SLOT(Rechercher_client()));
        QObject::connect(supp, SIGNAL(clicked()), C_SERVEUR, SLOT(Supprimer_client()));
        QObject::connect(pushButton, SIGNAL(clicked()), C_SERVEUR, SLOT(Active_led_portail()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), C_SERVEUR, SLOT(Desactive_led_portail()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), C_SERVEUR, SLOT(Active_moteur()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), C_SERVEUR, SLOT(Desactive_moteur()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), C_SERVEUR, SLOT(Active_buzzer()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), C_SERVEUR, SLOT(Desactive_buzzer()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), C_SERVEUR, SLOT(Active_led_flash()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), C_SERVEUR, SLOT(Desactive_led_flash()));
        QObject::connect(ajout, SIGNAL(clicked()), C_SERVEUR, SLOT(Ajouter_client()));
        QObject::connect(prenom, SIGNAL(textEdited(QString)), C_SERVEUR, SLOT(Mettre_majuscule()));
        QObject::connect(nom, SIGNAL(textEdited(QString)), C_SERVEUR, SLOT(Mettre_majuscule()));
        QObject::connect(aff_bdd_2, SIGNAL(clicked()), C_SERVEUR, SLOT(Creer_vue_parking()));
        QObject::connect(aff_bdd, SIGNAL(clicked()), C_SERVEUR, SLOT(Creer_vue_info()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), C_SERVEUR, SLOT(Demande_etat_bouton()));
        QObject::connect(pushButton_10, SIGNAL(clicked()), C_SERVEUR, SLOT(Demande_etat_capteur_lumiere()));
        QObject::connect(pushButton_12, SIGNAL(clicked()), C_SERVEUR, SLOT(Reset()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(C_SERVEUR);
    } // setupUi

    void retranslateUi(QMainWindow *C_SERVEUR)
    {
        C_SERVEUR->setWindowTitle(QApplication::translate("C_SERVEUR", "C_SERVEUR", 0));
        actionQuitter->setText(QApplication::translate("C_SERVEUR", "Quitter", 0));
        label_3->setText(QApplication::translate("C_SERVEUR", "IHM de gestion d'acc\303\250s au parking", 0));
        quitter->setText(QApplication::translate("C_SERVEUR", "Quitter", 0));
        mode_auto->setText(QApplication::translate("C_SERVEUR", "Mode automatique", 0));
        mode_manu->setText(QApplication::translate("C_SERVEUR", "Mode manuel", 0));
        aff_bdd->setText(QApplication::translate("C_SERVEUR", "BDD informations clients", 0));
        groupBox_6->setTitle(QApplication::translate("C_SERVEUR", "Options parking", 0));
        label->setText(QApplication::translate("C_SERVEUR", "Place v\303\251hicule l\303\251gers", 0));
        label_2->setText(QApplication::translate("C_SERVEUR", "Place v\303\251hicule lourds", 0));
        label_4->setText(QApplication::translate("C_SERVEUR", "Total", 0));
        label_5->setText(QApplication::translate("C_SERVEUR", "Autre", 0));
        label_6->setText(QApplication::translate("C_SERVEUR", "Motos/V\303\251los", 0));
        groupBox_7->setTitle(QApplication::translate("C_SERVEUR", "Horaires", 0));
        aff_bdd_2->setText(QApplication::translate("C_SERVEUR", "BDD informations parking", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("C_SERVEUR", "Accueil", 0));
        groupBox->setTitle(QApplication::translate("C_SERVEUR", "Rechercher", 0));
        recherche->setPlaceholderText(QApplication::translate("C_SERVEUR", "Num\303\251ro du client", 0));
        rech_client->setText(QApplication::translate("C_SERVEUR", "Rechercher", 0));
        groupBox_3->setTitle(QApplication::translate("C_SERVEUR", "Supprimer", 0));
        supp->setText(QApplication::translate("C_SERVEUR", "Supprimer", 0));
        supp_2->setPlaceholderText(QApplication::translate("C_SERVEUR", "Num\303\251ro du client", 0));
        groupBox_2->setTitle(QApplication::translate("C_SERVEUR", "Ajouter", 0));
        ajout->setText(QApplication::translate("C_SERVEUR", "Ajouter", 0));
        num_client->setPlaceholderText(QApplication::translate("C_SERVEUR", "Num\303\251ro du client", 0));
        nom->setPlaceholderText(QApplication::translate("C_SERVEUR", "Nom", 0));
        prenom->setPlaceholderText(QApplication::translate("C_SERVEUR", "Pr\303\251nom", 0));
        label_7->setText(QApplication::translate("C_SERVEUR", "Type de v\303\251hicule :", 0));
        voiture->setText(QApplication::translate("C_SERVEUR", "Voiture", 0));
        moto_velo->setText(QApplication::translate("C_SERVEUR", "Moto/V\303\251lo", 0));
        utilitaire->setText(QApplication::translate("C_SERVEUR", "Utilitaire", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("C_SERVEUR", "Modification des donn\303\251es", 0));
        pushButton->setText(QApplication::translate("C_SERVEUR", "Activer led portail", 0));
        pushButton_2->setText(QApplication::translate("C_SERVEUR", "D\303\251sactiver led portail", 0));
        pushButton_4->setText(QApplication::translate("C_SERVEUR", "Activer moteur", 0));
        pushButton_5->setText(QApplication::translate("C_SERVEUR", "D\303\251sactiver moteur", 0));
        pushButton_6->setText(QApplication::translate("C_SERVEUR", "Activer buzzer", 0));
        pushButton_7->setText(QApplication::translate("C_SERVEUR", "D\303\251sactiver buzzer", 0));
        pushButton_8->setText(QApplication::translate("C_SERVEUR", "Activer led flash", 0));
        pushButton_9->setText(QApplication::translate("C_SERVEUR", "D\303\251sactiver led flash", 0));
        groupBox_4->setTitle(QApplication::translate("C_SERVEUR", "Activer/d\303\251sactiver actionneurs", 0));
        groupBox_5->setTitle(QApplication::translate("C_SERVEUR", "Demander \303\251tats capteurs", 0));
        pushButton_3->setText(QApplication::translate("C_SERVEUR", "Bouton", 0));
        pushButton_10->setText(QApplication::translate("C_SERVEUR", "Capteur lumi\303\250re", 0));
        pushButton_12->setText(QApplication::translate("C_SERVEUR", "Reset", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("C_SERVEUR", "Mode manuel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("C_SERVEUR", "Affichage cam\303\251ra", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("C_SERVEUR", "Param\303\251tres", 0));
        menu_Fichier->setTitle(QApplication::translate("C_SERVEUR", "&Fichier", 0));
    } // retranslateUi

};

namespace Ui {
    class C_SERVEUR: public Ui_C_SERVEUR {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_SERVEUR_H
