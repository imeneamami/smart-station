#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employee.h"
#include <QMessageBox>
#include <QSqlQuery>
#include "qcustomplot.h"
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(tmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_E_clicked()
{
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
          ui->tableView->setModel(tmp.afficher());//refresh
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


void MainWindow::on_pushButton_supprimer_E_clicked()
{
    int id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toInt();
    bool test=tmp.supprimer(id);
    if(test)
    {
        ui->tableView->setModel(tmp.afficher());//refresh
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


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    ui->lineEdit_id->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->lineEdit_nom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->lineEdit_prenom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
    ui->lineEdit_age->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString());
    ui->lineEdit_mail->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),4)).toString());
    ui->lineEdit_adresse->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),5)).toString());

}


void MainWindow::on_pushButton_modifier_E_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    int age= ui->lineEdit_age->text().toInt();
    QString mail= ui->lineEdit_mail->text();
    QString adresse= ui->lineEdit_adresse->text();

          bool test=tmp.modifier(id,nom,prenom,age,mail,adresse);
             if (test)
             {
                  ui->tableView->setModel(tmp.afficher());
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


void MainWindow::on_pushButton_rafraichir_E_clicked()
{
    ui->lineEdit_id->setText("");
    ui->lineEdit_nom->setText("");
    ui->lineEdit_prenom->setText("");
    ui->lineEdit_age->setText("");
    ui->lineEdit_mail->setText("");
    ui->lineEdit_adresse->setText("");

}


void MainWindow::on_pushButton_quitter_clicked()
{
    close();
}


void MainWindow::on_pushButton_2_quitter_clicked()
{
    close();
}


void MainWindow::on_pushButton_rafraichir_clicked()
{
    ui->tableView->setModel(tmp.afficher());
    ui->lineEdit_chercher_nom->setText("");
    ui->lineEdit_chercher_adresse->setText("");
}


void MainWindow::on_pushButton_tri_id_clicked()
{
    ui->tableView->setModel(tmp.trier_id());
}


void MainWindow::on_pushButton_tri_nom_clicked()
{
    ui->tableView->setModel(tmp.trier_nom());
}


void MainWindow::on_pushButton_tri_age_clicked()
{
    ui->tableView->setModel(tmp.trier_age());
}


void MainWindow::on_pushButton_chercher_type_clicked()
{
    QString valeur=ui->lineEdit_chercher_nom->text();
        employee *c=new employee();
        ui->tableView->setModel(c->chercher_nom(valeur));
}


void MainWindow::on_pushButton_chercher_adresse_clicked()
{
    QString valeur=ui->lineEdit_chercher_adresse->text();
        employee *c=new employee();
        ui->tableView->setModel(c->chercher_adresse(valeur));
}


void MainWindow::on_pushButton_pdf_clicked()
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
QVector<double> MainWindow::Statistique()
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
void MainWindow::makePlot()
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
    bars1->setData(x3, MainWindow::Statistique());
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

void MainWindow::on_pushButton_statistique_clicked()
{
    MainWindow::makePlot();
}

