#include "employes.h"

Employes::Employes()
{
    Id=0;
    Nom="";
    Prenom="";
    Adresse="";
    Email="";
    Age="";

    
}
Employes::Employes(int Id,QString Nom, QString Prenom, QString Adresse, QString Email, QString Age)
{
    this->Id=Id;
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->Email=Email;
    this->Age=Age;
    this->Adresse=Adresse;

}
bool Employes::ajouter()
{
    QSqlQuery querry;
    QString res=QString::number(Id);
    querry.prepare("INSERT INTO Employes(ID, NOM, PRENOM, Adresse, Email, Age)""VALUES(:Id, :Nom, :Prenom, :Adresse, :Email)");
    querry.bindValue(":Id",res);
    querry.bindValue(":Nom",Nom);
    querry.bindValue(":Prenom",Prenom);
    querry.bindValue(":Adresse",Adresse);
    querry.bindValue(":Email",Email);

    return querry.exec();
}
QSqlQueryModel* Employes::afficher()
{
    QSqlQueryModel *model= new QSqlQueryModel();

    model->setQuery("select * from EVENEMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Adresse"));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("Email"));
      model->setHeaderData(2, Qt::Horizontal,QObject::tr("Age"));
      return model;

}
bool Employes::Modifier(int Id)
{
    QSqlQuery query;
    QString res= QString::number(Id);
    query.prepare("UPDATE EMPLOYES SET NOM=:Nom,PRENOM=:Prenom,ADRESSE=:Adresse, EMAIL=:Email, AGE=:Age WHERE ID=:Id");
    query.bindValue(":Id", res);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Prenom", Prenom);
    query.bindValue(":Adresse", Adresse);
    query.bindValue(":Email", Email);
    query.bindValue(":Age", Age);

    return    query.exec();
}

bool Employes::supprimer(int Id)
{
    QSqlQuery query;
    query.prepare("Delete from Employes where ID = :Id");
    query.bindValue(":Id", Id);
    return query.exec();
}
