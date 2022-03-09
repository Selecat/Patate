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
    int ligne;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
