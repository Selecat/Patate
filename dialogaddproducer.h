#ifndef DIALOGADDPRODUCER_H
#define DIALOGADDPRODUCER_H

#include <QDialog>

namespace Ui {
class DialogAddProducer;
}

class DialogAddProducer : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddProducer(QWidget *parent = nullptr);
    ~DialogAddProducer();

private:
    Ui::DialogAddProducer *ui;
};

#endif // DIALOGADDPRODUCER_H
