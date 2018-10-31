#include "loginwindows.h"
#include "ui_loginwindows.h"
#include "notmatchdialog.h"
#include "QMessageBox"
#include "registerwindows.h"
#include "adminwindows.h"
#include "normalwindows.h"
#include "UserClass.hpp"

#include "varset.h"
typedef MyMap<QueryInformation> TMAP;
typedef MyMap<UserInformation> UMAP;

loginWindows::loginWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginWindows)
{
    ui->setupUi(this);
}

loginWindows::~loginWindows()
{
    delete ui;
}

void loginWindows::on_loginButton_clicked()
{
    QString uid = ui->usernameEdit->text().trimmed();
    QString pwd = ui->passwordEdit->text().trimmed();
    int result = login(uid.toStdString(), pwd.toStdString(), ui->adminChoice->isChecked());
    if (ui->normalChoice->isChecked() == true) {

        if (result == 1) {//！！！此处一个用户登录函数判断是否管理员 QString ->string
            close();
            normalWindows *normal = new normalWindows();
            normal->userid = uid.toStdString();
            normal->setui();
            normal -> show();
        }
        else if (result == 0) {
            QMessageBox::warning(this,tr("警告"),tr("ID不存在！"),QMessageBox::Yes);
            ui->passwordEdit->clear();  //清空密码passwardLine
            ui->passwordEdit->setFocus();  //将鼠标重新定位到nameLine
        }
        else if (result == 2){
            //用户输入存在错误
            QMessageBox::warning(this,tr("警告"),tr("密码错误！"),QMessageBox::Yes);
            ui->passwordEdit->clear();  //清空密码passwardLine
            ui->passwordEdit->setFocus();  //将鼠标重新定位到nameLine
        }
    }
    else {
        if (result == 1) {//！！！此处一个管理员登录函数
            close();
            adminWindows *admin = new adminWindows;
            admin -> show();
        }
        else if (result == 0) {
            QMessageBox::warning(this,tr("警告"),tr("ID不存在！"),QMessageBox::Yes);
            ui->passwordEdit->clear();  //清空密码passwardLine
            ui->passwordEdit->setFocus();  //将鼠标重新定位到nameLine
        }
        else if (result == 2){
            //用户输入存在错误
            QMessageBox::warning(this,tr("警告"),tr("密码错误！"),QMessageBox::Yes);
            ui->passwordEdit->clear();  //清空密码passwardLine
            ui->passwordEdit->setFocus();  //将鼠标重新定位到nameLine
        }
    }
}

void loginWindows::on_registerButton_clicked()
{
    registerWindows *regWin = new registerWindows;
    regWin -> show();
}

void loginWindows::on_backCommand_clicked()
{
    close();
}

void loginWindows::on_passwordEdit_returnPressed()
{
    on_loginButton_clicked();
}

void loginWindows::on_pushButton_clicked()
{
    adregister *ad = new adregister;
    ad->show();
}
