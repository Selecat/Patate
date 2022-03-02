#include "mainwindow.h"
#include "dialogconnexion.h"

#include <QApplication>
#include <QtSql/QSqlDatabase>
#include <QtDebug>
#include <QDialog>

int main(int argc, char *argv[])
{
    QSqlDatabase dbPatate = QSqlDatabase::addDatabase("QMYSQL");
              dbPatate.setHostName("localhost");
              dbPatate.setDatabaseName("dbPatate");
              dbPatate.setUserName("producteur");
              dbPatate.setPassword("achetezMesProduitSVP21");
              bool ok = dbPatate.open();
              qDebug()<<"connexion bdd"<<ok;

    QApplication a(argc, argv);
    DialogConnexion connexion;
    if (connexion.exec()==QDialog::Accepted){
        qDebug()<<"resultat du dialog:"<<connexion.getType();
        MainWindow w(connexion.getType());
        w.show();
        return a.exec();
    }
}
