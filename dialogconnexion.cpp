#include "dialogconnexion.h"
#include "ui_dialogconnexion.h"

#include <QDebug>
#include <QSqlQuery>
/**
 * @brief DialogConnexion::DialogConnexion
 * @param parent
 * @author Lopez Jonathan
 */
DialogConnexion::DialogConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnexion)
{
    ui->setupUi(this);
}

DialogConnexion::~DialogConnexion()
{
    delete ui;
}

void DialogConnexion::on_pushButton_clicked()
{
    login=ui->lineEditLogin->text();
    pass=ui->lineEditPass->text();

    QString connect ="select count(*) from Employe where loginEmploye='"+login+"' and PassEmploye=password('"+pass+"')";
    qDebug()<<connect;
    QSqlQuery verif(connect);
    verif.next();
    bool bverif=verif.value(0).toInt();
    qDebug()<<bverif;
    if (bverif) {
        accept();
    }
    else {
        ui->labelError->setText("login ou mot de passe faux, veuillez réessayer");
    }
    QString typeConnexion ="select numeroTypeEmploye from Employe where loginEmploye='"+login+"'";
    qDebug()<<typeConnexion;
    QSqlQuery typeConnect(typeConnexion);
    typeConnect.next();
    type = typeConnect.value(0).toInt();
    //qDebug()<<type;
}

int DialogConnexion::getType()
{
    return type;
}
