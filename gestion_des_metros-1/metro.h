#ifndef metro_H
#define metro_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class metro
{
private:
    QString type, destination;
    int id , depart,places;
public:
    //constructeurs
    metro(){}; //par_defaut
    metro(int,QString,int,QString,int); //parametre
    // getters
    QString getTYPE(){return type;}
    QString getdestination(){return destination;}
    int getid(){return id;}
    int getdepart(){return depart;}
    int getplaces(){return places;}
    //setters
    void setType(QString n ){type=n;}
    void setdestination(QString p){destination=p;}
    void setid(int d){id=d;}
    void setdepart(int id){depart=id;}
    void setplaces(int salaire){places=salaire;}
    //fonctions de base relative a l'entite metro
    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(QString,int,int,int,QString);
    bool supprimer(int);
    QSqlQueryModel *chercher_met(const QString &aux);
    QSqlQueryModel *chercher_met1(const QString &aux);
    QSqlQueryModel *chercher_met2(const QString &aux);
    QSqlQueryModel* trie();
    QSqlQueryModel* trier(const QString, const QString);
    QSqlQueryModel* trie2();
    int stati();
    int stati1();
    int stati2();
    int nb_total();






};

#endif // metro_H
