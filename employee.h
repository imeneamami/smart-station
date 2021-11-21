#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employee
{
public:
    employee();
    employee(int,QString,QString,int,QString,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    int get_age();
    QString get_mail();
    QString get_adresse();



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,int,QString,QString);

    QSqlQueryModel * chercher_nom(QString);
    QSqlQueryModel * chercher_adresse(QString);
    QSqlQueryModel * trier_id();
    QSqlQueryModel * trier_nom();
    QSqlQueryModel * trier_age();

private:
    QString nom,prenom,mail,adresse;
    int id,age;
};

#endif // EMPLOYEE_H
