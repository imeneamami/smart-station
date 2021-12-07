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


bool Voyage::modifier(){
    QSqlQuery qry;
    qry.prepare ("update VOYAGE" "SET IDVOYAGE =:idvoyage , NUMTRAIN=:numtrain ,"
" ARRETD=:arretd, ARRETF=:arretf , NBRPLACE=:nbrplace , HEURE=:heure" );
    return qry.exec();
}


QSqlQueryModel * Voyage::chercher_voyage_id(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from VOYAGE where ((IDVOYAGE ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("IDVOYAGE"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("NUMTRAIN"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("ARRETD"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("ARRETF"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("NBRPLACE"));
     model->setHeaderData(5,Qt::Vertical,QObject::tr("HEURE"));

    return model;
}


QSqlQueryModel * Voyage::chercher_numtrain(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from VOYAGE where ((NUMTRAIN ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("IDVOYAGE"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("NUMTRAIN"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("ARRETD"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("ARRETF"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("NBRPLACE"));
     model->setHeaderData(5,Qt::Vertical,QObject::tr("HEURE"));

    return model;
}

QSqlQueryModel * Voyage::chercher_conducteur(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from VOYAGE where ((NUMTRAIN ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("IDVOYAGE"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("NUMTRAIN"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("ARRETD"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("ARRETF"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("NBRPLACE"));
     model->setHeaderData(5,Qt::Vertical,QObject::tr("HEURE"));

    return model;
}


QSqlQueryModel* Voyage::trie()
{



               QSqlQueryModel * model = new  QSqlQueryModel ();

               model->setQuery("select *  from VOYAGE   ORDER BY IDVOYAGE");

         model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDVOYAGE"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMTRAIN"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("ARRETD"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("ARRETF"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBRPLACE"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEURE"));





    return model;
}


QSqlQueryModel* Voyage::trie2()
{
    QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("select *  from VOYAGE   ORDER BY HEURE");

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDVOYAGE"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUMTRAIN"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("ARRETD"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("ARRETF"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("NBRPLACE"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("HEURE"));



    return model;
}

