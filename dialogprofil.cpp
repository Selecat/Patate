#include "dialogprofil.h"
#include "ui_dialogprofil.h"

DialogProfil::DialogProfil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogProfil)
{
    ui->setupUi(this);
}

DialogProfil::~DialogProfil()
{
    delete ui;
}
