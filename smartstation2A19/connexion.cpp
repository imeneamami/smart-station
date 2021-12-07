#include "connexion.h"

Connexion::Connexion()
{

}
bool Connexion::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("SMART");//inserer le nom de la source de données ODBC
db.setUserName("emna");//inserer nom de l'utilisateur
db.setPassword("gharbi");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
