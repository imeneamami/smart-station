#include "metro.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

metro::metro(  int id ,   QString destination ,int places ,  QString type ,int depart )
{
this->type=type;
    this->places=places;


    this->id=id;
    this->depart=depart;
    this->destination=destination;

}
bool metro::ajouter()
{
    QSqlQuery query; // SQL teb3a l DB
    QString res=QString::number(id);
    QString res1=QString::number(depart);
    QString res2=QString::number(places);

    query.prepare("INSERT INTO metro (id,destination,places,type,depart) "
                        "VALUES (:id, :destination, :places, :type, :depart)");
    query.bindValue(":id", res);
    query.bindValue(":depart", res1);
    query.bindValue(":places", res2);


    query.bindValue(":type", type);
    query.bindValue(":destination", destination);




    return    query.exec();

}


bool metro::modifier(QString type , int places ,int id , int depart, QString destination )
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(places);
    QString res2= QString::number(depart);


    query.prepare("update metro set type=:type, places=:places,id=:id,depart=:depart, destination=:destination where id=:id");
    query.bindValue(":type",type);
    query.bindValue(":places",res1 );

    query.bindValue(":id", res);
    query.bindValue(":depart",res2);
    query.bindValue(":destination", destination);
    return query.exec();
}



bool metro::supprimer(int idd)
{

    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from metro where ID = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}


QSqlQueryModel * metro::afficher()
{
    {QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from metro");
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("places"));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("depart"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));
        return model;
    }
}

QSqlQueryModel * metro::chercher_met(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from metro where ((id ) LIKE '%"+aux+"%')");
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("places"));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("depart"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));

    return model;
}


QSqlQueryModel * metro::chercher_met1(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from metro where ((destination ) LIKE '%"+aux+"%')");
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("places"));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("depart"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));

    return model;
}

QSqlQueryModel * metro::chercher_met2(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from metro where ((type ) LIKE '%"+aux+"%')");
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("places"));

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("depart"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));

    return model;
}


QSqlQueryModel* metro::trie()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from metro ORDER BY ID asc");

        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("places"));

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("depart"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));


    return model;
}

QSqlQueryModel* metro::trie2()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from metro ORDER BY ID desc");

        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("places"));

        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("depart"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("destination"));


    return model;
}



int metro::stati1()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from metro where type='marche' ") ;
    while(requete.next())

    {
            count++ ;
    }

return(count);
}
int metro::stati2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from metro where type='panne' ") ;
    while(requete.next())

    {
            count++ ;
    }
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setHeaderData(0,Qt::Vertical,QObject::tr("metro en panne  "));




return(count);
}
int metro::nb_total()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from metro ") ;
    while(requete.next())

    {
            count++ ;
    }

return(count);
}




























