#ifndef MAILING_H
#define MAILING_H

#include <QObject>
#include "smtp.h"

class mailing : public QObject
{
public:
    mailing();
    mailing(QString, QString );

    ~mailing();

    //    int GetTelephone(){return telephone;}
    QString GetAdresse(){return adresse;}
    QString GetMessage(){return message;}

    void setAdresse (QString ad){adresse=ad;}
    void setMessage(QString msg){message=msg;}

private:
    QString adresse;
    QString message;
};

#endif // MAILING_H
