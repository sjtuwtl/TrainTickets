/********************************************************************************
** Form generated from reading UI file 'notmatchdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTMATCHDIALOG_H
#define UI_NOTMATCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_notMatchDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *notMatchDialog)
    {
        if (notMatchDialog->objectName().isEmpty())
            notMatchDialog->setObjectName(QStringLiteral("notMatchDialog"));
        notMatchDialog->resize(400, 300);
        label = new QLabel(notMatchDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 90, 121, 91));

        retranslateUi(notMatchDialog);

        QMetaObject::connectSlotsByName(notMatchDialog);
    } // setupUi

    void retranslateUi(QDialog *notMatchDialog)
    {
        notMatchDialog->setWindowTitle(QApplication::translate("notMatchDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("notMatchDialog", "\347\224\250\346\210\267\345\220\215\345\257\206\347\240\201\344\270\215\345\214\271\351\205\215", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class notMatchDialog: public Ui_notMatchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTMATCHDIALOG_H
