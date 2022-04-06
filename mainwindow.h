#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int leType, QWidget *parent = nullptr);
    ~MainWindow();
    void AfficheAdministrateur();
    void AfficheModerateur();
    void AfficheProducteur();

    void AfficheModerateurAdmin();
    void AfficheProducteurAdmin();
    int ligne;
    QString typeEmployeDialog;

    private slots:
    void on_pushButtonAddAdmin_clicked();

    void on_pushButtonDelAdmin_clicked();

    void on_action_Quit_triggered();

    void on_pushButtonModifyAdmin_clicked();

    void on_pushButtonReloadTables_clicked();

    void on_pushButtonAddModer_clicked();

    void on_pushButtonReloadTablesAdmin_clicked();

    void on_pushButtonModifyModer_clicked();

    void on_pushButtonDelModer_clicked();

    void on_pushButtonAddProd_clicked();

    void on_pushButtonValidProd_clicked();

    void on_action_Profil_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
