#include "menu_voyege.h"
#include "ui_menu_voyege.h"
#include "voyage.h"
#include "connexion.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlTableModel>
#include<iostream>
#include <QDebug>
//#include"statistique.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts>
#include<QRegularExpression>
#include"signup.h"
#include"metro.h"
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include<QTextDocument>
#include <QDialog>
#include<QFileInfo>
#include<QFileDialog>
#include<QValidator>
#include "employee.h"
#include <QMessageBox>
#include <QSqlQuery>
#include "qcustomplot.h"
#include <QVector>
#include "smtp.h"

menu_voyege::menu_voyege(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu_voyege)
{
     ui->setupUi(this);
     int ret=A.connect_arduino(); // lancer la connexion à arduino
     switch(ret){
     case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
         break;
     case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
     case(-1):qDebug() << "arduino is not available";
     }
      QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
      //le slot update_label suite à la reception du signal readyRead (reception des données).

     ui->le_id->setValidator(new QIntValidator(100,999999,this));
     ui->le_numtrain->setValidator(new QIntValidator(100,999999,this));
     ui->le_arretd->setValidator(new QRegularExpressionValidator (QRegularExpression("[A-Za-z]+")));
     ui->le_arretf->setValidator(new QRegularExpressionValidator (QRegularExpression("[A-Za-z]+")));
     ui->le_nbrplace->setValidator(new QIntValidator(100,999999,this));
     ui->le_conducteur->setValidator(new QRegularExpressionValidator (QRegularExpression("[A-Za-z]+")));
     ui->ta_voyage->setModel(Etmp.afficher());
}

menu_voyege::~menu_voyege()
{
    delete ui;
}

void menu_voyege::update_label()
{
    data=A.read_from_arduino();

    if(data <="5000")

        ui->label_29->setText("un metro arrive"); // si les données reçues de arduino via la liaison série sont égales à 1
    //QMessageBox::information(nullptr, QObject::tr("train arrivee"),
    //QObject::tr("ouvrir la barriere:"), QMessageBox::Ok);
    // alors afficher ON

    else if (data>"5000")

        ui->label_29->setText("aucun metro detecte");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}


void menu_voyege::on_pb_ajouter_clicked()
{
    int idvoyage=ui->le_id->text().toInt();
    int numtrain=ui->le_numtrain->text().toInt();
    QString arretd=ui->le_arretd->text();
    QString arretf=ui->le_arretf->text();
    int nbrplace=ui->le_nbrplace->text().toInt();
    QString heured=ui->le_heured->text();
    Voyage V(idvoyage,numtrain,arretd,arretf,nbrplace,heured);
    bool test=V.ajouter();

    if (test)

    {
        ui->ta_voyage->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout voyage"),
        QObject::tr("voyage ajouté :"), QMessageBox::Cancel);
    }


}


void menu_voyege::on_pb_modifier_clicked()
{
    if (ui->pb_modifier->isChecked())
          {
              ui->pb_modifier->setDisabled(true);
              ui->pb_modifier->setText("Modifiable");
              QSqlTableModel *tableModel= new QSqlTableModel();
              tableModel->setTable("VOYAGE");
              tableModel->select();
              ui->ta_voyage->setModel(tableModel);
          }
          else
          {
              ui->pb_modifier->setText("Modifier");
              ui->ta_voyage->setModel(V.afficher());

          }


}


void menu_voyege::on_pb_trier_clicked()
{

    Voyage V;

               QString mode;
                if (ui->radioButto_h_asc->isChecked()==true)
           {
                    ui->ta_voyage->setModel(V.trie());


           }
                else if(ui->radioButton_des->isChecked()==true)

                    ui->ta_voyage->setModel(V.trie2());


}


void menu_voyege::on_pb_supprimer_clicked()
{
    Voyage V1;
    V1.setidvoyage(ui->le_idsuprimer->text().toUInt());
    bool test=V1.supprimer(V1.getidvoyage());

    if (test)
     {
       ui->ta_voyage->setModel(Etmp.afficher());

      QMessageBox::information(nullptr, QObject::tr(" suppression voyage "),
                             QObject::tr("voyage supprimé :"), QMessageBox::Cancel);
     }

}


void menu_voyege::on_pb_rechercher_clicked()
{
    Voyage V;
    QString text;

    if (ui->radioButton_id->isChecked()==true)
   {
   text=ui->le_recherche->text();
     if(text == "")
     {
         ui->ta_voyage->setModel(V.afficher());
     }

     else
     {
         ui->ta_voyage->setModel(V.chercher_voyage_id(text));
     }
    }


   if(ui->radioButton_nummetro->isChecked()==true)
    {
        text=ui->le_recherche->text();
             if(text == "")

             {
                 ui->ta_voyage->setModel(V.afficher());

             }

             else

             {
                 ui->ta_voyage->setModel(V.chercher_numtrain(text));
             }

    }

     else if     (ui->radioButton_conducteur->isChecked()==true)
     {

         text=ui->le_recherche->text();
              if(text == "")

              {
                  ui->ta_voyage->setModel(V.afficher());
              }

              else

              {
                  ui->ta_voyage->setModel(V.chercher_conducteur(text));
              }
     }


}


void menu_voyege::on_pushButton_staaat_clicked()
{
    int akther;
               int akal;
               int somme;
               QString akther50;
               QString akal50;
               QSqlQuery q1;

               q1.prepare("SELECT COUNT(*) FROM voyage where nbrplace  BETWEEN '0' AND '50' ");
               q1.exec();
               q1.first() ;
               akther=(q1.value(0).toInt());

               q1.prepare("SELECT COUNT(*) FROM voyage where nbrplace BETWEEN '50' AND '10000' ");
               q1.exec();
               q1.first() ;
               akal=(q1.value(0).toInt());

               q1.prepare("SELECT COUNT(*) FROM voyage ");
               q1.exec();
               q1.first() ;
               somme=(q1.value(0).toInt());

               akther=((double)akther/(double)somme)*100;
               akal=((double)akal/(double)somme)*100;

               akther50= QString::number(akther);
               akal50=QString::number(akal);
               QPieSeries *series1;
                series1= new  QPieSeries();
                series1->append(" moins 50 "+akther50+"%",akther);
                series1->append(" plus 50  "+akal50+"%",akal);
                QPieSlice *slice00 = series1->slices().at(0);
                 slice00->setLabelVisible();

                 QPieSlice *slice01 = series1->slices().at(1);
                    slice01->setExploded();
                    slice01->setLabelVisible();
                    slice01->setPen(QPen(Qt::green, 3));
                    slice01->setBrush(Qt::darkYellow);

                     QChart *chart1 = new QChart();
                     chart1->addSeries(series1);
                     chart1->setTitle("Statistique des types  ");
                     chart1->legend()->show();
                     QChartView *chartView1 = new QChartView(chart1);
                     chartView1->setRenderHint(QPainter::Antialiasing);
                     ui->vertical_layout_stat12->addWidget(chartView1);
                show();
                ui->vertical_layout_stat12->removeWidget(chartView1);
}

void menu_voyege::on_pushButton_clicked()
{
    QString username,password;
    username=ui->lineEdit_Username->text();
    password=ui->lineEdit_Password->text();

    QSqlQuery qry;
    if(qry.exec("select * from SIGNUP where name= '"+username +"' and PASSWORD= '"+password+"'"))
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if (count==1)
        {   QMessageBox::information(nullptr, QObject::tr("Connected"),
                                 QObject::tr("Connexion réussite\n""Click Cancel to exit")
                                 ,QMessageBox::Cancel);
            ui->stackedWidget->setCurrentIndex(1);


        }
        if (count>1)
            QMessageBox::warning(nullptr, QObject::tr("Duplicated"),
                         QObject::tr("Duplication\n""Click Cancel to exit")
                         ,QMessageBox::Cancel);
        if (count<1)
            QMessageBox::warning(nullptr, QObject::tr("Erreur"),
                         QObject::tr("Nom d'utilisateur ou mot de passe incorrecte\n""Click Cancel to exit")
                         ,QMessageBox::Cancel);
    }
}

void menu_voyege::on_pushButton_6_clicked()
{
    QString name=ui->lineEdit_password->text();
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_username->text();
    signup A(username,password, name);
    bool test=A.ajouter();
                if(name.isEmpty()){QMessageBox::warning(nullptr, QObject::tr("Nom et prénom"),
                                                                 QObject::tr("Veuillez indiquer votre nom et prénom\n""Click Cancel to exit")
                                                                 ,QMessageBox::Cancel);}
               /* else if(username.isEmpty()){QMessageBox::warning(nullptr, QObject::tr("Nom d'utilisateur"),
                                                                 QObject::tr("Veuillez indiquer votre nom d'utilisateur\n""Click Cancel to exit")
                                                                 ,QMessageBox::Cancel);}*/
                else if(password.isEmpty()){QMessageBox::warning(nullptr, QObject::tr("Mot de passe"),
                                                                 QObject::tr("Veuillez indiquer votre mot de passe\n""Click Cancel to exit")
                                                                 ,QMessageBox::Cancel);}
                else if (test){
                                QMessageBox::information(nullptr, QObject::tr("OK"),
                                                         QObject::tr("Compte creer\n""Click Cancel to exit")
                                                         ,QMessageBox::Cancel);
                                ui->tabWidget->setCurrentIndex(0);


                }
                else{
                                QMessageBox::warning(nullptr, QObject::tr("OK"),
                                             QObject::tr("Nom d'utilisateur existe déjà\n""Click Cancel to exit")
                                             ,QMessageBox::Cancel);}
}

void menu_voyege::on_pushButton_3_clicked()
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


void menu_voyege::on_pushButton_5_clicked()
{
    metro Etmp;

    {ui->tableView_2->setModel(Etmp.afficher());
        ui->tableView_3->setModel(Etmp.afficher());


    }
}

void menu_voyege::on_pushButton_4_clicked()
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

void menu_voyege::on_pushButton_8_clicked()
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

void menu_voyege::on_pushButton_9_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void menu_voyege::on_recherche_critere_emp_clicked()
{
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
}

void menu_voyege::on_pushButton_10_clicked()
{
    metro e;
    ui->label_stag->setNum(((e.stati1())*100/e.nb_total()));
    ui->label_norm->setNum(((e.stati2())*100/e.nb_total()));

    ui->label_26->setText(" % des metros en panne");
    ui->label_27->setText(" % des metros en marche");

}

void menu_voyege::on_pushButton_trier_salaire_clicked()
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

void menu_voyege::on_pushButton_11_clicked()
{

    int akther;
               int akal;
               int somme;
               QString akther50;
               QString akal50;
               QSqlQuery q1;

               q1.prepare("SELECT COUNT(*) FROM metro where  type='marche' ");
               q1.exec();
               q1.first() ;
               akther=(q1.value(0).toInt());

               q1.prepare("SELECT COUNT(*) FROM metro where type='panne'");
               q1.exec();
               q1.first() ;
               akal=(q1.value(0).toInt());

               q1.prepare("SELECT COUNT(*) FROM metro ");
               q1.exec();
               q1.first() ;
               somme=(q1.value(0).toInt());

               akther=((double)akther/(double)somme)*100;
               akal=((double)akal/(double)somme)*100;

               akther50= QString::number(akther);
               akal50=QString::number(akal);
               QPieSeries *series1;
                series1= new  QPieSeries();
                series1->append(" marche "+akther50+"%",akther);
                series1->append(" panne  "+akal50+"%",akal);
                QPieSlice *slice00 = series1->slices().at(0);
                 slice00->setLabelVisible();

                 QPieSlice *slice01 = series1->slices().at(1);
                    slice01->setExploded();
                    slice01->setLabelVisible();
                    slice01->setPen(QPen(Qt::green, 3));
                    slice01->setBrush(Qt::darkYellow);

                     QChart *chart1 = new QChart();
                     chart1->addSeries(series1);
                     chart1->setTitle("Statistique des types  ");
                     chart1->legend()->show();
                     QChartView *chartView1 = new QChartView(chart1);
                     chartView1->setRenderHint(QPainter::Antialiasing);
                     ui->vertical_layout_stat1->addWidget(chartView1);
                show();
                ui->vertical_layout_stat1->removeWidget(chartView1);

}

void menu_voyege::on_pushButton_pdf_materiel_clicked()
{
    {

        {
            QString strStream;
            QString currentDate = QDateTime().currentDateTime().toString();
            QTextStream out(&strStream);
            const int rowCount = ui->tableView_3->model()->rowCount();
            const int columnCount = ui->tableView_3->model()->columnCount();
            out <<
             "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<QString("<title>%1</title>\n").arg("strTitle")
            <<"</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"
             <<QString(currentDate)
            <<//"<align='right'> " << datefich << "</align>"
            "<center> <img src="":/IMG/IMG/logo2.png"" width=""100"" height=""100"" > <br> <br><H1>LIST OF INGREDIENTS</H1> <br> <br><table border=1 cellspacing=0 cellpadding=2>\n";
            // headers
            out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
            for (int column = 0; column < columnCount; column++)
            if (!ui->tableView_3->isColumnHidden(column))
            out << QString("<th>%1</th>").arg(ui->tableView_3->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";
            // data table
            for (int row = 0; row < rowCount; row++)
            {
            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
            for (int column = 0; column < columnCount; column++)
            {
            if (!ui->tableView_3->isColumnHidden(column))
            {
            QString data = ui->tableView_3->model()->data(ui->tableView_3->model()->index(row, column)).toString().simplified();
            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
            }
            }
            out << "</tr>\n";
            }
            out <<  "</table> </center>\n"
                 "<br> <br> <br> <br>"
            "</body>\n"
            "<footer>\n"
                    "<div class = ""container"">"
                        "<div class = ""row"">"
                            "<div>"
                                "<div><img src="":/IMG/IMG/icons8-facebook-30.png""> <span>Control Patrol TN </div>\n"
                                "<br>"
                                "<div><img src="":/IMG/IMG/icons8-instagram-30.png""> <span>@controlpatrol.tn </div>\n"
                                "<p>Generated from : Control Patrol.exe "
                            "</div>"
                        "</div>"
                    "</div>"
            "</footer>\n"
            "</html>\n";
            QString filter = "pdf (*.pdf) ";
            QString fileName = QFileDialog::getSaveFileName(this, "save in", QDir::homePath(),filter);


            QPrinter printer (QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
            printer.setOutputFileName(fileName);
            QTextDocument doc;
            doc.setHtml(strStream);
            doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
            doc.print(&printer);

    }
    }
}

void menu_voyege::on_pushButton_13_clicked()
{
    {
        QTableView *table;

                            table = ui->tableView_3;


                            QString filters("Excel Files (.xls)");

                            QString defaultFilter("Excel Files (*.xls)");

                            QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),

                                               filters, &defaultFilter);

                            QFile file(fileName);


                            QAbstractItemModel *model =  table->model();

                            if (file.open(QFile::WriteOnly | QFile::Truncate)) {

                                QTextStream data(&file);

                                QStringList strList;

                                for (int i = 0; i < model->columnCount(); i++) {

                                    if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)

                                        strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");

                                    else

                                        strList.append("");

                                }

                                data << strList.join(";") << "\n";

                                for (int i = 0; i < model->rowCount(); i++) {

                                    strList.clear();

                                    for (int j = 0; j < model->columnCount(); j++) {


                                        if (model->data(model->index(i, j)).toString().length() > 0)

                                            strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");

                                        else

                                            strList.append("");

                                    }

                                    data << strList.join(";") + "\n";

                                }

                                file.close();

                                QMessageBox::information(nullptr, QObject::tr("Export excel"),

                                                          QObject::tr("Export avec succes .\n"

                                                                      "Click OK to exit."), QMessageBox::Ok);
            }
    }
}

void menu_voyege::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void menu_voyege::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void menu_voyege::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void menu_voyege::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void menu_voyege::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void menu_voyege::on_pushButton_ajouter_E_clicked()
{
    employee tmp;
    employee e;
        int id = ui->lineEdit_id->text().toInt();
        QString nom= ui->lineEdit_nom->text();
        QString prenom= ui->lineEdit_prenom->text();
        int age= ui->lineEdit_age->text().toInt();
        QString mail= ui->lineEdit_mail->text();
        QString adresse= ui->lineEdit_adresse->text();

      employee E (id,nom,prenom,age,mail,adresse);
      bool test=E.ajouter();

      if(test)
    {
          ui->tableView_employee->setModel(tmp.afficher());//refresh
          QMessageBox msgBox ;
   QMessageBox::information(this,"information","employee ajouté");
               ui->lineEdit_id->setText("");
               ui->lineEdit_nom->setText("");
               ui->lineEdit_prenom->setText("");
               ui->lineEdit_age->setText("");
               ui->lineEdit_mail->setText("");
               ui->lineEdit_adresse->setText("");
  }

  else

  {
  QMessageBox msgBox ;
    msgBox.setText("employee non ajouté ");

  }
}

void menu_voyege::on_pushButton_modifier_E_clicked()
{
    employee tmp;
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    int age= ui->lineEdit_age->text().toInt();
    QString mail= ui->lineEdit_mail->text();
    QString adresse= ui->lineEdit_adresse->text();

          bool test=tmp.modifier(id,nom,prenom,age,mail,adresse);
             if (test)
             {
                  ui->tableView_employee->setModel(tmp.afficher());
                  QMessageBox msgBox ;
           QMessageBox::information(this,"information","employee bien Modifié");
           ui->lineEdit_id->setText("");
           ui->lineEdit_nom->setText("");
           ui->lineEdit_prenom->setText("");
           ui->lineEdit_age->setText("");
           ui->lineEdit_mail->setText("");
           ui->lineEdit_adresse->setText("");

                }
}

void menu_voyege::on_pushButton_rafraichir_E_clicked()
{
    ui->lineEdit_id->setText("");
    ui->lineEdit_nom->setText("");
    ui->lineEdit_prenom->setText("");
    ui->lineEdit_age->setText("");
    ui->lineEdit_mail->setText("");
    ui->lineEdit_adresse->setText("");
}

void menu_voyege::on_pushButton_quitter_clicked()
{
    close();

}

void menu_voyege::on_pushButton_tri_id_clicked()
{
    employee tmp;
    ui->tableView_employee->setModel(tmp.trier_id());

}

void menu_voyege::on_pushButton_tri_nom_clicked()
{
    employee tmp;
    ui->tableView_employee->setModel(tmp.trier_nom());

}

void menu_voyege::on_pushButton_tri_age_clicked()
{
    employee tmp;
    ui->tableView_employee->setModel(tmp.trier_age());

}

void menu_voyege::on_pushButton_chercher_type_clicked()
{
    QString valeur=ui->lineEdit_chercher_nom->text();
        employee *c=new employee();
        ui->tableView_employee->setModel(c->chercher_nom(valeur));
}

void menu_voyege::on_pushButton_chercher_adresse_clicked()
{
    QString valeur=ui->lineEdit_chercher_adresse->text();
        employee *c=new employee();
        ui->tableView_employee->setModel(c->chercher_adresse(valeur));
}

void menu_voyege::on_pushButton_rafraichir_clicked()
{
    employee tmp;
    ui->tableView_employee->setModel(tmp.afficher());
    ui->lineEdit_chercher_nom->setText("");
    ui->lineEdit_chercher_adresse->setText("");
}

void menu_voyege::on_pushButton_supprimer_E_clicked()
{
    employee tmp;
    int id = ui->tableView_employee->model()->data(ui->tableView_employee->model()->index(ui->tableView_employee->selectionModel()->currentIndex().row(),0)).toInt();
    bool test=tmp.supprimer(id);
    if(test)
    {
        ui->tableView_employee->setModel(tmp.afficher());//refresh
        QMessageBox msgBox ;
        QMessageBox::information(this,"information","employee supprimé");
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("employee non Supprimer"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void menu_voyege::on_pushButton_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/Administrateur/Documents/employee/Pdf.pdf");
    QPainter painter(&pdf);
    int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1100,1200,"Liste Des Employee ");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawRect(100,100,7300,2600);

        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"ID Employee");
        painter.drawText(1700,3300,"Nom Employee");
        painter.drawText(3200,3300,"Prenom Employee");
        painter.drawText(4700,3300,"Age Employee");
        painter.drawText(6300,3300,"Mail Employee");
        painter.drawText(7800,3300,"Adresse Employee");


        QSqlQuery query;
        query.prepare("select * from employee");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1700,i,query.value(1).toString());
            painter.drawText(3200,i,query.value(2).toString());
            painter.drawText(4700,i,query.value(3).toString());
            painter.drawText(6300,i,query.value(4).toString());
            painter.drawText(7800,i,query.value(5).toString());

           i = i + 500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Administrateur/Documents/employee/Pdf.pdf"));
                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
            }
}



QVector<double> menu_voyege::Statistique()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT age FROM employee WHERE age<=18");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT age FROM employee WHERE 18<age and age<=25");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT age FROM employee WHERE 25<age and age<=30");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }
    q.prepare("SELECT age FROM employee WHERE 30<age and age<=40");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }
    q.prepare("SELECT age FROM employee WHERE 40<age ");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }
    return stat;
}


void menu_voyege::makePlot()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, menu_voyege::Statistique());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customPlot->replot();

    // move bars above graphs and grid below bars:
    ui->customPlot->addLayer("abovemain", ui->customPlot->layer("main"), QCustomPlot::limAbove);
    ui->customPlot->addLayer("belowmain", ui->customPlot->layer("main"), QCustomPlot::limBelow);
    ui->customPlot->xAxis->grid()->setLayer("belowmain");
    ui->customPlot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6<<7;
    QVector<QString> labels;
    labels<<"0-18"<<"18-25"<<"25-30"<<"30-40"<<"40+"<<"ans";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0,4);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customPlot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customPlot->xAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customPlot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customPlot->axisRect()->setBackground(axisRectGradient);

    ui->customPlot->rescaleAxes();
    ui->customPlot->xAxis->setRange(0, 7);
    ui->customPlot->yAxis->setRange(0, 10);


}

void menu_voyege::on_pushButton_statistique_clicked()
{
    menu_voyege::makePlot();

}

void menu_voyege::on_pushButton_envoyer_mail_clicked()
{
    Smtp* smtp = new Smtp("daly.walha@gmail.com","yoser-2000","smtp.gmail.com",465);
    connect (smtp, SIGNAL (status (QString)), this, SLOT (mailSent(QString)));
    smtp->sendMail("daly.walha@gmail.com", ui->lineEdit_mail_2->text(), ui->subject->text(), ui->msg->toPlainText());
    ui->lineEdit_mail_2->setText("");
     ui->subject->setText("");
             ui->msg->setText("");
}

//arduino fourat
/*
void menu_voyege::update_label()
{
    data=A.read_from_arduino();

    QMessageBox::information(nullptr, QObject::tr("marche"),

                              QObject::tr("succes .\n"

                                          "Click OK to exit."), QMessageBox::Ok);

 //   if(data<"30")

   //     ui->label_17->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON


    //else

      //  ui->label_17->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher OF
}*/



// arduino employee
/*
void menu_voyege ::update_label()
{
    data=A.read_from_arduino();
    if (data=="1")
        ui->label_3->setText("ON"); //si les donnes reçues de arduino via la liaison série sont égales a 1
    //alors afficher ON
    else if(data=="0")
        ui->label_3->setText("OFF");
}

void MainWindow::on_pushButton_clicked() //implémentation du slot bouton on
{
    A.write_to_arduino("1"); //envoyer 1 à arduino
}
void MainWindow::on_pushButton_2_clicked() //implémentation du slot bouton off
   A.write_to_arduino("0"); //envoyer 0 a arduino
*/

void menu_voyege::on_pushButton_rafraichir_E_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void menu_voyege::on_label_27_linkActivated(const QString &link)
{

}

void menu_voyege::on_pushButton_21_clicked()//push btn pour ouvrir la barriere et afficher le message dans lcd
{
     A.write_to_arduino("1"); //envoyer 1 à arduino
}
