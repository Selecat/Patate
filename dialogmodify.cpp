#include "dialogmodify.h"
#include "dialogmodify.h"
#include "ui_dialogmodify.h"

#include <QRegExpValidator>
#include <QSqlQuery>
#include <QDebug>

DialogModify::DialogModify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModify)
{
    ui->setupUi(this);
}

DialogModify::~DialogModify()
{
    delete ui;
}

void DialogModify::setId(QString sonId)
{
    idAdmin = sonId;
    qDebug()<<"idAdmin dans dialogModify.cpp : "<<idAdmin;
}

void DialogModify::setPrenom(QString lePrenom)
{
    ui->lineEditFNameModifyAdmin->setText(lePrenom);
}

void DialogModify::setNom(QString leNom)
{
    ui->lineEditNameModifyAdmin->setText(leNom);
}

void DialogModify::setLogin(QString leLogin)
{
    ui->lineEditLoginModifyAdmin->setText(leLogin);
}

void DialogModify::setPhone(QString lePhone)
{
    ui->lineEditPhoneModifyAdmin->setText(lePhone);
}

void DialogModify::setMail(QString leMail)
{
    ui->lineEditMailModifyAdmin->setText(leMail);
}

void DialogModify::setRue()
{
    QString txtReqAdresseAdmin = "select rueEmploye from Employe where numeroEmploye = "+ idAdmin;
    qDebug()<<txtReqAdresseAdmin;
    QSqlQuery reqAdresseAdmin(txtReqAdresseAdmin);
    reqAdresseAdmin.first();

    ui->lineEditStreetModifyAdmin->setText(reqAdresseAdmin.value("rueEmploye").toString());
}

void DialogModify::setVille()
{
    QString txtReqAdresseAdmin = "select villeEmploye from Employe where numeroEmploye = "+ idAdmin;
    QSqlQuery reqAdresseAdmin(txtReqAdresseAdmin);
    reqAdresseAdmin.first();

    ui->lineEditCityModifyAdmin->setText(reqAdresseAdmin.value("villeEmploye").toString());

}

void DialogModify::setCp()
{
    QString txtReqAdresseAdmin = "select cpEmploye from Employe where numeroEmploye = "+ idAdmin;
    QSqlQuery reqAdresseAdmin(txtReqAdresseAdmin);
    reqAdresseAdmin.first();

    ui->lineEditDepartementModifyAdmin->setText(reqAdresseAdmin.value("CpEmploye").toString());

}

void DialogModify::on_pushButtonModifyAdministrator_clicked()
{
        ui->lineEditMailModifyAdmin->setValidator(new QRegExpValidator(QRegExp("[a-z0-9._%+-]+@[a-z0-9.-]+\\.[a-z]{2,4}")));
        if(ui->lineEditMailModifyAdmin->hasAcceptableInput())
        {
            ui->lineEditMailModifyAdmin->setStyleSheet("color: green;");
            //récupération des donées
            QString loginAdmin=ui->lineEditLoginModifyAdmin->text();
            QString passAdmin=ui->lineEditPassModifyAdmin->text();
            QString confirmPassAdmin=ui->lineEditConfirmPassModifyAdmin->text();
            QString nameAdmin=ui->lineEditNameModifyAdmin->text();
            QString firstName=ui->lineEditFNameModifyAdmin->text();
            QString phoneAdmin=ui->lineEditPhoneModifyAdmin->text();
            QString mailAdmin=ui->lineEditMailModifyAdmin->text();
            QString streetAdmin=ui->lineEditStreetModifyAdmin->text();
            QString cityAdmin=ui->lineEditCityModifyAdmin->text();
            QString cpAdmin=ui->lineEditDepartementModifyAdmin->text();

            //commande de modification SQL
            if (passAdmin.size() > 8 && passAdmin == confirmPassAdmin) {
                QString reqModifAdmin = "UPDATE Employe SET nomEmploye = '"+nameAdmin+"', prenomEmploye = '"+firstName+"',"
                                                           "rueEmploye = '"+streetAdmin+"', cpEmploye = '"+cpAdmin+"',"
                                                           "MailEmploye = '"+mailAdmin+"', TelEmploye = '"+phoneAdmin+"',"
                                                           "PassEmploye=password('"+passAdmin+"') WHERE numeroEmploye = "+ idAdmin;

                QSqlQuery resModifAdmin (reqModifAdmin);
                qDebug()<<reqModifAdmin;
                resModifAdmin.next();

            //demander à la mainwindow d'ajouter la ligne
            //((MainWindow*)parent())->AfficheAdministrateur();
            //((MainWindow*)parent())->AfficheModerateur();

            close();
        }
        else {
            //tr : text en brute
            ui->labelErrorModify->setText(tr("Passwort is less than 8 or both pass are differents"));
        }
        }
        else
        {
            ui->lineEditMailModifyAdmin->setStyleSheet("color:red");
            ui->lineEditMailModifyAdmin->setValidator(new QRegExpValidator(QRegExp("[a-z0-9._%+-]*@?[a-z0-9.-]*\\.?[a-z]*")));
        }
    }


void DialogModify::on_pushButtonCancelModifyAdministrator_clicked()
{
    close();
}

