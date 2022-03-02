#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStackedWidget>
#include <QDebug>

MainWindow::MainWindow(int leType, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<leType;
    switch (leType) {

        case 1: ui->stackedWidget->setCurrentIndex(0);
        break;
        case 2: ui->stackedWidget->setCurrentIndex(1);
        break;
        case 3: ui->stackedWidget->setCurrentIndex(2);
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
