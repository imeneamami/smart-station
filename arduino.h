#ifndef ARDUINO_H
#define ARDUINO_H
#include < QSerialPort >  //classe rassemblant des fonctions permettant l'echange es donnés dans une liasion série
#include <QSerialPortInfo> //classe fournissant des informations sur les ports disponibles
#include <QAbstractItemModel>

class Arduino
{


public:  //méthodes de la classe Arduino
    Arduino();
    int connect_arduino(); //permet de connecter le pc à arduino
    int close_arduino(); //permet de fermer la connecion
    int write_to_arduino(QByteArray); //envoyer des données vers arduino
    QByteArray read_from_arduino(); //recevoir des données de la carte Arduino
    QSerialPort* getserial(); //accesseur
    QString getarduino_port_name();



private:
    QSerialPort *serial; //cet objet rassemble des informations (vitesse , bits,etc..)
    static const quint16 arduino_uno_vendor_id=9025;
    static const quint16 arduino_uno_producy_id=67;
    QString arduino_port_name;
    bool arduino_is_available;
    QByteArray data; //contenant les donnés lues à partir d'arduino

};

#endif // ARDUINO_H
