#include "mydialog.h"
#include "ui_mydialog.h"
#include "TrainClass.hpp"
#include "UserClass.hpp"

MyDialog::MyDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::on_pushButton_clicked()
{
    string ticketNum = ui->spinBox->text().toStdString(),
           ticketClass = ui->lineEdit_6->text().toStdString(),
           trainId = ui->lineEdit_4->text().toStdString(),
           start = ui->lineEdit->text().toStdString(),
           dest = ui->lineEdit_3->text().toStdString(),
           date = ui->lineEdit_2->text().toStdString();
    ticketUsrOpt("bought", ticketNum, ticketClass, trainId, start, dest, date);
    QMessageBox::information(this,tr("提示"),tr("订票成功!"));
}

void MyDialog::setui()
{
    ui->lineEdit_4->setText(QString::fromStdString(num));
    ui->lineEdit->setText(QString::fromStdString(sta));
    ui->lineEdit_3->setText(QString::fromStdString(end));
    ui->lineEdit_2->setText(QString::fromStdString(day));
}

void MyDialog::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{

}
