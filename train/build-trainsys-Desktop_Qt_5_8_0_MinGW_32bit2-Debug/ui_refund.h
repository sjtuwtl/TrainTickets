/********************************************************************************
** Form generated from reading UI file 'refund.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REFUND_H
#define UI_REFUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_refund
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QLabel *label_7;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_6;
    QLabel *label_8;
    QSpinBox *spinBox;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *refund)
    {
        if (refund->objectName().isEmpty())
            refund->setObjectName(QStringLiteral("refund"));
        refund->resize(400, 300);
        layoutWidget = new QWidget(refund);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 60, 177, 178));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        lineEdit_3 = new QLineEdit(layoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 3, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_6 = new QLineEdit(layoutWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 4, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        gridLayout->addWidget(spinBox, 5, 1, 1, 1);

        label = new QLabel(refund);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 20, 51, 21));
        pushButton = new QPushButton(refund);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 250, 75, 23));

        retranslateUi(refund);

        QMetaObject::connectSlotsByName(refund);
    } // setupUi

    void retranslateUi(QWidget *refund)
    {
        refund->setWindowTitle(QApplication::translate("refund", "Form", Q_NULLPTR));
        label_2->setText(QApplication::translate("refund", "\350\265\267\347\202\271\347\253\231", Q_NULLPTR));
        label_4->setText(QApplication::translate("refund", "\350\275\246\346\254\241", Q_NULLPTR));
        label_6->setText(QApplication::translate("refund", "\346\227\245\346\234\237", Q_NULLPTR));
        label_7->setText(QApplication::translate("refund", "\347\245\250\345\236\213", Q_NULLPTR));
        label_3->setText(QApplication::translate("refund", "\347\273\210\347\202\271\347\253\231", Q_NULLPTR));
        label_8->setText(QApplication::translate("refund", "\346\225\260\351\207\217", Q_NULLPTR));
        label->setText(QApplication::translate("refund", "\351\200\200\347\245\250", Q_NULLPTR));
        pushButton->setText(QApplication::translate("refund", "\347\241\256\350\256\244\351\200\200\347\245\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class refund: public Ui_refund {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REFUND_H
