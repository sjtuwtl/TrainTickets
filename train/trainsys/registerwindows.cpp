#include <string>
#include "registerwindows.h"
#include "ui_registerwindows.h"
#include "QMessageBox"
#include "regdialog.h"
#include "varset.h"
#include "UserClass.hpp"

using std::string;

registerWindows::registerWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registerWindows)
{
    ui->setupUi(this);
}

registerWindows::~registerWindows()
{
    delete ui;
}

void registerWindows::on_sureButton_clicked()
{
    a = ui->newNameEdit->text().toStdString();
    b = ui->newPassEdit->text().toStdString();
    c = ui->newPassEdit2->text().toStdString();
    if(ui->newNameEdit->text().isEmpty()||ui->newPassEdit->text().isEmpty()||ui->newPassEdit2->text().isEmpty())
        QMessageBox::warning(this,tr("警告信息"),tr("用户名或密码为空，不能注册"));
    if (b != c)
        QMessageBox::warning(this,tr("警告信息"),tr("两次输入密码不符"));
    else {
        c = trueRegister(a,b,0);
        // !!!c = 注册函数
        QMessageBox::information(this,tr("注册成功"),QString::fromStdString("账号为" + c));
        close();
    }
}

void registerWindows::on_exitButton_clicked()
{
    close();
}
