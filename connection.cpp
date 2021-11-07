#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");


db.setDatabaseName("smart");//inserer le nom de la source de données ODBC
db.setUserName("test");//inserer nom de l'utilisateur
db.setPassword("imen123");//inserer mot de passe de cet utilisateur

if (db.open())
    return true;

}

