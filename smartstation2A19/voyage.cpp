#include "voyage.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>


Voyage::Voyage(){

    idvoyage=0;
    numtrain=0;
    arretd="";
    arretf="";
    nbrplace=0;
    heured="";


}

Voyage::Voyage(int idvoyage,int numtrain,QString arretd,QString arretf,int nbrplace,QString heured)
{
    this->idvoyage=idvoyage;
    this->numtrain=numtrain;
    this->arretd=arretd;
    this->arretf=arretf;
    this->nbrplace=nbrplace;
    this->heured=heured;
}

int Voyage::getidvoyage(){return idvoyage;};
int Voyage::getnumtrain(){return numtrain;};
QString Voyage::getarretd(){return  arretd;};
QString Voyage::getarretf(){return  arretf;};
int Voyage::getnbrplace(){return  nbrplace;};
QString Voyage:: getheure(){return heured;};

void Voyage::setidvoyage(int idvoyage){this->idvoyage=idvoyage;};
void Voyage::setnumtrain(int numtrain){this->numtrain=numtrain;};
void Voyage::setarretd(QString arretd){this->arretd=arretd;};
void Voyage::setarretf(QString arretf){this->arretf=arretf;};
void Voyage::setnbrplace(int nbrplace){this->nbrplace=nbrplace;};
void Voyage::setheure(QString( heured)){this->heured=heured;};


bool Voyage::ajouter()
{
     QSqlQuery query;
     QString res= QString::number(idvoyage);
     QString ress= QString::number(numtrain);
     QString resss= QString::number(nbrplace);
     query.prepare("insert into VOYAGE (IDVOYAGE,NUMTRAIN,ARRETD,ARRETF,NBRPLACE,HEURE) " "values (:idvoyage,:numtrain,:arretd,:arretf,:nbrplace,:heure)");

     query.bindValue(":idvoyage",res);
     query.bindValue(":numtrain",ress);
     query.bindValue(":arretd",arretd);
     query.bindValue(":arretf",arretf);
     query.bindValue(":nbrplace",resss);
     query.bindValue(":heure",heured);
     return query.exec();


}





QSqlQueryModel * Voyage::afficher()
{
  QSqlQueryModel * model = new QSqlQueryModel();
  model->setQuery("select * from VOYAGE");
  model->setHeaderData(0,Qt::Horizontal,"idvoyage");
  model->setHeaderData(1,Qt::Horizontal,"numtrain");
  model->setHeaderData(2,Qt::Horizontal,"arretd");
  model->setHeaderData(3,Qt::Horizontal,"arretf");
   model->setHeaderData(4,Qt::Horizontal,"nbrplace");
   model->setHeaderData(5,Qt::Horizontal,"heure");
   return model;
}



bool Voyage::supprimer(int idvoyage){
    QSqlQuery qry;
    qry.prepare("Delete from VOYAGE where IDVOYAGE=:idvoyage");
    QString idvoyagee=QString::number(idvoyage);
    qry.bindValue(":idvoyage",idvoyage);
    return qry.exec();
}

