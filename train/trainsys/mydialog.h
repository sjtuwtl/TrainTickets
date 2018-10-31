#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class MyDialog;
}

class MyDialog : public QWidget
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    std::string num, sta, end, day;
    ~MyDialog();
    void setui();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
