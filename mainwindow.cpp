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

AfficheAdministrateur();
AfficheModerateur();
AfficheProducteur();

AfficheModerateurAdmin();
AfficheProducteurAdmin();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//XITgfUibs1456


void MainWindow::AfficheAdministrateur()
{
    //initialisation ligne
    ligne=0;

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

void MainWindow::AfficheModerateur()
{
    //initialisation ligne
    ligne=0;

    //SET NB COLONNES
    ui->tableWidgetModerateur->setColumnCount(7);

    //stretch du tableau
    ui->tableWidgetModerateur->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //requete affichage Administrateurs
    QString reqModo ="select numeroEmploye, nomEmploye, prenomEmploye, concat(rueEmploye, villeEmploye, CpEmploye), MailEmploye, TelEmploye, PassEmploye, loginEmploye, numeroTypeEmploye, supprEmploye from Employe where numeroTypeEmploye = 3";
    QSqlQuery resModo(reqModo);
    while (resModo.next()) {
        ligne++;

        //ajout des lignes et colonnes
        ui->tableWidgetModerateur->setRowCount(ligne);

        //odubic
        //login
        ui->tableWidgetModerateur->setItem(ligne-1,0,new QTableWidgetItem(resModo.value("loginEmploye").toString()));
        //nomsupprEmploye
        ui->tableWidgetModerateur->setItem(ligne-1,1,new QTableWidgetItem(resModo.value("nomEmploye").toString()));
        //prenom
        ui->tableWidgetModerateur->setItem(ligne-1,2,new QTableWidgetItem(resModo.value("prenomEmploye").toString()));
        //tel
        ui->tableWidgetModerateur->setItem(ligne-1,3,new QTableWidgetItem(resModo.value("TelEmploye").toString()));
        //mail
        ui->tableWidgetModerateur->setItem(ligne-1,4,new QTableWidgetItem(resModo.value("MailEmploye").toString()));
        //@
        ui->tableWidgetModerateur->setItem(ligne-1,5,new QTableWidgetItem(resModo.value("concat(rueEmploye, villeEmploye, CpEmploye)").toString()));
        //checkbox
        ui->tableWidgetModerateur->setCellWidget(ligne-1,6, new QCheckBox);
    }
}

void MainWindow::AfficheProducteur()
{
    //initialisation ligne
    ligne=0;

    //SET NB COLONNES
    ui->tableWidgetProducteur->setColumnCount(7);

    //stretch du tableau
    ui->tableWidgetProducteur->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //requete affichage Administrateurs
    QString reqModo ="select numeroproducteur, loginProducteur, nomProducteur, prenomProducteur, adresseProducteur, telProducteur, mailProducteur, validiteProducteur from Producteur where validiteProducteur = 1";
    QSqlQuery resModo(reqModo);
    while (resModo.next()) {
        ligne++;

        //ajout des lignes et colonnes
        ui->tableWidgetProducteur->setRowCount(ligne);

        //odubic
        //login
        ui->tableWidgetProducteur->setItem(ligne-1,0,new QTableWidgetItem(resModo.value("loginProducteur").toString()));
        //nomsupprEmploye
        ui->tableWidgetProducteur->setItem(ligne-1,1,new QTableWidgetItem(resModo.value("nomProducteur").toString()));
        //prenom
        ui->tableWidgetProducteur->setItem(ligne-1,2,new QTableWidgetItem(resModo.value("prenomProducteur").toString()));
        //tel
        ui->tableWidgetProducteur->setItem(ligne-1,3,new QTableWidgetItem(resModo.value("telProducteur").toString()));
        //mail
        ui->tableWidgetProducteur->setItem(ligne-1,4,new QTableWidgetItem(resModo.value("mailProducteur").toString()));
        //@
        ui->tableWidgetProducteur->setItem(ligne-1,5,new QTableWidgetItem(resModo.value("adresseProducteur").toString()));
        //checkbox
        ui->tableWidgetProducteur->setCellWidget(ligne-1,6, new QCheckBox);
    }
}
//amogus
//Ideo ?
// nan nan c pas moi
void MainWindow::AfficheModerateurAdmin()
{
    //initialisation ligne
    ligne=0;

    //SET NB COLONNES
    ui->tableWidgetModerateurAdmin->setColumnCount(7);

    //stretch du tableau
    ui->tableWidgetModerateurAdmin->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //requete affichage Administrateurs
    QString reqModoAdmin ="select numeroEmploye, nomEmploye, prenomEmploye, concat(rueEmploye, villeEmploye, CpEmploye), MailEmploye, TelEmploye, PassEmploye, loginEmploye, numeroTypeEmploye, supprEmploye from Employe where numeroTypeEmploye = 3";
    QSqlQuery resModoAdmin(reqModoAdmin);
    while (resModoAdmin.next()) {
        ligne++;

        //ajout des lignes et colonnes
        ui->tableWidgetModerateurAdmin->setRowCount(ligne);

        //odubic
        //login
        ui->tableWidgetModerateurAdmin->setItem(ligne-1,0,new QTableWidgetItem(resModoAdmin.value("loginEmploye").toString()));
        //nomsupprEmploye
        ui->tableWidgetModerateurAdmin->setItem(ligne-1,1,new QTableWidgetItem(resModoAdmin.value("nomEmploye").toString()));
        //prenom
        ui->tableWidgetModerateurAdmin->setItem(ligne-1,2,new QTableWidgetItem(resModoAdmin.value("prenomEmploye").toString()));
        //tel
        ui->tableWidgetModerateurAdmin->setItem(ligne-1,3,new QTableWidgetItem(resModoAdmin.value("TelEmploye").toString()));
        //mail
        ui->tableWidgetModerateurAdmin->setItem(ligne-1,4,new QTableWidgetItem(resModoAdmin.value("MailEmploye").toString()));
        //@
        ui->tableWidgetModerateurAdmin->setItem(ligne-1,5,new QTableWidgetItem(resModoAdmin.value("concat(rueEmploye, villeEmploye, CpEmploye)").toString()));
        //checkbox
        ui->tableWidgetModerateurAdmin->setCellWidget(ligne-1,6, new QCheckBox);
    }
}

void MainWindow::AfficheProducteurAdmin()
{
    //initialisation ligne
    ligne=0;

    //SET NB COLONNES
    ui->tableWidgetProducteurAdmin->setColumnCount(7);

    //stretch du tableau
    ui->tableWidgetProducteurAdmin->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //requete affichage Administrateurs
    QString reqProdAdmin ="select numeroproducteur, loginProducteur, nomProducteur, prenomProducteur, adresseProducteur, telProducteur, mailProducteur, validiteProducteur from Producteur where validiteProducteur = 1";
    QSqlQuery resProdAdmin(reqProdAdmin);
    while (resProdAdmin.next()) {
        ligne++;

        //ajout des lignes et colonnes
        ui->tableWidgetProducteurAdmin->setRowCount(ligne);

        //odubic
        //login
        ui->tableWidgetProducteurAdmin->setItem(ligne-1,0,new QTableWidgetItem(resProdAdmin.value("loginProducteur").toString()));
        //nomsupprEmploye
        ui->tableWidgetProducteurAdmin->setItem(ligne-1,1,new QTableWidgetItem(resProdAdmin.value("nomProducteur").toString()));
        //prenom
        ui->tableWidgetProducteurAdmin->setItem(ligne-1,2,new QTableWidgetItem(resProdAdmin.value("prenomProducteur").toString()));
        //tel
        ui->tableWidgetProducteurAdmin->setItem(ligne-1,3,new QTableWidgetItem(resProdAdmin.value("telProducteur").toString()));
        //mail
        ui->tableWidgetProducteurAdmin->setItem(ligne-1,4,new QTableWidgetItem(resProdAdmin.value("mailProducteur").toString()));
        //@
        ui->tableWidgetProducteurAdmin->setItem(ligne-1,5,new QTableWidgetItem(resProdAdmin.value("adresseProducteur").toString()));
        //checkbox
        ui->tableWidgetProducteurAdmin->setCellWidget(ligne-1,6, new QCheckBox);
    }
}
