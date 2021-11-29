#include "arduino.h"

    

int Arduino::connect_arduino()
{
    //recherche du port sur lequel la carte arduino identifié par arduino_uno_vendor_id
    //est connectée
    foreach (const QserialPortInfo &serial_port_info,QSerialPortInfo::availablePorts())
    {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info,hasProductIdentifier()){
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&serial_port_info.productIdentifier()==arduino_uno_producy_id){
                arduino_is_available =true;
                arduino_port_name=serial_port_info.portName();
            }
        }
    }
}
QDebug() <<"arduino_port_name is :"<<arduino_port_name();
if (arduino_is_available)
{
    //configuration de la communication (débit ...)
    serial->setPortName(arduino_port_name);
    if(serial->open(QSerialPort::ReadWrite)){

        serial->setBaudRate(QSerialPort::baud9600); //debit :9600 bits/s
        serial->setDataBits(QSerialPort::DataB); //longueur de donnés est 8 bits,
        serial->setParity(QSerialPort::NoParity); //1 bit de parité opionnel
        serial->setStopBits(QSerialPort::OneStop); //nombre de bits de stop : 1
        serial->setFlowControl(QSerialPort::NoFlowControl);
        return 0;

    }
   int arduino::close_arduino
   {
               if (serial->isOpen()){
           serial->close();
           return0;
       }
      }
   QByteArray Arduino::read_from_arduino()
   {
       if(serial->isReadable()){
           data=serial->readAll(); //récupérer les données reçues
           return data;

       }
       }
   }
int Arduino::write_to_arduino(QByteArray d)
{
    if (serial->Writable()) {
        serial->write(d); //envoyer des donnés vers Arduino
        }
    else
    {
        qDebug() <<"couldn't write to serial:";


    }
}
