#ifndef DIALOGADDADMIN_H
#define DIALOGADDADMIN_H

#include <QDialog>

namespace Ui {
class DialogAddAdmin;
}

class DialogAddAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddAdmin(QWidget *parent = nullptr);
    ~DialogAddAdmin();

private slots:
    void on_pushButtonAddAdministrator_clicked();

    void on_pushButtonCancelAddAdministrator_clicked();

private:
    Ui::DialogAddAdmin *ui;
};

#endif // DIALOGADDADMIN_H
