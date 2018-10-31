/********************************************************************************
** Form generated from reading UI file 'normalwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORMALWINDOWS_H
#define UI_NORMALWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_normalWindows
{
public:
    QLabel *label;
    QCommandLinkButton *backCommand;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *lineEditdeparture;
    QLabel *label_4;
    QLineEdit *lineEditdestination;
    QLabel *label_3;
    QLineEdit *lineEditdate;
    QPushButton *pushButtonresearch;
    QTableWidget *tableWidget;
    QWidget *page_2;
    QPushButton *pushButtonCheck;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QLabel *label_6;
    QLineEdit *lineEditRepassword;
    QLabel *label_5;
    QLineEdit *lineEditNewpassword;
    QLineEdit *lineEditNewname;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *page_3;
    QTableWidget *tableWidget_2;
    QWidget *page_4;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QWidget *normalWindows)
    {
        if (normalWindows->objectName().isEmpty())
            normalWindows->setObjectName(QStringLiteral("normalWindows"));
        normalWindows->resize(738, 365);
        label = new QLabel(normalWindows);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 101, 41));
        QFont font;
        font.setFamily(QStringLiteral("AcadEref"));
        font.setPointSize(12);
        label->setFont(font);
        backCommand = new QCommandLinkButton(normalWindows);
        backCommand->setObjectName(QStringLiteral("backCommand"));
        backCommand->setGeometry(QRect(630, 310, 71, 41));
        layoutWidget = new QWidget(normalWindows);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 110, 91, 181));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_4 = new QPushButton(layoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        stackedWidget = new QStackedWidget(normalWindows);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(160, 50, 551, 271));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        layoutWidget1 = new QWidget(page);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 40, 101, 186));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        lineEditdeparture = new QLineEdit(layoutWidget1);
        lineEditdeparture->setObjectName(QStringLiteral("lineEditdeparture"));

        verticalLayout->addWidget(lineEditdeparture);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        lineEditdestination = new QLineEdit(layoutWidget1);
        lineEditdestination->setObjectName(QStringLiteral("lineEditdestination"));

        verticalLayout->addWidget(lineEditdestination);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        lineEditdate = new QLineEdit(layoutWidget1);
        lineEditdate->setObjectName(QStringLiteral("lineEditdate"));

        verticalLayout->addWidget(lineEditdate);

        pushButtonresearch = new QPushButton(layoutWidget1);
        pushButtonresearch->setObjectName(QStringLiteral("pushButtonresearch"));

        verticalLayout->addWidget(pushButtonresearch);

        tableWidget = new QTableWidget(page);
        if (tableWidget->columnCount() < 15)
            tableWidget->setColumnCount(15);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(120, 30, 411, 211));
        tableWidget->horizontalHeader()->setDefaultSectionSize(70);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        pushButtonCheck = new QPushButton(page_2);
        pushButtonCheck->setObjectName(QStringLiteral("pushButtonCheck"));
        pushButtonCheck->setGeometry(QRect(210, 200, 75, 23));
        layoutWidget2 = new QWidget(page_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(140, 50, 221, 131));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 0, 0, 1, 1);

        lineEditRepassword = new QLineEdit(layoutWidget2);
        lineEditRepassword->setObjectName(QStringLiteral("lineEditRepassword"));
        lineEditRepassword->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEditRepassword, 2, 1, 1, 1);

        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        lineEditNewpassword = new QLineEdit(layoutWidget2);
        lineEditNewpassword->setObjectName(QStringLiteral("lineEditNewpassword"));
        lineEditNewpassword->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEditNewpassword, 1, 1, 1, 1);

        lineEditNewname = new QLineEdit(layoutWidget2);
        lineEditNewname->setObjectName(QStringLiteral("lineEditNewname"));

        gridLayout_2->addWidget(lineEditNewname, 0, 1, 1, 1);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(-100, 30, 54, 12));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        tableWidget_2 = new QTableWidget(page_3);
        if (tableWidget_2->columnCount() < 9)
            tableWidget_2->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(6, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(7, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(8, __qtablewidgetitem23);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(20, 50, 441, 181));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        stackedWidget->addWidget(page_4);
        label_9 = new QLabel(normalWindows);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(90, 70, 51, 20));
        label_10 = new QLabel(normalWindows);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(50, 70, 31, 16));

        retranslateUi(normalWindows);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(normalWindows);
    } // setupUi

    void retranslateUi(QWidget *normalWindows)
    {
        normalWindows->setWindowTitle(QApplication::translate("normalWindows", "\347\224\250\346\210\267", Q_NULLPTR));
        label->setText(QApplication::translate("normalWindows", "\346\202\250\345\245\275\357\274\214\347\224\250\346\210\267\357\274\201", Q_NULLPTR));
        backCommand->setText(QApplication::translate("normalWindows", "\346\263\250\351\224\200", Q_NULLPTR));
        pushButton->setText(QApplication::translate("normalWindows", "\346\237\245\350\257\242\350\275\246\346\254\241", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("normalWindows", "\344\270\252\344\272\272\344\277\241\346\201\257", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("normalWindows", "\350\264\255\347\245\250\350\256\260\345\275\225", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("normalWindows", "\345\234\250\347\272\277\345\256\242\346\234\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("normalWindows", "\350\265\267\347\202\271", Q_NULLPTR));
        label_4->setText(QApplication::translate("normalWindows", "\347\273\210\347\202\271", Q_NULLPTR));
        label_3->setText(QApplication::translate("normalWindows", "\346\227\245\346\234\237", Q_NULLPTR));
        pushButtonresearch->setText(QApplication::translate("normalWindows", "\346\237\245\350\257\242", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("normalWindows", "\350\275\246\346\254\241", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("normalWindows", "\350\265\267\347\202\271", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("normalWindows", "\345\207\272\345\217\221\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("normalWindows", "\347\273\210\347\202\271", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("normalWindows", "\345\210\260\350\276\276\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("normalWindows", "\347\261\273\345\236\213\344\270\200", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("normalWindows", "\347\245\250\344\273\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("normalWindows", "\344\275\231\347\245\250\346\225\260\351\207\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("normalWindows", "\347\261\273\345\236\213\344\272\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("normalWindows", "\347\245\250\344\273\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("normalWindows", "\344\275\231\347\245\250\346\225\260\351\207\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("normalWindows", "\347\261\273\345\236\213\344\270\211", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("normalWindows", "\347\245\250\344\273\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("normalWindows", "\344\275\231\347\245\250\346\225\260\351\207\217", Q_NULLPTR));
        pushButtonCheck->setText(QApplication::translate("normalWindows", "\347\241\256\345\256\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("normalWindows", "\346\226\260\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        label_5->setText(QApplication::translate("normalWindows", "\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        label_7->setText(QApplication::translate("normalWindows", "\345\206\215\346\254\241\350\276\223\345\205\245\346\226\260\345\257\206\347\240\201", Q_NULLPTR));
        label_8->setText(QString());
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("normalWindows", "\350\275\246\346\254\241", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("normalWindows", "\350\265\267\347\202\271", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("normalWindows", "\345\207\272\345\217\221\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("normalWindows", "\347\273\210\347\202\271", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QApplication::translate("normalWindows", "\345\210\260\350\276\276\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QApplication::translate("normalWindows", "\346\227\245\346\234\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_2->horizontalHeaderItem(6);
        ___qtablewidgetitem20->setText(QApplication::translate("normalWindows", "\347\245\250\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_2->horizontalHeaderItem(7);
        ___qtablewidgetitem21->setText(QApplication::translate("normalWindows", "\344\273\267\346\240\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_2->horizontalHeaderItem(8);
        ___qtablewidgetitem22->setText(QApplication::translate("normalWindows", "\346\225\260\351\207\217", Q_NULLPTR));
        label_9->setText(QApplication::translate("normalWindows", "TextLabel", Q_NULLPTR));
        label_10->setText(QApplication::translate("normalWindows", "\350\264\246\345\217\267", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class normalWindows: public Ui_normalWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMALWINDOWS_H
