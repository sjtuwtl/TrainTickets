/********************************************************************************
** Form generated from reading UI file 'regdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGDIALOG_H
#define UI_REGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_regDialog
{
public:
    QPushButton *reLogin;
    QLabel *idText;
    QTextBrowser *idBrowser;

    void setupUi(QDialog *regDialog)
    {
        if (regDialog->objectName().isEmpty())
            regDialog->setObjectName(QStringLiteral("regDialog"));
        regDialog->resize(400, 300);
        reLogin = new QPushButton(regDialog);
        reLogin->setObjectName(QStringLiteral("reLogin"));
        reLogin->setGeometry(QRect(160, 210, 75, 23));
        idText = new QLabel(regDialog);
        idText->setObjectName(QStringLiteral("idText"));
        idText->setGeometry(QRect(80, 70, 54, 12));
        idBrowser = new QTextBrowser(regDialog);
        idBrowser->setObjectName(QStringLiteral("idBrowser"));
        idBrowser->setGeometry(QRect(100, 120, 181, 41));
        QFont font;
        font.setFamily(QStringLiteral("AcadEref"));
        font.setPointSize(16);
        idBrowser->setFont(font);

        retranslateUi(regDialog);

        QMetaObject::connectSlotsByName(regDialog);
    } // setupUi

    void retranslateUi(QDialog *regDialog)
    {
        regDialog->setWindowTitle(QApplication::translate("regDialog", "\346\210\220\345\212\237\357\274\201", Q_NULLPTR));
        reLogin->setText(QApplication::translate("regDialog", "\350\277\224\345\233\236\347\231\273\345\275\225", Q_NULLPTR));
        idText->setText(QApplication::translate("regDialog", "\346\202\250\347\232\204ID\346\230\257\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class regDialog: public Ui_regDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGDIALOG_H
