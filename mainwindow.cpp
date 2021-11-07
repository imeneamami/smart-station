#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_Id->setValidator(new QIntValidator(0,9999999,this));
ui->tab_employes->setModel(E.afficher());

}


MainWindow::~MainWindow()


{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int Id=ui->le_Id->text().toInt();
    QString Nom=ui->le_Nom->text();
    QString Prenom=ui->le_Prenom->text();
    QString Age=ui->le_Age->text();
    QString Adresse=ui->le_Adresse->text();
    QString Mail=ui->le_Mail->text();
    Employes E(Id,Nom,Prenom,Adresse,Age,Mail);
}
bool test= E.ajouter
       QMessageBox msgBox;

if (test)
  { msgBox.setText("Ajout avec success ");
  else
   msgBox.setText("Echec d'ajout");
}
void MainWindow::on_pb_supprimer_clicked()
{
    Employes E1; E1.setId(ui->le_Id_supp->text().toInt());
    bool test=E1.supprimer(E1.getId());

    QMessageBox msgBox;

    if (test)
       msgBox.setText("suppression avec success ");
    else
       msgBox.setText("Echec de suppression");
}



void MainWindow::on_pb_se_connecter_clicked()
{
    Employes E;
    QString login=ui->le_login->text();
    QString motdepasse=ui->le_mdp->text();
    if (login=="admin" && motdepasse=="admin")
    {
        QMessageBox::information(this,"Authentification reussie","login et mot de passe correcte");
        hide();
      }
        else {
            QMessageBox::warning(this,"Authentification échoué","Mot de passe/login incorrectes");

        }
}

void MainWindow::on_le_mailing_clicked()
{
   bool texte =E.Mailing;
   QMessageBox msgBox;

if (texte)
{
    msgBox.setText("ecriture de mail avec success ");
}
else
 msgBox.setText("Echec d'ecriture ");

void MainWindow::on_pb_envoyer_clicked()
{

}

void MainWindow::on_pb_supprimer_2_clicked()
{

};
