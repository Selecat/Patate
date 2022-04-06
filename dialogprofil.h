#ifndef DIALOGPROFIL_H
#define DIALOGPROFIL_H

#include <QDialog>

namespace Ui {
class DialogProfil;
}

class DialogProfil : public QDialog
{
    Q_OBJECT

public:
    explicit DialogProfil(QWidget *parent = nullptr);
    ~DialogProfil();

private:
    Ui::DialogProfil *ui;
};

#endif // DIALOGPROFIL_H
