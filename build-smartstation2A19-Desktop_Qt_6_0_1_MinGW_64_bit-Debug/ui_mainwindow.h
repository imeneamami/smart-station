/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLineEdit *le_numtrain;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *le_arretd;
    QLineEdit *le_arretf;
    QLineEdit *le_nbrplace;
    QLineEdit *le_conducteur;
    QPushButton *pb_ajouter;
    QTimeEdit *le_heured;
    QDateTimeEdit *dateTimeEdit;
    QPushButton *pb_modifier;
    QLabel *label_7;
    QLineEdit *le_id;
    QLineEdit *le_idsuprimer;
    QTableView *ta_voyage;
    QPushButton *pb_supprimer;
    QLabel *label_8;
    QMenuBar *menubar;
    QMenu *menugestion_des_voyages;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 30, 811, 411));
        le_numtrain = new QLineEdit(groupBox);
        le_numtrain->setObjectName(QString::fromUtf8("le_numtrain"));
        le_numtrain->setGeometry(QRect(200, 140, 113, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 140, 121, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 180, 91, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 210, 81, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 260, 151, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(40, 300, 91, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 340, 91, 16));
        le_arretd = new QLineEdit(groupBox);
        le_arretd->setObjectName(QString::fromUtf8("le_arretd"));
        le_arretd->setGeometry(QRect(200, 190, 113, 20));
        le_arretf = new QLineEdit(groupBox);
        le_arretf->setObjectName(QString::fromUtf8("le_arretf"));
        le_arretf->setGeometry(QRect(200, 220, 113, 20));
        le_nbrplace = new QLineEdit(groupBox);
        le_nbrplace->setObjectName(QString::fromUtf8("le_nbrplace"));
        le_nbrplace->setGeometry(QRect(200, 260, 113, 20));
        le_conducteur = new QLineEdit(groupBox);
        le_conducteur->setObjectName(QString::fromUtf8("le_conducteur"));
        le_conducteur->setGeometry(QRect(200, 300, 111, 20));
        pb_ajouter = new QPushButton(groupBox);
        pb_ajouter->setObjectName(QString::fromUtf8("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(80, 380, 75, 23));
        le_heured = new QTimeEdit(groupBox);
        le_heured->setObjectName(QString::fromUtf8("le_heured"));
        le_heured->setGeometry(QRect(200, 340, 118, 22));
        dateTimeEdit = new QDateTimeEdit(groupBox);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(150, 20, 194, 22));
        pb_modifier = new QPushButton(groupBox);
        pb_modifier->setObjectName(QString::fromUtf8("pb_modifier"));
        pb_modifier->setGeometry(QRect(220, 380, 75, 23));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 100, 47, 13));
        le_id = new QLineEdit(groupBox);
        le_id->setObjectName(QString::fromUtf8("le_id"));
        le_id->setGeometry(QRect(200, 100, 113, 20));
        le_idsuprimer = new QLineEdit(groupBox);
        le_idsuprimer->setObjectName(QString::fromUtf8("le_idsuprimer"));
        le_idsuprimer->setGeometry(QRect(450, 340, 113, 20));
        ta_voyage = new QTableView(groupBox);
        ta_voyage->setObjectName(QString::fromUtf8("ta_voyage"));
        ta_voyage->setGeometry(QRect(420, 60, 256, 192));
        pb_supprimer = new QPushButton(centralwidget);
        pb_supprimer->setObjectName(QString::fromUtf8("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(630, 370, 75, 23));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(500, 340, 47, 13));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menugestion_des_voyages = new QMenu(menubar);
        menugestion_des_voyages->setObjectName(QString::fromUtf8("menugestion_des_voyages"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menugestion_des_voyages->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Ajouter un voyage ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "numero du metro ", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "arret de d\303\251but ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "arret du fin", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "nombre du places disponible", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "conducteur ", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "heure de d\303\251part", nullptr));
        pb_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pb_modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "id voyage", nullptr));
        pb_supprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "id voyage", nullptr));
        menugestion_des_voyages->setTitle(QCoreApplication::translate("MainWindow", "gestion des voyages", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
