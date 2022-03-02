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
