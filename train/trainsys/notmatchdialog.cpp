#include "notmatchdialog.h"
#include "ui_notmatchdialog.h"

notMatchDialog::notMatchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notMatchDialog)
{
    ui->setupUi(this);
}

notMatchDialog::~notMatchDialog()
{
    delete ui;
}
