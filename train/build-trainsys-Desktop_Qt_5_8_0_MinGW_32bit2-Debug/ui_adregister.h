/********************************************************************************
** Form generated from reading UI file 'adregister.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADREGISTER_H
#define UI_ADREGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adregister
{
public:
    QPushButton *sureButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QLineEdit *newNameEdit_2;
    QLabel *newNameText_2;
    QLabel *newPassText_2;
    QLineEdit *newPassEdit_2;
    QLabel *newWordText2_2;
    QLineEdit *newPassEdit2_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *exitButton;

    void setupUi(QWidget *adregister)
    {
        if (adregister->objectName().isEmpty())
            adregister->setObjectName(QStringLiteral("adregister"));
        adregister->resize(400, 300);
        sureButton = new QPushButton(adregister);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        sureButton->setGeometry(QRect(80, 240, 75, 23));
        layoutWidget = new QWidget(adregister);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 50, 221, 171));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(20);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        newNameEdit_2 = new QLineEdit(layoutWidget);
        newNameEdit_2->setObjectName(QStringLiteral("newNameEdit_2"));

        gridLayout_2->addWidget(newNameEdit_2, 0, 1, 1, 1);

        newNameText_2 = new QLabel(layoutWidget);
        newNameText_2->setObjectName(QStringLiteral("newNameText_2"));

        gridLayout_2->addWidget(newNameText_2, 0, 0, 1, 1);

        newPassText_2 = new QLabel(layoutWidget);
        newPassText_2->setObjectName(QStringLiteral("newPassText_2"));

        gridLayout_2->addWidget(newPassText_2, 1, 0, 1, 1);

        newPassEdit_2 = new QLineEdit(layoutWidget);
        newPassEdit_2->setObjectName(QStringLiteral("newPassEdit_2"));

        gridLayout_2->addWidget(newPassEdit_2, 1, 1, 1, 1);

        newWordText2_2 = new QLabel(layoutWidget);
        newWordText2_2->setObjectName(QStringLiteral("newWordText2_2"));

        gridLayout_2->addWidget(newWordText2_2, 2, 0, 1, 1);

        newPassEdit2_2 = new QLineEdit(layoutWidget);
        newPassEdit2_2->setObjectName(QStringLiteral("newPassEdit2_2"));

        gridLayout_2->addWidget(newPassEdit2_2, 2, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 3, 0, 1, 1);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 3, 1, 1, 1);

        label = new QLabel(adregister);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 20, 61, 16));
        exitButton = new QPushButton(adregister);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(240, 240, 75, 23));

        retranslateUi(adregister);

        QMetaObject::connectSlotsByName(adregister);
    } // setupUi

    void retranslateUi(QWidget *adregister)
    {
        adregister->setWindowTitle(QApplication::translate("adregister", "Form", Q_NULLPTR));
        sureButton->setText(QApplication::translate("adregister", "\347\241\256\350\256\244\346\263\250\345\206\214", Q_NULLPTR));
        newNameText_2->setText(QApplication::translate("adregister", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        newPassText_2->setText(QApplication::translate("adregister", "\345\257\206\347\240\201", Q_NULLPTR));
        newWordText2_2->setText(QApplication::translate("adregister", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("adregister", "\346\263\250\345\206\214\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("adregister", "\347\256\241\347\220\206\345\221\230\346\263\250\345\206\214", Q_NULLPTR));
        exitButton->setText(QApplication::translate("adregister", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class adregister: public Ui_adregister {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADREGISTER_H
