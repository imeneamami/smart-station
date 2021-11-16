#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "metro.h"
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include<QTextDocument>
#include <QDialog>
#include<QFileInfo>
#include<QFileDialog>
#include<QValidator>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QValidator *validator_String=new QRegExpValidator(QRegExp("[A-Za-z ' ']+"),this);
    ui->lineEdit_destination->setValidator(validator_String);


      ui->lineEdit_id->setValidator(new QIntValidator(1, 240, this));
        ui->lineEdit_places->setValidator(new QIntValidator(10, 500, this));
          ui->lineEdit_depart->setValidator(new QIntValidator(1, 24, this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    {
        metro h;
        metro Etmp;
        int id=ui->lineEdit_id->text().toInt();
        int places=ui->lineEdit_places->text().toInt();
        int depart=ui->lineEdit_depart->text().toInt();
        QString type;

        QString destination=ui->lineEdit_destination->text();
        if     (ui->checkBox_panne->isChecked()==true)
        {
             type=ui->checkBox_panne->text();
        }
        if(ui->checkBox_marche->isChecked()==true)
        {
             type=ui->checkBox_marche->text();
        }

    metro E(id,destination,places,type,depart);
    bool test=E.ajouter();
    if(test)
    {
        ui->tableView_2->setModel(Etmp.afficher());
        ui->tableView_3->setModel(Etmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("ajout effectue \n click cancel to exit."), QMessageBox::Cancel);
    }

    }
}

void MainWindow::on_pushButton_4_clicked()
{
    metro Etmp;
    Etmp.setid(ui->lineEdit_id->text().toInt());
    QMessageBox msgbox;
        msgbox.setWindowTitle("supprimer");
        msgbox.setText("voulez_vous supprimer cette réclamation?");
        msgbox.setStandardButtons(QMessageBox ::Yes);
        msgbox.addButton(QMessageBox::No);
        if(msgbox.exec()==QMessageBox::Yes)
        {
  bool test=Etmp.supprimer(Etmp.getid());
  QMessageBox msgBox;

  if(test)
  {

      QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("suppression effectuée \n click cancel to exit."), QMessageBox::Cancel);
      {ui->tableView_2->setModel(Etmp.afficher());
          ui->tableView_3->setModel(Etmp.afficher());


      }


  }
  else
      QMessageBox::critical(nullptr,QObject::tr("NOT OK"),QObject::tr("suppression non effectuer.\n click cancel to exis."), QMessageBox::Cancel);
  msgBox.exec();

}
}

void MainWindow::on_pushButton_5_clicked()
{
    metro Etmp;

    {ui->tableView_2->setModel(Etmp.afficher());
        ui->tableView_3->setModel(Etmp.afficher());


    }
}

void MainWindow::on_pushButton_3_clicked()
{
    metro p;
        int id = ui->lineEdit_id_2->text().toInt();
        int depart= ui->lineEdit_depart_2->text().toInt();
        int places= ui->lineEdit_places_2->text().toInt();

        QString type = ui->lineEdit_etat_2->text();
        QString destination = ui->lineEdit_destination_2->text();


        metro (id,destination,places,type,depart);
        bool test =p.modifier(type,places,id,depart,destination);
        if(test)
        {ui->tableView_2->setModel(p.afficher());
            ui->tableView_3->setModel(p.afficher());

            QMessageBox::information(nullptr, QObject::tr("modifier un metro"),
                                     QObject::tr("metro  modifié.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier un metro"),
                                  QObject::tr("Erreur !.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_recherche_critere_emp_clicked()
{
    metro e;
    QString text;
    if (ui->radioButton_ID->isChecked()==true)
{
text=ui->line_recherche_critere->text();
     if(text == "")

     {

         ui->tableView_2->setModel(e.afficher());

     }

     else

     {



         ui->tableView_2->setModel(e.chercher_met(text));

     }
    }
     if(ui->radioButton_salaire->isChecked()==true)
    {
        text=ui->line_recherche_critere->text();
             if(text == "")

             {

                 ui->tableView_2->setModel(e.afficher());

             }

             else

             {



                 ui->tableView_2->setModel(e.chercher_met1(text));

             }

    }
     else if     (ui->radioButton_nom->isChecked()==true)
     {

         text=ui->line_recherche_critere->text();
              if(text == "")

              {

                  ui->tableView_2->setModel(e.afficher());

              }

              else

              {



                  ui->tableView_2->setModel(e.chercher_met2(text));

              }
     }
}


void MainWindow::on_pushButton_trier_salaire_clicked()
{
    metro e;
        QString mode;
         if (ui->rb_asc_historique->isChecked()==true)
    {
             ui->tableView_2->setModel(e.trie());


    }
         else if(ui->rb_desc_historique->isChecked()==true)

             ui->tableView_2->setModel(e.trie2());
}

void MainWindow::on_pushButton_pdf_materiel_clicked()
{
    QDialog QFileDialog;
     QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append("metro.pdf"); }

             QPrinter printer(QPrinter::PrinterResolution);
             printer.setOutputFormat(QPrinter::PdfFormat);
             printer.setPaperSize(QPrinter::A4);
             printer.setOutputFileName(fileName);

             /*QPrinter printer;*/
             ui->tableView_2->render(&printer);




             QTextDocument doc;
             QSqlQuery q;
             q.prepare("SELECT * FROM metro ");
             q.exec();
             QString pdf="<br> <img src='D:/Esprit/2A2/projet c++/logo/debug2.png' height='42' width='144'/> <h1  style='color:red'>LISTE DES RECLAMATION  <br></h1>\n <br> <table>  <tr>  <th> CODE </th> <th> SUJET </th> <th> COMMENTAIRE </th> <th> DATE AJOUT </th>  </tr>" ;


             while ( q.next()) {

                 pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"    </td>   <td>   " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"  "" " "</td>   <td>"+q.value(3).toString()+"</td>    <td>"+q.value(4).toString()+" </td>" ;

             }
             doc.setHtml(pdf);
             doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
          /*   doc.print(&printer);*/
             ui->tableView_2->render(&printer);
}

void MainWindow::on_pushButton_9_clicked()
{
    metro e;
    ui->label_stag->setNum(((e.stati1())*100/e.nb_total()));
    ui->label_norm->setNum(((e.stati2())*100/e.nb_total()));

    ui->label_14->setText(" % des metros en panne");
    ui->label_15->setText(" % des metros en marche");

}
