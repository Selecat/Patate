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
    //récupération des donées
    QString loginAdmin=ui->lineEditLoginAddAdmin->text();
    QString passAdmin=ui->lineEditPassAddAdmin->text();
    QString nameAdmin=ui->lineEditNameAddAdmin->text();
    QString firstName=ui->lineEditFNameAddAdmin->text();
    QString phoneAdmin=ui->lineEditPhoneAddAdmin->text();
    QString mailAdmin=ui->lineEditMailAddAdmin->text();
    QString streetAdmin=ui->lineEditStreetAddAdmin->text();
    QString cityAdmin=ui->lineEditCityAddAdmin->text();
    QString cpAdmin=ui->lineEditDepartementAddAdmin->text();

    QString reqAddAdmin = "INSERT INTO Employe loginEmploye, PassEmploye, nomEmploye, PrenomEmploye, TelEmploye, MailEmploye, rueEmploye, villeEmploye, CpEmploye Values("+loginAdmin+", password("+passAdmin+"), "+nameAdmin+", "+firstName+", "+phoneAdmin+", "+mailAdmin+", "+streetAdmin+", "+cityAdmin+", "+cpAdmin+")";

}

void DialogAddAdmin::on_pushButtonCancelAddAdministrator_clicked()
{
    close();
}
