/********************************************************************************
** Form generated from reading UI file 'registerwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOWS_H
#define UI_REGISTERWINDOWS_H

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

class Ui_registerWindows
{
public:
    QPushButton *sureButton;
    QPushButton *exitButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *newNameText;
    QLineEdit *newNameEdit;
    QLabel *newPassText;
    QLineEdit *newPassEdit;
    QLabel *newWordText2;
    QLineEdit *newPassEdit2;
    QLabel *label;

    void setupUi(QWidget *registerWindows)
    {
        if (registerWindows->objectName().isEmpty())
            registerWindows->setObjectName(QStringLiteral("registerWindows"));
        registerWindows->resize(400, 300);
        sureButton = new QPushButton(registerWindows);
        sureButton->setObjectName(QStringLiteral("sureButton"));
        sureButton->setGeometry(QRect(70, 240, 75, 23));
        exitButton = new QPushButton(registerWindows);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(230, 240, 75, 23));
        layoutWidget = new QWidget(registerWindows);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 50, 221, 171));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        newNameText = new QLabel(layoutWidget);
        newNameText->setObjectName(QStringLiteral("newNameText"));

        gridLayout->addWidget(newNameText, 0, 0, 1, 1);

        newNameEdit = new QLineEdit(layoutWidget);
        newNameEdit->setObjectName(QStringLiteral("newNameEdit"));

        gridLayout->addWidget(newNameEdit, 0, 1, 1, 1);

        newPassText = new QLabel(layoutWidget);
        newPassText->setObjectName(QStringLiteral("newPassText"));

        gridLayout->addWidget(newPassText, 1, 0, 1, 1);

        newPassEdit = new QLineEdit(layoutWidget);
        newPassEdit->setObjectName(QStringLiteral("newPassEdit"));

        gridLayout->addWidget(newPassEdit, 1, 1, 1, 1);

        newWordText2 = new QLabel(layoutWidget);
        newWordText2->setObjectName(QStringLiteral("newWordText2"));

        gridLayout->addWidget(newWordText2, 2, 0, 1, 1);

        newPassEdit2 = new QLineEdit(layoutWidget);
        newPassEdit2->setObjectName(QStringLiteral("newPassEdit2"));

        gridLayout->addWidget(newPassEdit2, 2, 1, 1, 1);

        label = new QLabel(registerWindows);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 61, 16));

        retranslateUi(registerWindows);

        QMetaObject::connectSlotsByName(registerWindows);
    } // setupUi

    void retranslateUi(QWidget *registerWindows)
    {
        registerWindows->setWindowTitle(QApplication::translate("registerWindows", "\346\263\250\345\206\214", Q_NULLPTR));
        sureButton->setText(QApplication::translate("registerWindows", "\347\241\256\350\256\244", Q_NULLPTR));
        exitButton->setText(QApplication::translate("registerWindows", "\345\217\226\346\266\210", Q_NULLPTR));
        newNameText->setText(QApplication::translate("registerWindows", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        newPassText->setText(QApplication::translate("registerWindows", "\345\257\206\347\240\201", Q_NULLPTR));
        newWordText2->setText(QApplication::translate("registerWindows", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        label->setText(QApplication::translate("registerWindows", "\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class registerWindows: public Ui_registerWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOWS_H
