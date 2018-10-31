#include <string>
#include "refund.h"
#include "ui_refund.h"
#include "UserClass.hpp"
#include "TrainClass.hpp"

using std::string;

refund::refund(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::refund)
{
    ui->setupUi(this);
}

refund::~refund()
{
    delete ui;
}
void refund::setui()
{
    ui->lineEdit_4->setText(QString::fromStdString(num));
    ui->lineEdit->setText(QString::fromStdString(sta));
    ui->lineEdit_3->setText(QString::fromStdString(end));
    ui->lineEdit_2->setText(QString::fromStdString(day));
}

void refund::on_pushButton_clicked()
{
    string ticketNum = ui->spinBox->text().toStdString(),
           ticketClass = ui->lineEdit_6->text().toStdString(),
           trainId = ui->lineEdit_4->text().toStdString(),
           start = ui->lineEdit->text().toStdString(),
           dest = ui->lineEdit_3->text().toStdString(),
           date = ui->lineEdit_2->text().toStdString();
    ticketUsrOpt("refunded", ticketNum, ticketClass, trainId, start, dest, date);
}
