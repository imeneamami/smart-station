   #ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employes.h"

#include <QMainWindow>
QT_BEGIN_NAMESPACE

namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();


    void on_pb_se_connecter_clicked();

    void on_le_mailing_clicked();

    void on_pb_envoyer_clicked();

    void on_pb_supprimer_2_clicked();

private:
    Ui::MainWindow *ui;
    Employes E;
};

#endif // MAINWINDOW_H
