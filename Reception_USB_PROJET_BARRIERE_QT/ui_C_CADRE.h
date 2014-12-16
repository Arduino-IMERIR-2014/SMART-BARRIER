/********************************************************************************
** Form generated from reading UI file 'C_CADRE.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_C_CADRE_H
#define UI_C_CADRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_C_CADRE
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QListWidget *Etat_Carte;
    QListWidget *Etat_Serveur;
    QListWidget *Info_Serveur;
    QListWidget *Info_Carte;
    QPushButton *Bouton_Connection_Serveur;
    QPushButton *Bouton_Connexion_Carte;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *C_CADRE)
    {
        if (C_CADRE->objectName().isEmpty())
            C_CADRE->setObjectName(QStringLiteral("C_CADRE"));
        C_CADRE->resize(282, 189);
        centralwidget = new QWidget(C_CADRE);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 61, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 10, 61, 16));
        Etat_Carte = new QListWidget(centralwidget);
        Etat_Carte->setObjectName(QStringLiteral("Etat_Carte"));
        Etat_Carte->setGeometry(QRect(10, 30, 101, 31));
        Etat_Serveur = new QListWidget(centralwidget);
        Etat_Serveur->setObjectName(QStringLiteral("Etat_Serveur"));
        Etat_Serveur->setGeometry(QRect(150, 30, 101, 31));
        Info_Serveur = new QListWidget(centralwidget);
        Info_Serveur->setObjectName(QStringLiteral("Info_Serveur"));
        Info_Serveur->setGeometry(QRect(180, 70, 41, 31));
        Info_Carte = new QListWidget(centralwidget);
        Info_Carte->setObjectName(QStringLiteral("Info_Carte"));
        Info_Carte->setGeometry(QRect(40, 70, 41, 31));
        Bouton_Connection_Serveur = new QPushButton(centralwidget);
        Bouton_Connection_Serveur->setObjectName(QStringLiteral("Bouton_Connection_Serveur"));
        Bouton_Connection_Serveur->setGeometry(QRect(160, 110, 75, 23));
        Bouton_Connexion_Carte = new QPushButton(centralwidget);
        Bouton_Connexion_Carte->setObjectName(QStringLiteral("Bouton_Connexion_Carte"));
        Bouton_Connexion_Carte->setGeometry(QRect(20, 110, 75, 23));
        C_CADRE->setCentralWidget(centralwidget);
        menubar = new QMenuBar(C_CADRE);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 282, 21));
        C_CADRE->setMenuBar(menubar);
        statusbar = new QStatusBar(C_CADRE);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        C_CADRE->setStatusBar(statusbar);

        retranslateUi(C_CADRE);
        QObject::connect(Bouton_Connection_Serveur, SIGNAL(clicked()), C_CADRE, SLOT(Slot_Connexion_Serveur()));
        QObject::connect(Bouton_Connexion_Carte, SIGNAL(clicked()), C_CADRE, SLOT(Slot_Connexion_Carte()));

        QMetaObject::connectSlotsByName(C_CADRE);
    } // setupUi

    void retranslateUi(QMainWindow *C_CADRE)
    {
        C_CADRE->setWindowTitle(QApplication::translate("C_CADRE", "C_CADRE", 0));
        label->setText(QApplication::translate("C_CADRE", "Etat Carte", 0));
        label_2->setText(QApplication::translate("C_CADRE", "Etat Serveur", 0));
        Bouton_Connection_Serveur->setText(QApplication::translate("C_CADRE", "Connexion", 0));
        Bouton_Connexion_Carte->setText(QApplication::translate("C_CADRE", "Connexion", 0));
    } // retranslateUi

};

namespace Ui {
    class C_CADRE: public Ui_C_CADRE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_C_CADRE_H
