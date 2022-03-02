#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCheckBox>
#include <QSqlQuery>
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

    //variable ligne
    int ligne =0;


    //SET NB COLONNES
    ui->tableWidgetAdministrateur->setColumnCount(7);

    //stretch du tableau
    ui->tableWidgetAdministrateur->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //requete affichage Administrateurs
    QString adminQuery ="select numeroEmploye, nomEmploye, prenomEmploye, concat(rueEmploye, villeEmploye, CpEmploye), MailEmploye, TelEmploye, PassEmploye, loginEmploye, numeroTypeEmploye, supprEmploye from Employe where numeroTypeEmploye = 2";
    QSqlQuery adminResult(adminQuery);
    while (adminResult.next()) {
        ligne++;

        //ajout des lignes et colonnes
        ui->tableWidgetAdministrateur->setRowCount(ligne);

        //XITgfUibs1456
        //login
        ui->tableWidgetAdministrateur->setItem(ligne-1,0,new QTableWidgetItem(adminResult.value("loginEmploye").toString()));
        //nomsupprEmploye
        ui->tableWidgetAdministrateur->setItem(ligne-1,1,new QTableWidgetItem(adminResult.value("nomEmploye").toString()));
        //prenom
        ui->tableWidgetAdministrateur->setItem(ligne-1,2,new QTableWidgetItem(adminResult.value("prenomEmploye").toString()));
        //tel
        ui->tableWidgetAdministrateur->setItem(ligne-1,3,new QTableWidgetItem(adminResult.value("TelEmploye").toString()));
        //mail
        ui->tableWidgetAdministrateur->setItem(ligne-1,4,new QTableWidgetItem(adminResult.value("MailEmploye").toString()));
        //@
        ui->tableWidgetAdministrateur->setItem(ligne-1,5,new QTableWidgetItem(adminResult.value("concat(rueEmploye, villeEmploye, CpEmploye)").toString()));
        //checkbox
        ui->tableWidgetAdministrateur->setCellWidget(ligne-1,6, new QCheckBox);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
