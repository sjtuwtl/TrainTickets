#include "regdialog.h"
#include "ui_regdialog.h"
#include "QDialog"

regDialog::regDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regDialog)
{
    ui->setupUi(this);
}

regDialog::~regDialog()
{
    delete ui;
}

void regDialog::useDialog(QString id) {
    ui->idBrowser->setPlainText(id);
    this->show();
}


void regDialog::on_reLogin_clicked()
{
    close();
}
