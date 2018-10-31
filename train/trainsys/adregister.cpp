#include <string>
#include "adregister.h"
#include "ui_adregister.h"
#include "varset.h"
#include "UserClass.hpp"
using std::pair;
using std::string;

adregister::adregister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adregister)
{
    ui->setupUi(this);
}

adregister::~adregister()
{
    delete ui;
}

void adregister::on_sureButton_clicked()
{
    a = ui->newNameEdit_2->text().toStdString();
    b = ui->newPassEdit_2->text().toStdString();
    c = ui->newPassEdit2_2->text().toStdString();
    d = ui->lineEdit->text().toStdString();
    if(ui->newNameEdit_2->text().isEmpty()||ui->newPassEdit_2->text().isEmpty()||ui->newPassEdit2_2->text().isEmpty())
        QMessageBox::warning(this,tr("警告信息"),tr("用户名或密码为空，不能注册"));
    if (d != "6666")
        QMessageBox::warning(this,tr("警告信息"),tr("注册码错误"));
    else if (b != c)
        QMessageBox::warning(this,tr("警告信息"),tr("两次输入密码不符"));
    else {
        c = trueRegister(a,b,1);
        QMessageBox::information(this,tr("注册成功"),QString::fromStdString("账号为" + c));
    }
    close();
}

void adregister::on_exitButton_clicked()
{
    close();
}
