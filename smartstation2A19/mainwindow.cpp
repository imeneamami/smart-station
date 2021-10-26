#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "voyage.h"
#include "connexion.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlTableModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(100,999999,this));
    ui->ta_voyage->setModel(Etmp.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int idvoyage=ui->le_id->text().toInt();
    int numtrain=ui->le_numtrain->text().toInt();
    QString arretd=ui->le_arretd->text();
    QString arretf=ui->le_arretf->text();
    int nbrplace=ui->le_nbrplace->text().toInt();
    QString heured=ui->le_heured->text();
    Voyage V(idvoyage,numtrain,arretd,arretf,nbrplace,heured);
    bool test=V.ajouter();

    if (test)

    {
        ui->ta_voyage->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout voyage"),
        QObject::tr("voyage ajouté :"), QMessageBox::Cancel);
    }

}

void MainWindow::on_pb_supprimer_clicked()
{

    Voyage V1;
    V1.setidvoyage(ui->le_idsuprimer->text().toUInt());
    bool test=V1.supprimer(V1.getidvoyage());

    if (test)
     {
       ui->ta_voyage->setModel(Etmp.afficher());

      QMessageBox::information(nullptr, QObject::tr(" suppression voyage "),
                             QObject::tr("voyage supprimé :"), QMessageBox::Cancel);
     }

}

void MainWindow::on_pb_modifier_clicked()
{

    if (ui->pb_modifier->isChecked())
          {
              ui->pb_modifier->setDisabled(true);
              ui->pb_modifier->setText("Modifiable");
              QSqlTableModel *tableModel= new QSqlTableModel();
              tableModel->setTable("VOYAGE");
              tableModel->select();
              ui->ta_voyage->setModel(tableModel);
          }
          else
          {
              ui->pb_modifier->setText("Modifier");
              ui->ta_voyage->setModel(V.afficher());

          }

}
