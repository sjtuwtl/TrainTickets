#ifndef NOTMATCHDIALOG_H
#define NOTMATCHDIALOG_H

#include <QDialog>

namespace Ui {
class notMatchDialog;
}

class notMatchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit notMatchDialog(QWidget *parent = 0);
    ~notMatchDialog();

private:
    Ui::notMatchDialog *ui;
};

#endif // NOTMATCHDIALOG_H
