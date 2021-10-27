#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employes
{

    
public:
    Employes();
    Employes(int,QString,QString,QString,QString,QString);
    QString get_Prenom(){return Prenom;}
    QString get_Nom(){return Nom;}
    QString get_Adresse(){return Adresse;}
    QString get_Email(){return Email;}
    QString get_Age(){return Age;}
    int get_Id(){return Id;}
    bool ajouter();
    bool supprimer(int);
    bool Modifier(int);
    QSqlQueryModel* afficher();
private:
    int Id;
    QString Prenom,Nom,Adresse, Email, Age ;
};

#endif // EMPLOYES_H
