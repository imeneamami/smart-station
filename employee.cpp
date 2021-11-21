#include "employee.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>

employee::employee()
{
    id=0;
    nom="";
    prenom="";
    age=0;
    mail="";
    adresse="";
}
employee::employee(int id,QString nom,QString prenom,int age,QString mail,QString adresse)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->age=age;
  this->mail=mail;
  this->adresse=adresse;
}

int employee::get_id(){return id;}
QString employee::get_nom(){return nom;}
QString employee::get_prenom(){return prenom ;}
int employee::get_age(){return age;}
QString employee::get_mail(){return mail ;}
QString employee::get_adresse(){return adresse;}



bool employee::ajouter()
{
QSqlQuery query;

QString res= QString::number(id);

query.prepare("INSERT INTO employee (id,nom,prenom,age,mail,adresse) "
                    "VALUES (:id,:nom,:prenom,:age,:mail,:adresse)");

query.bindValue(":id",res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":age",age);
query.bindValue(":mail",mail);
query.bindValue(":adresse",adresse);

return    query.exec();
}

QSqlQueryModel * employee::afficher()
{
  QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from employee");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
return model;
}

bool employee::supprimer(int id)
{
    QSqlQuery query;


    QString res= QString::number(id);

    query.prepare("Delete from employee where id= :id");
    query.bindValue(":id", res);
    return    query.exec();
}




bool employee::modifier(int id,QString nom,QString prenom,int age,QString mail,QString adresse)
{ QSqlQuery query;
    QString res= QString::number(id);

    query.prepare("update evenement set id=:id,nom=:nom,prenom=:prenom,age=:age,mail=:mail,adresse=:adresse where id=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":age",age);
    query.bindValue(":mail",mail);
    query.bindValue(":adresse",adresse);


    return    query.exec();

}

QSqlQueryModel * employee::chercher_nom(QString N)
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM employee WHERE nom ='"+N+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));

    return model ;
}
QSqlQueryModel * employee::chercher_adresse(QString N)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM employee WHERE adresse ='"+N+"' ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));

    return model ;
}
QSqlQueryModel * employee::trier_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM employee ORDER BY id asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}
QSqlQueryModel * employee::trier_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM employee ORDER BY nom asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));

    return model;
}
QSqlQueryModel * employee::trier_age()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM employee ORDER BY age asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
    return model
        ;
}
