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
    int getId();
    QString getPrenom(){return Prenom;}
    QString getNom(){return Nom;}
    QString getAdresse(){return Adresse;}
    QString getMail(){return Mail;}
    QString getAge(){return Age;}
    void setId(int);
    void setNom(QString);
    void setPrenom(QString);
    void setAge(QString);
    void setAdresse(QString);
    void setMail(QString);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool Modifier(int);

private:
    int Id;
    QString Prenom,Nom,Adresse, Mail, Age ;
};

#endif // EMPLOYES_H
