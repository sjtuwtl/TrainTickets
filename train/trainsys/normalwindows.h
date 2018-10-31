#ifndef NORMALWINDOWS_H
#define NORMALWINDOWS_H

#include <QWidget>
#include <QMessageBox>
#include "mydialog.h"
#include "refund.h"

using std::string;

namespace Ui {
class normalWindows;
}

class normalWindows : public QWidget
{
    Q_OBJECT

public:
    explicit normalWindows(QWidget *parent = 0);
    ~normalWindows();
    string userid;
    void setui();

private slots:
    void on_backCommand_clicked();

    void on_pushButton_clicked();

    void on_pushButtonresearch_clicked();

    void on_pushButtonCheck_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_tableWidget_2_doubleClicked(const QModelIndex &index);

private:
    Ui::normalWindows *ui;
    string a, b, c, d;
    MyDialog *dialog;
};

#endif // NORMALWINDOWS_H
