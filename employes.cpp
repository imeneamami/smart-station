#include "employes.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Employes::Employes()
{
    Id=0;
    Nom="";
    Prenom="";
    Adresse="";
    Mail="";
    Age="";


}
Employes::Employes(int Id,QString Nom, QString Prenom, QString Adresse, QString Mail, QString Age)
{
    this->Id=Id;
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->Mail=Mail;
    this->Age=Age;
    this->Adresse=Adresse;
     Employes::getId();
     Employes::getNom();
     Employes::getPrenom();
     Employes::getAge();
     Employes::getAdresse();
     Employes::getMail();

     void setId(int Id);{this ->Id=Id;}
     void setNom(QString Nom);{this->Nom=Nom;}
     void setPrenom(QString Prenom);{this->Prenom=Prenom;}
     void setAge(QString Age);{this->Age=Age;}
     void setMail(QString Mail);{this->Mail=Mail;}
     void setAdresse(QString Adresse);{this->Adresse=Adresse;}


}
bool Employes::ajouter()
{
     QSqlQuery querry;
    QString Id_string=QString::number(Id);

    querry.prepare("INSERT INTO Employes(ID, NOM, PRENOM, Adresse, Mail, Age)""VALUES(:Id, :Nom, :Prenom, :Adresse, :Mail,Age)");
    querry.bindValue(":Id",Id_string);
    querry.bindValue(":Nom",Nom);
    querry.bindValue(":Prenom",Prenom);
    querry.bindValue(":Adresse",Adresse);
    querry.bindValue(":Mail",Mail);
    querry.bindValue(":Age",Age);


    return querry.exec();

}
bool Employes::supprimer(int Id)
{
    QSqlQuery querry;
    querry.prepare("Delete from employes where Id=Id");
    querry.bindValue(0,Id);
    querry.bindValue(1,Nom);
    querry.bindValue(2,Prenom);
    querry.bindValue(5,Mail);
    return querry.exec();
}

QSqlQueryModel* Employes::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery("select * from Employes");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Adresse"));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("Mail"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("Age"));
      return model;

}
bool Employes::Modifier(int Id)
{
    QSqlQuery query;
    QString Id_string= QString::number(Id);
    query.prepare(" EMPLOYES SET NOM=:Nom,PRENOM=:Prenom,ADRESSE=:Adresse, MAIL=:Mail, AGE=:Age WHERE ID=:Id");
    query.bindValue(0,Id);
    query.bindValue(1,Nom);
    query.bindValue(2,Prenom);
    query.bindValue(3,Adresse);
    query.bindValue(4,Mail);
    query.bindValue(5,Age);

    return query.exec();
}
void Employes::Mailing;
     {
if (ui->Mail->text().contains(QRegExp("^\w\@ \.]{2,4,5,6}"))) || ui->Mail
{
    ui->Mail->clear();
    ui->Mail->setTexte("user@email.com");
    return false;

}
     else
{               return true;
}
