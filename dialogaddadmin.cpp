#include "dialogaddadmin.h"
#include "ui_dialogaddadmin.h"
#include "mainwindow.h"

#include <QSqlQuery>
#include <QDebug>
#include <QRegExpValidator>
DialogAddAdmin::DialogAddAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddAdmin)
{
    ui->setupUi(this);
    //QRegExp regExpEmail("(?:[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*|(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21\x23-\x5b\x5d-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])*")@(?:(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?|\[(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?|[a-z0-9-]*[a-z0-9]:(?:[\x01-\x08\x0b\x0c\x0e-\x1f\x21-\x5a\x53-\x7f]|\\[\x01-\x09\x0b\x0c\x0e-\x7f])+)\])");
    //QRegExp regExpEmail("[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}");

}

DialogAddAdmin::~DialogAddAdmin()
{
    delete ui;
}

void DialogAddAdmin::on_pushButtonAddAdministrator_clicked()
{
    ui->lineEditMailAddAdmin->setValidator(new QRegExpValidator(QRegExp("[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}")));
    if(ui->lineEditMailAddAdmin->hasAcceptableInput())
    {
        ui->lineEditMailAddAdmin->setStyleSheet("color: green;");
        //récupération des donées
        QString loginAdmin=ui->lineEditLoginAddAdmin->text();
        QString passAdmin=ui->lineEditPassAddAdmin->text();
        QString confirmPassAdmin=ui->lineEditConfirmPassAddAdmin->text();
        QString nameAdmin=ui->lineEditNameAddAdmin->text();
        QString firstName=ui->lineEditFNameAddAdmin->text();
        QString phoneAdmin=ui->lineEditPhoneAddAdmin->text();
        QString mailAdmin=ui->lineEditMailAddAdmin->text();
        QString streetAdmin=ui->lineEditStreetAddAdmin->text();
        QString cityAdmin=ui->lineEditCityAddAdmin->text();
        QString cpAdmin=ui->lineEditDepartementAddAdmin->text();


        if (passAdmin == confirmPassAdmin) {
            QString reqAddAdmin = "INSERT INTO Employe (loginEmploye, PassEmploye, nomEmploye, PrenomEmploye, TelEmploye, MailEmploye, rueEmploye, villeEmploye, CpEmploye, numeroTypeEmploye) Values('"+loginAdmin+"', password('"+passAdmin+"'), '"+nameAdmin+"', '"+firstName+"', '"+phoneAdmin+"', '"+mailAdmin+"', '"+streetAdmin+"', '"+cityAdmin+"', "+cpAdmin+", "+((MainWindow*)parent())->typeEmployeDialog+")";
            QSqlQuery resAddAdmin (reqAddAdmin);
            qDebug()<<reqAddAdmin;
            resAddAdmin.next();

        //demander à la mainwindow d'ajouter la ligne
        ((MainWindow*)parent())->AfficheAdministrateur();
        ((MainWindow*)parent())->AfficheModerateur();

        close();
    }
    else {
        //tr : text en brute
        ui->labelError->setText(tr("Both password are differents"));
    }
    }
    else
    {
        ui->lineEditMailAddAdmin->setStyleSheet("color:red");
        ui->lineEditMailAddAdmin->setValidator(new QRegExpValidator(QRegExp("[a-z0-9._%+-]*@?[a-z0-9.-]*\\.?[a-z]*")));
    }
}

void DialogAddAdmin::on_pushButtonCancelAddAdministrator_clicked()
{
    close();
}
