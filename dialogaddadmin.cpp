#include "dialogaddadmin.h"
#include "ui_dialogaddadmin.h"

DialogAddAdmin::DialogAddAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddAdmin)
{
    ui->setupUi(this);
}

DialogAddAdmin::~DialogAddAdmin()
{
    delete ui;
}

void DialogAddAdmin::on_pushButtonAddAdministrator_clicked()
{
    QString reqAddAdmin = "INSERT INTO Employe loginEmploye, PassEmploye, nomEmploye, PrenomEmploye, TelEmploye, MailEmploye, rueEmploye, villeEmploye, CpEmploye";

}


void DialogAddAdmin::on_pushButtonCancelAddAdministrator_clicked()
{
    close();
}

