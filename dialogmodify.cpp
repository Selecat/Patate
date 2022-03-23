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
    QString txtReqAdresseAdmin = "select rueEmploye, villeEmploye, CpEmploye from Employe where nomeroEmploye = "+ idAdmin;
    QSqlQuery reqAdresseAdmin(txtReqAdresseAdmin);
    reqAdresseAdmin.first();

    ui->lineEditStreetModifyAdmin->setText(reqAdresseAdmin.value("rueEmploye").toString());
    ui->lineEditCityModifyAdmin->setText(reqAdresseAdmin.value("villeEmploye").toString());
    ui->lineEditDepartementModifyAdmin->setText(reqAdresseAdmin.value("CpEmploye").toString());
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


            if (passAdmin == confirmPassAdmin) {
                QString reqAddAdmin;// = "INSERT INTO Employe (loginEmploye, PassEmploye, nomEmploye, PrenomEmploye, TelEmploye, MailEmploye, rueEmploye, villeEmploye, CpEmploye, numeroTypeEmploye) Values('"+loginAdmin+"', password('"+passAdmin+"'), '"+nameAdmin+"', '"+firstName+"', '"+phoneAdmin+"', '"+mailAdmin+"', '"+streetAdmin+"', '"+cityAdmin+"', "+cpAdmin+", "+((MainWindow*)parent())->typeEmployeDialog+")";
                QSqlQuery resAddAdmin (reqAddAdmin);
                qDebug()<<reqAddAdmin;
                resAddAdmin.next();

            //demander à la mainwindow d'ajouter la ligne
            //((MainWindow*)parent())->AfficheAdministrateur();
            //((MainWindow*)parent())->AfficheModerateur();

            close();
        }
        else {
            //tr : text en brute
            ui->labelErrorModify->setText(tr("Both password are differents"));
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

