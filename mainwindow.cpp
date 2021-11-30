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
#include "piechartwidget.h"
#include "signup.h"


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



void MainWindow::on_pushButton_9_clicked()
{
    metro e;
    ui->label_stag->setNum(((e.stati1())*100/e.nb_total()));
    ui->label_norm->setNum(((e.stati2())*100/e.nb_total()));

    ui->label_14->setText(" % des metros en panne");
    ui->label_15->setText(" % des metros en marche");

}


void MainWindow::on_pushButton_8_clicked()
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




void MainWindow::on_pushButton_pdf_materiel_clicked()
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


void MainWindow::on_pushButton_clicked()
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
            ui->tabWidget->setCurrentIndex(1);


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

void MainWindow::on_pushButton_6_clicked()
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

void MainWindow::on_pushButton_7_clicked()
{
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_11_clicked()
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


/*-----Arduino-----*/

void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data<="40")
{
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("un metro arrive \n clicker ok pour ouvrir la barriere."), QMessageBox::Ok);


}
