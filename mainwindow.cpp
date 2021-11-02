#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "metro.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    {
        metro h;
        metro Etmp;
        int id=ui->lineEdit_id->text().toInt();
        int places=ui->lineEdit_places->text().toInt();
        int depart=ui->lineEdit_depart->text().toInt();

        QString destination=ui->lineEdit_destination->text();
        QString type=ui->lineEdit_etat->text();

    metro E(id,destination,places,type,depart);
    bool test=E.ajouter();
    if(test)
    {
        ui->tableView_2->setModel(Etmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue \n click cancel to exit."), QMessageBox::Cancel);
    }

    }
}

void MainWindow::on_pushButton_4_clicked()
{
    metro Etmp;
    Etmp.setid(ui->lineEdit_id->text().toInt());
    QMessageBox msgbox;
        msgbox.setWindowTitle("supprimer");
        msgbox.setText("voulez_vous supprimer cette réclamation?");
        msgbox.setStandardButtons(QMessageBox ::Yes);
        msgbox.addButton(QMessageBox::No);
        if(msgbox.exec()==QMessageBox::Yes)
        {
  bool test=Etmp.supprimer(Etmp.getid());
  QMessageBox msgBox;

  if(test)
  {

      QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectuée \n click cancel to exit."), QMessageBox::Cancel);
      {ui->tableView_2->setModel(Etmp.afficher());}

  }
  else
      QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("suppression non effectuer.\n click cancel to exis."), QMessageBox::Cancel);
  msgBox.exec();

}
}

void MainWindow::on_pushButton_5_clicked()
{
    metro Etmp;

    {ui->tableView_2->setModel(Etmp.afficher());}
}

void MainWindow::on_pushButton_3_clicked()
{
    metro p;
        int id = ui->lineEdit_id_2->text().toInt();
        int depart= ui->lineEdit_depart_2->text().toInt();
        int places= ui->lineEdit_places_2->text().toInt();

        QString type = ui->lineEdit_etat_2->text();
        QString destination = ui->lineEdit_destination_2->text();


        metro (id,destination,places,type,depart);
        bool test =p.modifier(type,places,id,depart,destination);
        if(test)
        {ui->tableView_2->setModel(p.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier un employe"),
                                     QObject::tr("employe  modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un employe"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}
