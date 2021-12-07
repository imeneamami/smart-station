#ifndef MENU_VOYEGE_H
#define MENU_VOYEGE_H

#include <QMainWindow>
#include <QMessageBox>
#include "connexion.h"
#include "voyage.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class menu_voyege; }
QT_END_NAMESPACE

class menu_voyege : public QMainWindow
{
    Q_OBJECT

public:
    menu_voyege(QWidget *parent = nullptr);
    ~menu_voyege();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_modifier_clicked();

    void on_pb_trier_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_rechercher_clicked();

    void on_pushButton_staaat_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_recherche_critere_emp_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_trier_salaire_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_pdf_materiel_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_ajouter_E_clicked();

    void on_pushButton_modifier_E_clicked();

    void on_pushButton_rafraichir_E_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButton_tri_id_clicked();

    void on_pushButton_tri_nom_clicked();

    void on_pushButton_tri_age_clicked();

    void on_pushButton_chercher_type_clicked();

    void on_pushButton_chercher_adresse_clicked();

    void on_pushButton_rafraichir_clicked();

    void on_pushButton_supprimer_E_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_statistique_clicked();
    void makePlot();
    QVector<double> Statistique();


    void on_pushButton_envoyer_mail_clicked();

    // arduino
    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

    void on_label_17_linkActivated(const QString &link); //label_17

    void on_pushButton_rafraichir_E_2_clicked();

    void on_label_27_linkActivated(const QString &link);

    void on_pushButton_21_clicked(); // envoyer  a larduino pour ouvrir la barriere et afficher le meddage sur lecran lcd


private:
    Ui::menu_voyege *ui;
    Voyage V;
    Voyage Etmp;
    QByteArray data; // variable contenant les données reçues
    /*QByteArray data;*/ // variable contenant les données reçues

    Arduino A; // objet temporaire

};
#endif // MENU_VOYEGE_H
