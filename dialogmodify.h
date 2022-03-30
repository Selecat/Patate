#ifndef DIALOGMODIFY_H
#define DIALOGMODIFY_H

#include <QDialog>

namespace Ui {
class DialogModify;
}

class DialogModify : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModify(QWidget *parent = nullptr);
    ~DialogModify();
    void setId(QString sonId);
    void setPrenom(QString lePrenom);
    void setNom(QString leNom);
    void setLogin(QString leLogin);
    void setPhone(QString lePhone);
    void setMail(QString leMail);
    void setRue();
    void setVille();
    void setCp();

private slots:
    void on_pushButtonModifyAdministrator_clicked();

    void on_pushButtonCancelModifyAdministrator_clicked();

private:
    Ui::DialogModify *ui;
    QString idAdmin;
};

#endif // DIALOGMODIFY_H
