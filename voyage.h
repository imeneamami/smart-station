#ifndef VOYAGE_H
#define VOYAGE_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include "connexion.h"
#include <QDebug>
#include <QFileDialog>
#include <QtDebug>
#include <QMessageBox>
#include <QDateTime>



class Voyage
{

public:
    Voyage();
    Voyage(int,int,QString,QString,int,QString);
    int getidvoyage();
    int getnumtrain();
    QString getarretd();
    QString getarretf();
     int getnbrplace();
    QString getheure();

    void setidvoyage(int);
     void setnumtrain(int);
     void setarretd(QString);
     void setarretf(QString);
     void setnbrplace(int);
     void setheure(QString);

  QSqlQueryModel * afficher();

    bool ajouter();
    bool modifier();
    bool supprimer(int);
    QSqlQueryModel * trie();
    QSqlQueryModel * trie2();
    QSqlQueryModel *chercher_voyage_id(const QString &aux);
    QSqlQueryModel *chercher_numtrain(const QString &aux);
    QSqlQueryModel *chercher_conducteur(const QString &aux);

private:
   int idvoyage;
    int numtrain;
    QString arretd;
    QString arretf;
    int nbrplace;
    QString heured;


};

#endif // VOYAGE_H
