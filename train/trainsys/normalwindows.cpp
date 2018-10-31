    #include <sstream>
    #include "normalwindows.h"
    #include "ui_normalwindows.h"
    #include "loginwindows.h"
    #include "UserClass.hpp"
    #include "varset.h"

    normalWindows::normalWindows(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::normalWindows)
    {
        ui->setupUi(this);
        ui->tableWidget->setColumnWidth(0,100);
        ui->tableWidget->setColumnWidth(1,50);
        ui->tableWidget->setColumnWidth(2,70);
        ui->tableWidget->setColumnWidth(3,50);
        ui->tableWidget->setColumnWidth(4,70);
        ui->tableWidget->setColumnWidth(5,70);
        ui->tableWidget->setColumnWidth(6,70);
        ui->tableWidget->setColumnWidth(7,70);
        ui->tableWidget->setColumnWidth(8,70);
        ui->tableWidget->setColumnWidth(9,70);
        ui->tableWidget->setColumnWidth(10,70);
        ui->tableWidget->setColumnWidth(11,70);
        ui->tableWidget->setColumnWidth(12,70);
        ui->tableWidget->setColumnWidth(13,70);
        ui->tableWidget_2->setColumnWidth(0,100);
        ui->tableWidget_2->setColumnWidth(1,50);
        ui->tableWidget_2->setColumnWidth(2,70);
        ui->tableWidget_2->setColumnWidth(3,50);
        ui->tableWidget_2->setColumnWidth(4,70);
        ui->tableWidget_2->setColumnWidth(5,150);
        ui->tableWidget_2->setColumnWidth(6,50);
        ui->tableWidget_2->setColumnWidth(7,70);
        ui->tableWidget_2->setColumnWidth(8,50);
    }

    normalWindows::~normalWindows()
    {
        delete ui;
    }

    void normalWindows::on_backCommand_clicked()
    {
        close();
        loginWindows *login = new loginWindows;
        login->show();
    }

    void normalWindows::on_pushButton_clicked()
    {
        ui->stackedWidget->setCurrentIndex(0);
        //查询车次的函数
    }

    void normalWindows::on_pushButtonresearch_clicked()
    {
        a = ui->lineEditdeparture->text().toStdString();
        b = ui->lineEditdestination->text().toStdString();
        c = ui->lineEditdate->text().toStdString();
        if(ui->lineEditdate->text()==""||ui->lineEditdeparture->text()==""||ui->lineEditdestination->text().isEmpty())
            QMessageBox::warning(this,tr("警告信息"),tr("起始站或日期为空，不能查询"));
        ui->tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        string t=Enquiry(a, b, c);
        std::istringstream sin(t);
        string tmp;
        for (int i = 0; sin >> tmp; i++)
        {
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(tmp)));
            for (int j = 1; j < 15; j++)
            {
                sin>>tmp;
                ui->tableWidget->setItem(i, j, new QTableWidgetItem(QString::fromStdString(tmp)));
            }
        }

    }

    void normalWindows::on_pushButtonCheck_clicked()
    {
        a = ui->lineEditNewname->text().toStdString();
        b = ui->lineEditNewpassword->text().toStdString();
        c = ui->lineEditRepassword->text().toStdString();
        if (b != c)  QMessageBox::warning(this,tr("警告信息"),tr("两次密码不符"));
        changeInfo(a, b);
        QMessageBox::information(this,tr("提示"),tr("修改成功!"));
    }

    void normalWindows::on_pushButton_2_clicked()
    {
        ui->stackedWidget->setCurrentIndex(1);
    }

    void normalWindows::on_pushButton_3_clicked()
    {
        ui->stackedWidget->setCurrentIndex(2);
        string t = curUser->queryTicket();
        std::istringstream sin(t);
        string tmp;
        for (int i = 0; sin >> tmp; i++)
        {
            ui->tableWidget_2->insertRow(i);
            ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(tmp)));
            for (int j = 1; j < 15; j++)
            {
                sin>>tmp;
                ui->tableWidget_2->setItem(i, j, new QTableWidgetItem(QString::fromStdString(tmp)));
            }
        }
    }

    void normalWindows::on_pushButton_4_clicked()
    {
        ui->stackedWidget->setCurrentIndex(3);
    }

    void normalWindows::on_tableWidget_doubleClicked(const QModelIndex &index)
    {
        MyDialog *Dialog = new MyDialog();
        Dialog->num = ui->tableWidget->item(index.row(), 0)->text().toStdString();
        Dialog->sta = ui->tableWidget->item(index.row(), 1)->text().toStdString();
        Dialog->end = ui->tableWidget->item(index.row(), 3)->text().toStdString();
        Dialog->day = ui->tableWidget->item(index.row(), 5)->text().toStdString();
        Dialog->setui();
        Dialog->show();
    }

    void normalWindows::setui()
    {
        ui->label_9->setText(QString::fromStdString(userid));
    }


void normalWindows::on_tableWidget_2_doubleClicked(const QModelIndex &index)
{
    refund *f = new refund();
    f->num = ui->tableWidget_2->item(index.row(),0)->text().toStdString();
    f->sta = ui->tableWidget_2->item(index.row(),1)->text().toStdString();
    f->end = ui->tableWidget_2->item(index.row(),3)->text().toStdString();
    f->day = ui->tableWidget_2->item(index.row(),5)->text().toStdString();
    f->setui();
    f->show();
}

