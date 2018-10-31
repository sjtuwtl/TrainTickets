#ifndef LOGINWINDOWS_H
#define LOGINWINDOWS_H

#include <QMainWindow>
#include "adregister.h"

namespace Ui {
class loginWindows;
}

class loginWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginWindows(QWidget *parent = 0);
    ~loginWindows();

private slots:
    void on_loginButton_clicked();

    void on_registerButton_clicked();

    void on_backCommand_clicked();

    void on_passwordEdit_returnPressed();

    void on_pushButton_clicked();

private:
    Ui::loginWindows *ui;
};


#endif // LOGINWINDOWS_H
