#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //explicit MainWindow(QWidget *parent = nullptr);
    //~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_recherche_critere_emp_clicked();

    void on_pushButton_trier_salaire_clicked();

    void on_pushButton_pdf_materiel_clicked();
    void pdf();
    void pdf_ing();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_8_clicked(bool checked);

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    /*arduino*/
    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
