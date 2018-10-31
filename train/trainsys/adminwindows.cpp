#include <string>
#include "adminwindows.h"
#include "ui_adminwindows.h"
#include "loginwindows.h"
#include "qtextbrowser.h"
#include "vipfunc.h"
#include "toolSet.hpp"

using std::string;

adminWindows::adminWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminWindows)
{
    ui->setupUi(this);
}

adminWindows::~adminWindows()
{
    delete ui;
}

void adminWindows::on_backButton_clicked()
{
    close();
    loginWindows *login = new loginWindows;
    login->show();
}

void adminWindows::on_cheSysButton_clicked()
{
   ui->stackedWidget->setCurrentIndex(5);
}

void adminWindows::on_addPlanButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void adminWindows::on_delPlanButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void adminWindows::on_modPlanButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void adminWindows::on_updSellButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void adminWindows::on_cheUserButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void adminWindows::on_checkUserButton_clicked()
{
    string ID = ui->idEdit->text().toStdString();
    string text1, text2, text4;
    seeUser(littleTool::string2Int(ID), text1, text2, text4);
    ui->reIdEdit->setText(ui->idEdit->text());
    ui->usernameEdit->setText(QString::fromStdString(text1));
    ui->passwordEdit->setText(QString::fromStdString(text2));
    ui->logBrowser->setText(QString::fromStdString(text4));
}

void adminWindows::on_pushButton_6_clicked()
{
    string trainName = ui->lineEdit_7->text().toStdString();
    if (delTrain(trainName)) {
        delTrain(trainName);
        QMessageBox::information(this,tr("成功"),tr("删除成功！"));
    }
    else QMessageBox::warning(this,tr("警告"),tr("该车次不存在！"),QMessageBox::Yes);
}

void adminWindows::on_pushButton_clicked()
{
    string name = ui->lineEdit_2->text().toStdString();
    string date = ui->lineEdit_3->text().toStdString();
    if (updateSell(name, date, 1)) {
        QMessageBox::information(this,tr("成功"),tr("修改成功！"));
    }
    else QMessageBox::warning(this,tr("警告"),tr("该车次不存在！"),QMessageBox::Yes);
}

void adminWindows::on_pushButton_2_clicked()
{
    string name = ui->lineEdit_2->text().toStdString();
    string date = ui->lineEdit_3->text().toStdString();
    if (updateSell(name, date, 0)) {
        QMessageBox::information(this,tr("成功"),tr("修改成功！"));
    }
    else QMessageBox::warning(this,tr("警告"),tr("该车次不存在！"),QMessageBox::Yes);
}

void adminWindows::on_addNewStation_clicked()
{
    int n = ui->addTable->rowCount();
    ui->addTable->setRowCount(n + 1);
    ui->addTable->setRowHeight(n, 24);
}

void adminWindows::on_pushButton_7_clicked()
{
    string name = ui->trainIdEdit->text().toStdString(), title[15], list[70][15];
    int titleLen = 0, listLen = 0;
    listLen = ui->addTable->rowCount() - 1;
    for (int i = 0; i < 5; ++i) title[++titleLen] = ui->addTable->item(0, i)->text().toStdString();
    if (ui->seat_1->text() != tr("")) {
        title[++titleLen] = ui->seat_1->text().toStdString();
        if (ui->seat_2->text() != tr("")) {
            title[++titleLen] = ui->seat_2->text().toStdString();
            if (ui->seat_3->text() != tr("")){
                title[++titleLen] = ui->seat_2->text().toStdString();
            }
        }
    }
    for (int i = 1; i <= listLen; ++i) {
        for (int j = 0; j < titleLen; ++j) {
            list[i - 1][j] = ui->addTable->item(i, j)->text().toStdString();
        }
    }
    if (insertTrain(name, title, titleLen, list, listLen)) {
        QMessageBox::information(this, tr("成功"), tr("添加成功！"));
     }
    else {
        QMessageBox::warning(this, tr("失败"), tr("该车次已经存在"));
    }
    ui->seat_1->clear();
    ui->seat_2->clear();
    ui->seat_3->clear();
    while (ui->addTable->rowCount() > 1) {
        ui->addTable->removeRow(1);
    }
}

void adminWindows::on_addNewStation_2_clicked()
{
    int n = ui->addTable->rowCount();
    ui->addTable->setRowCount(n + 1);
    ui->addTable->setRowHeight(n, 24);
}

void adminWindows::on_pushButton_8_clicked()
{
    string name = ui->trainIdEdit->text().toStdString(), title[15], list[70][15];
    int titleLen = 0, listLen = 0;
    listLen = ui->addTable->rowCount() - 1;
    for (int i = 0; i < 5; ++i) title[++titleLen] = ui->addTable->item(0, i)->text().toStdString();
    if (ui->seat_1->text() != tr("")) {
        title[++titleLen] = ui->seat_1->text().toStdString();
        if (ui->seat_2->text() != tr("")) {
            title[++titleLen] = ui->seat_2->text().toStdString();
            if (ui->seat_3->text() != tr("")){
                title[++titleLen] = ui->seat_2->text().toStdString();
            }
        }
    }
    for (int i = 1; i <= listLen; ++i) {
        for (int j = 0; j < titleLen; ++j) {
            list[i - 1][j] = ui->addTable->item(i, j)->text().toStdString();
        }
    }
    int result = changeTrain(name, title, titleLen, list, listLen);
    if (result == 1) {
        QMessageBox::information(this, tr("成功"), tr("修改成功！"));
     }
    else if (result == 2) {
        QMessageBox::warning(this, tr("失败"), tr("该车次已经开始发售"));
    }
    else {
        QMessageBox::warning(this, tr("失败"), tr("该车次不存在"));
    }
    ui->seat_1->clear();
    ui->seat_2->clear();
    ui->seat_3->clear();
    while (ui->addTable->rowCount() > 1) {
        ui->addTable->removeRow(1);
    }
}
