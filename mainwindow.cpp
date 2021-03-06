#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogaddadmin.h"
#include "dialogmodify.h"
#include "dialogprofil.h"

#include <QCheckBox>
#include <QSqlQuery>
#include <QStackedWidget>
#include <QDebug>
#include <QPixmap>
#include <QLabel>

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
    ui->tableWidgetAdministrateur->setRowCount(0);

    //SET NB COLONNES
    ui->tableWidgetAdministrateur->setColumnCount(8);

    //stretch du tableau
    ui->tableWidgetAdministrateur->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //requete affichage Administrateurs
    QString adminQuery ="select numeroEmploye, nomEmploye, prenomEmploye, concat(rueEmploye,' ', villeEmploye,' ', cpEmploye) AS adr, MailEmploye, TelEmploye, PassEmploye, loginEmploye, numeroTypeEmploye, supprEmploye from Employe where numeroTypeEmploye = 2 and supprEmploye = 0";
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
        ui->tableWidgetAdministrateur->setItem(ligne-1,5,new QTableWidgetItem(adminResult.value("adr").toString()));
        //checkbox
        ui->tableWidgetAdministrateur->setCellWidget(ligne-1,6, new QCheckBox);
        //num??ro
        ui->tableWidgetAdministrateur->setItem(ligne-1,7,new QTableWidgetItem(adminResult.value("numeroEmploye").toString()));
    }
    ui->tableWidgetAdministrateur->hideColumn(7);
}

void MainWindow::AfficheModerateur()
{
    //initialisation ligne
    ligne=0;

    //SET NB COLONNES
    ui->tableWidgetModerateur->setColumnCount(8);

    //stretch du tableau
    ui->tableWidgetModerateur->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //requete affichage Administrateurs
    QString reqModo ="select numeroEmploye, nomEmploye, prenomEmploye, concat(rueEmploye,' ', villeEmploye,' ', CpEmploye) AS adr, MailEmploye, TelEmploye, PassEmploye, loginEmploye, numeroTypeEmploye, supprEmploye from Employe where numeroTypeEmploye = 3 and supprEmploye = 0";
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
        ui->tableWidgetModerateur->setItem(ligne-1,5,new QTableWidgetItem(resModo.value("adr").toString()));
        //checkbox
        ui->tableWidgetModerateur->setCellWidget(ligne-1,6, new QCheckBox);
        //num??ro
        ui->tableWidgetModerateur->setItem(ligne-1,7,new QTableWidgetItem(resModo.value("numeroEmploye").toString()));
    }
    ui->tableWidgetModerateur->hideColumn(7);
}

void MainWindow::AfficheProducteur()
{
    //initialisation ligne
    ligne=0;

    //SET NB COLONNES
    ui->tableWidgetProducteurInvalid->setColumnCount(9);

    //stretch du tableau
    ui->tableWidgetProducteurInvalid->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //requete affichage Administrateurs
    QString reqProd ="select numeroproducteur, loginProducteur, nomProducteur, prenomProducteur, telProducteur, dateInscriptionProducteur, imageProducteur, "
                     "imageFermeProducteur, numeroabonnement, mailProducteur, validiteProducteur, raisonInvaliditeProducteur, siren, "
                     "concat(rueProducteur,' ',villeProducteur,' ',cpProducteur) as adr from Producteur where validiteProducteur = 0";
    QSqlQuery resProd(reqProd);
    while (resProd.next()) {
        ligne++;

        //ajout des lignes et colonnes
        ui->tableWidgetProducteurInvalid->setRowCount(ligne);

        //odubic
        //login
        ui->tableWidgetProducteurInvalid->setItem(ligne-1,0,new QTableWidgetItem(resProd.value("loginProducteur").toString()));
        qDebug()<<resProd.value("loginProducteur").toString();
        //nomsupprEmploye
        ui->tableWidgetProducteurInvalid->setItem(ligne-1,1,new QTableWidgetItem(resProd.value("nomProducteur").toString()));
        //prenom
        ui->tableWidgetProducteurInvalid->setItem(ligne-1,2,new QTableWidgetItem(resProd.value("prenomProducteur").toString()));
        //tel
        ui->tableWidgetProducteurInvalid->setItem(ligne-1,3,new QTableWidgetItem(resProd.value("telProducteur").toString()));
        //mail
        ui->tableWidgetProducteurInvalid->setItem(ligne-1,4,new QTableWidgetItem(resProd.value("mailProducteur").toString()));
        //@
        ui->tableWidgetProducteurInvalid->setItem(ligne-1,5,new QTableWidgetItem(resProd.value("adr").toString()));
        //checkbox
        ui->tableWidgetProducteurInvalid->setCellWidget(ligne-1,6, new QCheckBox);

        //declaration du vecteur des image du producteur et de la ferme
        QLabel *labelProfil = new QLabel();
        QString cheminImageProfil = "/home/jlopez/Documents/SIO2/git/Patate/"+resProd.value("imageProducteur").toString();
        labelProfil->setPixmap(QPixmap (cheminImageProfil).scaled(100,100));
        labelProfil->setScaledContents(true);

        QLabel *labelFerme = new QLabel();
        QString cheminImageFerme="/home/jlopez/Documents/SIO2/git/Patate/"+resProd.value("imageFermeProducteur").toString();
        qDebug()<<cheminImageFerme;
        labelFerme->setPixmap(QPixmap (cheminImageFerme).scaled(100,100));
        labelFerme->setScaledContents(true);

        //image producteur
        ui->tableWidgetProducteurInvalid->setCellWidget(ligne-1,7, labelProfil);
        qDebug()<<resProd.value("imageFermeProducteur").toString();
        //image ferme
        ui->tableWidgetProducteurInvalid->setCellWidget(ligne-1,8, labelFerme);

        //id
        ui->tableWidgetProducteurInvalid->setItem(ligne-1, 9, new QTableWidgetItem(resProd.value("numeroProducteur").toString()));

    }
    ui->tableWidgetProducteurInvalid->resizeColumnsToContents();
    ui->tableWidgetProducteurInvalid->resizeRowsToContents();
    ui->tableWidgetProducteurInvalid->update();
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
    QString reqProdAdmin ="select numeroproducteur, loginProducteur, nomProducteur, prenomProducteur, telProducteur, dateInscriptionProducteur, imageProducteur, imageFermeProducteur, numeroabonnement, numeroabonnement, mailProducteur, validiteProducteur, raisonInvaliditeProducteur, siren, concat(rueProducteur,' ',villProducteur,' ',cpProducteur) as adr from Producteur where validiteProducteur = 1";
    QSqlQuery resProdAdmin(reqProdAdmin);
    while (resProdAdmin.next()) {
        ligne++;

        //ajout des lignes et colonnes
        ui->tableWidgetModerateurAdmin->setRowCount(ligne);

        //odubic
        //login
        ui->tableWidgetModerateurAdmin->setItem(ligne-1,0,new QTableWidgetItem(resProdAdmin.value("loginProducteur").toString()));
        //nomsupprEmploye
        ui->tableWidgetModerateurAdmin->setItem(ligne-1,1,new QTableWidgetItem(resProdAdmin.value("nomProducteur").toString()));
        //prenom
        ui->tableWidgetModerateurAdmin->setItem(ligne-1,2,new QTableWidgetItem(resProdAdmin.value("prenomProducteur").toString()));
        //tel
        ui->tableWidgetModerateurAdmin->setItem(ligne-1,3,new QTableWidgetItem(resProdAdmin.value("telProducteur").toString()));
        //mail
        ui->tableWidgetModerateurAdmin->setItem(ligne-1,4,new QTableWidgetItem(resProdAdmin.value("mailProducteur").toString()));
        //@
        ui->tableWidgetModerateurAdmin->setItem(ligne-1,5,new QTableWidgetItem(resProdAdmin.value("adr").toString()));
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

void MainWindow::on_pushButtonAddAdmin_clicked()
{
   typeEmployeDialog="2";
   DialogAddAdmin dialog(this);
   dialog.exec();

   qDebug()<<"type employe admin"<<typeEmployeDialog;
}


void MainWindow::on_pushButtonDelAdmin_clicked()
{
    //on check le nb de lignes
    for (int nbLigne = ui->tableWidgetAdministrateur->rowCount()-1; nbLigne>=0; nbLigne--) {
        qDebug()<<"for checkbox"<<nbLigne;
        //si la checkbox est coch??e
        if(((QCheckBox*)(ui->tableWidgetAdministrateur->cellWidget(nbLigne,6)))->isChecked())
            {
                qDebug()<<"if checkbox";
                //on recupere le login
                QString login = ui->tableWidgetAdministrateur->item(nbLigne,0)->text();
                qDebug()<<"login : "<<login;
                //passer le bool ?? 1
                QString reqDelAdmin = "UPDATE Employe SET supprEmploye = 1 where loginEmploye='"+login+"'";
                qDebug()<<"reqDelAdmin : "<<reqDelAdmin;
                QSqlQuery resDelAdmin (reqDelAdmin);
                resDelAdmin.next();
            }
    }
    AfficheAdministrateur();
}


void MainWindow::on_action_Quit_triggered()
{
    close();
}


void MainWindow::on_pushButtonModifyAdmin_clicked()
{ 
    typeEmployeDialog = "3";
    qDebug()<<"type employe admin"<<typeEmployeDialog;

    //r??cup??rer les valeur
    int row=ui->tableWidgetModerateur->currentRow();

    qDebug()<<"ligne : "<<row;

    QString sonPrenom = ui->tableWidgetAdministrateur->item(row, 2)->text();
    qDebug()<<sonPrenom;
    QString sonNom = ui->tableWidgetAdministrateur->item(row, 1)->text();
    qDebug()<<sonNom;
    QString sonlogin = ui->tableWidgetAdministrateur->item(row,0)->text();
    QString sonPhone = ui->tableWidgetAdministrateur->item(row,3)->text();
    QString sonMail = ui->tableWidgetAdministrateur->item(row,4)->text();
    QString sonId = ui->tableWidgetAdministrateur->item(row, 7)->text();
    qDebug()<<sonId;


    //ouvrir le dialog
    DialogModify dialogModify(this);

    dialogModify.setNom(sonNom);
    dialogModify.setPrenom(sonPrenom);
    dialogModify.setLogin(sonlogin);
    dialogModify.setPhone(sonPhone);
    dialogModify.setMail(sonMail);
    dialogModify.setId(sonId);
    dialogModify.setRue();
    dialogModify.setVille();
    dialogModify.setCp();
    dialogModify.exec();

}


void MainWindow::on_pushButtonReloadTables_clicked()
{
    AfficheAdministrateur();
    AfficheModerateur();
    AfficheProducteur();
    //stretch du tableau
    ui->tableWidgetProducteurInvalid->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    AfficheModerateurAdmin();
    AfficheProducteurAdmin();
}

void MainWindow::on_pushButtonAddModer_clicked()
{
    typeEmployeDialog="3";
    qDebug()<<"type employe modo"<<typeEmployeDialog;
    DialogAddAdmin dialog(this);
    dialog.exec();
}


void MainWindow::on_pushButtonReloadTablesAdmin_clicked()
{
    AfficheAdministrateur();
    AfficheModerateur();
    AfficheProducteur();
    //stretch du tableau
    ui->tableWidgetProducteurInvalid->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    AfficheModerateurAdmin();
    AfficheProducteurAdmin();
}

void MainWindow::on_pushButtonModifyModer_clicked()
{
    //r??cup??rer les valeur
    int row=ui->tableWidgetModerateur->currentRow();

    qDebug()<<"ligne : "<<row;

    QString sonPrenom = ui->tableWidgetModerateur->item(row, 2)->text();
    qDebug()<<sonPrenom;
    QString sonNom = ui->tableWidgetModerateur->item(row, 1)->text();
    qDebug()<<sonNom;
    QString sonlogin = ui->tableWidgetModerateur->item(row,0)->text();
    QString sonPhone = ui->tableWidgetModerateur->item(row,3)->text();
    QString sonMail = ui->tableWidgetModerateur->item(row,4)->text();
    QString sonId = ui->tableWidgetModerateur->item(row, 7)->text();
    qDebug()<<sonId;


    //ouvrir le dialog
    DialogModify dialogModify(this);

    dialogModify.setNom(sonNom);
    dialogModify.setPrenom(sonPrenom);
    dialogModify.setLogin(sonlogin);
    dialogModify.setPhone(sonPhone);
    dialogModify.setMail(sonMail);
    dialogModify.setId(sonId);
    dialogModify.setRue();
    dialogModify.setVille();
    dialogModify.setCp();
    dialogModify.exec();
}


void MainWindow::on_pushButtonDelModer_clicked()
{
    //on check le nb de lignes
    for (int nbLigne = ui->tableWidgetModerateur->rowCount()-1; nbLigne>=0; nbLigne--) {
        qDebug()<<"for checkbox"<<nbLigne;
        //si la checkbox est coch??e
        if(((QCheckBox*)(ui->tableWidgetModerateur->cellWidget(nbLigne,6)))->isChecked())
            {
                qDebug()<<"if checkbox";
                //on recupere le login
                QString login = ui->tableWidgetModerateur->item(nbLigne,0)->text();
                qDebug()<<"login : "<<login;
                //passer le bool ?? 1
                QString reqDelAdmin = "UPDATE Employe SET supprEmploye = 1 where loginEmploye='"+login+"'";
                qDebug()<<"reqDelAdmin : "<<reqDelAdmin;
                QSqlQuery resDelAdmin (reqDelAdmin);
                resDelAdmin.next();
            }
    }
    AfficheModerateur();
}



void MainWindow::on_pushButtonAddProd_clicked()
{

}


void MainWindow::on_pushButtonValidProd_clicked()
{

}


void MainWindow::on_action_Profil_triggered()
{
    //typeEmployeDialog="3";
    //qDebug()<<"type employe modo"<<typeEmployeDialog;
    DialogProfil dialog(this);
    dialog.exec();
}


