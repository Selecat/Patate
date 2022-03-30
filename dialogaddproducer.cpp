#include "dialogaddproducer.h"
#include "ui_dialogaddproducer.h"

DialogAddProducer::DialogAddProducer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddProducer)
{
    ui->setupUi(this);
}

DialogAddProducer::~DialogAddProducer()
{
    delete ui;
}
