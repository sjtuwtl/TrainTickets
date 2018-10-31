#ifndef REGDIALOG_H
#define REGDIALOG_H

#include <QDialog>

namespace Ui {
class regDialog;
}

class regDialog : public QDialog
{
    Q_OBJECT

public:
    explicit regDialog(QWidget *parent = 0);
    ~regDialog();
    void useDialog(QString id);

private slots:
    void on_reLogin_clicked();

private:
    Ui::regDialog *ui;
};

#endif // REGDIALOG_H
