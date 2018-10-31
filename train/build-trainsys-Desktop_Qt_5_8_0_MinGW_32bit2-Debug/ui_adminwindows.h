/********************************************************************************
** Form generated from reading UI file 'adminwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOWS_H
#define UI_ADMINWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminWindows
{
public:
    QLabel *label;
    QCommandLinkButton *backButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *modPlanButton;
    QPushButton *delPlanButton;
    QPushButton *addPlanButton;
    QPushButton *cheUserButton;
    QPushButton *cheSysButton;
    QPushButton *updSellButton;
    QStackedWidget *stackedWidget;
    QWidget *page_6;
    QLabel *label_16;
    QPushButton *pushButton_7;
    QTableWidget *addTable;
    QLabel *label_20;
    QLineEdit *trainIdEdit;
    QPushButton *addNewStation;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QLabel *label_21;
    QLineEdit *seat_1;
    QLabel *label_22;
    QLineEdit *seat_2;
    QLabel *label_23;
    QLineEdit *seat_3;
    QWidget *page_5;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_7;
    QWidget *page_4;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QPushButton *addNewStation_2;
    QLineEdit *seat_4;
    QLineEdit *seat_5;
    QLabel *label_27;
    QLineEdit *seat_6;
    QPushButton *pushButton_8;
    QLabel *label_28;
    QLineEdit *trainIdEdit_2;
    QTableWidget *addTable_2;
    QWidget *page_3;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_11;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLabel *label_17;
    QLineEdit *reIdEdit;
    QLineEdit *usernameEdit;
    QLabel *label_19;
    QLabel *label_4;
    QLabel *label_12;
    QLabel *label_18;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *idEdit;
    QPushButton *checkUserButton;
    QTextBrowser *logBrowser;
    QWidget *page_2;
    QTableWidget *tableWidget_3;
    QLabel *label_13;

    void setupUi(QWidget *adminWindows)
    {
        if (adminWindows->objectName().isEmpty())
            adminWindows->setObjectName(QStringLiteral("adminWindows"));
        adminWindows->resize(738, 417);
        label = new QLabel(adminWindows);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(33, 31, 111, 21));
        QFont font;
        font.setFamily(QStringLiteral("AcadEref"));
        font.setPointSize(12);
        label->setFont(font);
        backButton = new QCommandLinkButton(adminWindows);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(650, 370, 71, 41));
        layoutWidget = new QWidget(adminWindows);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 70, 101, 261));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        modPlanButton = new QPushButton(layoutWidget);
        modPlanButton->setObjectName(QStringLiteral("modPlanButton"));

        gridLayout->addWidget(modPlanButton, 3, 0, 1, 1);

        delPlanButton = new QPushButton(layoutWidget);
        delPlanButton->setObjectName(QStringLiteral("delPlanButton"));

        gridLayout->addWidget(delPlanButton, 2, 0, 1, 1);

        addPlanButton = new QPushButton(layoutWidget);
        addPlanButton->setObjectName(QStringLiteral("addPlanButton"));

        gridLayout->addWidget(addPlanButton, 1, 0, 1, 1);

        cheUserButton = new QPushButton(layoutWidget);
        cheUserButton->setObjectName(QStringLiteral("cheUserButton"));

        gridLayout->addWidget(cheUserButton, 5, 0, 1, 1);

        cheSysButton = new QPushButton(layoutWidget);
        cheSysButton->setObjectName(QStringLiteral("cheSysButton"));

        gridLayout->addWidget(cheSysButton, 6, 0, 1, 1);

        updSellButton = new QPushButton(layoutWidget);
        updSellButton->setObjectName(QStringLiteral("updSellButton"));

        gridLayout->addWidget(updSellButton, 4, 0, 1, 1);

        stackedWidget = new QStackedWidget(adminWindows);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(160, 20, 551, 355));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        label_16 = new QLabel(page_6);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(40, 30, 81, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("AcadEref"));
        font1.setPointSize(10);
        label_16->setFont(font1);
        pushButton_7 = new QPushButton(page_6);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(360, 270, 75, 23));
        addTable = new QTableWidget(page_6);
        if (addTable->columnCount() < 7)
            addTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        addTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        addTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        addTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        addTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        addTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        addTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        addTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        addTable->setObjectName(QStringLiteral("addTable"));
        addTable->setGeometry(QRect(40, 60, 391, 191));
        label_20 = new QLabel(page_6);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(270, 30, 31, 16));
        trainIdEdit = new QLineEdit(page_6);
        trainIdEdit->setObjectName(QStringLiteral("trainIdEdit"));
        trainIdEdit->setGeometry(QRect(320, 30, 113, 20));
        addNewStation = new QPushButton(page_6);
        addNewStation->setObjectName(QStringLiteral("addNewStation"));
        addNewStation->setGeometry(QRect(40, 270, 75, 23));
        widget = new QWidget(page_6);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(440, 60, 81, 128));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(widget);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_3->addWidget(label_21, 0, 0, 1, 1);

        seat_1 = new QLineEdit(widget);
        seat_1->setObjectName(QStringLiteral("seat_1"));

        gridLayout_3->addWidget(seat_1, 1, 0, 1, 1);

        label_22 = new QLabel(widget);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_3->addWidget(label_22, 2, 0, 1, 1);

        seat_2 = new QLineEdit(widget);
        seat_2->setObjectName(QStringLiteral("seat_2"));

        gridLayout_3->addWidget(seat_2, 3, 0, 1, 1);

        label_23 = new QLabel(widget);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_3->addWidget(label_23, 4, 0, 1, 1);

        seat_3 = new QLineEdit(widget);
        seat_3->setObjectName(QStringLiteral("seat_3"));

        gridLayout_3->addWidget(seat_3, 5, 0, 1, 1);

        stackedWidget->addWidget(page_6);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        label_14 = new QLabel(page_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(40, 30, 81, 21));
        label_14->setFont(font1);
        label_15 = new QLabel(page_5);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(110, 120, 54, 12));
        pushButton_6 = new QPushButton(page_5);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(160, 182, 61, 21));
        lineEdit_7 = new QLineEdit(page_5);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(170, 120, 113, 20));
        stackedWidget->addWidget(page_5);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        label_24 = new QLabel(page_4);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(440, 70, 79, 12));
        label_25 = new QLabel(page_4);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(440, 114, 79, 12));
        label_26 = new QLabel(page_4);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(40, 40, 81, 21));
        label_26->setFont(font1);
        addNewStation_2 = new QPushButton(page_4);
        addNewStation_2->setObjectName(QStringLiteral("addNewStation_2"));
        addNewStation_2->setGeometry(QRect(40, 280, 75, 23));
        seat_4 = new QLineEdit(page_4);
        seat_4->setObjectName(QStringLiteral("seat_4"));
        seat_4->setGeometry(QRect(440, 176, 79, 20));
        seat_5 = new QLineEdit(page_4);
        seat_5->setObjectName(QStringLiteral("seat_5"));
        seat_5->setGeometry(QRect(440, 132, 79, 20));
        label_27 = new QLabel(page_4);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(440, 158, 79, 12));
        seat_6 = new QLineEdit(page_4);
        seat_6->setObjectName(QStringLiteral("seat_6"));
        seat_6->setGeometry(QRect(440, 88, 79, 20));
        pushButton_8 = new QPushButton(page_4);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(360, 280, 75, 23));
        label_28 = new QLabel(page_4);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(270, 40, 31, 16));
        trainIdEdit_2 = new QLineEdit(page_4);
        trainIdEdit_2->setObjectName(QStringLiteral("trainIdEdit_2"));
        trainIdEdit_2->setGeometry(QRect(320, 40, 113, 20));
        addTable_2 = new QTableWidget(page_4);
        if (addTable_2->columnCount() < 7)
            addTable_2->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        addTable_2->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        addTable_2->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        addTable_2->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        addTable_2->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        addTable_2->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        addTable_2->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        addTable_2->setHorizontalHeaderItem(6, __qtablewidgetitem13);
        addTable_2->setObjectName(QStringLiteral("addTable_2"));
        addTable_2->setGeometry(QRect(40, 70, 391, 191));
        stackedWidget->addWidget(page_4);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        label_5 = new QLabel(page_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(120, 120, 54, 12));
        label_6 = new QLabel(page_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(120, 160, 54, 12));
        pushButton = new QPushButton(page_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 290, 75, 23));
        pushButton_2 = new QPushButton(page_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 290, 75, 23));
        lineEdit_2 = new QLineEdit(page_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 120, 113, 20));
        lineEdit_3 = new QLineEdit(page_3);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(200, 160, 113, 20));
        label_11 = new QLabel(page_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 30, 91, 21));
        label_11->setFont(font1);
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(120, 120, 54, 12));
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(120, 160, 54, 12));
        stackedWidget->addWidget(page_3);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 2);

        label_17 = new QLabel(page);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_2->addWidget(label_17, 2, 0, 1, 1);

        reIdEdit = new QLineEdit(page);
        reIdEdit->setObjectName(QStringLiteral("reIdEdit"));

        gridLayout_2->addWidget(reIdEdit, 2, 1, 1, 1);

        usernameEdit = new QLineEdit(page);
        usernameEdit->setObjectName(QStringLiteral("usernameEdit"));

        gridLayout_2->addWidget(usernameEdit, 3, 1, 1, 1);

        label_19 = new QLabel(page);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_2->addWidget(label_19, 4, 0, 1, 1);

        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 5, 0, 1, 2);

        label_12 = new QLabel(page);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);

        gridLayout_2->addWidget(label_12, 0, 0, 1, 2);

        label_18 = new QLabel(page);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_2->addWidget(label_18, 3, 0, 1, 1);

        passwordEdit = new QLineEdit(page);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));

        gridLayout_2->addWidget(passwordEdit, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        idEdit = new QLineEdit(page);
        idEdit->setObjectName(QStringLiteral("idEdit"));

        horizontalLayout->addWidget(idEdit);

        checkUserButton = new QPushButton(page);
        checkUserButton->setObjectName(QStringLiteral("checkUserButton"));

        horizontalLayout->addWidget(checkUserButton);


        gridLayout_2->addLayout(horizontalLayout, 0, 2, 1, 1);

        logBrowser = new QTextBrowser(page);
        logBrowser->setObjectName(QStringLiteral("logBrowser"));

        gridLayout_2->addWidget(logBrowser, 6, 0, 1, 3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        tableWidget_3 = new QTableWidget(page_2);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(40, 90, 431, 161));
        label_13 = new QLabel(page_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 30, 101, 21));
        label_13->setFont(font1);
        stackedWidget->addWidget(page_2);

        retranslateUi(adminWindows);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(adminWindows);
    } // setupUi

    void retranslateUi(QWidget *adminWindows)
    {
        adminWindows->setWindowTitle(QApplication::translate("adminWindows", "\347\256\241\347\220\206\345\221\230", Q_NULLPTR));
        label->setText(QApplication::translate("adminWindows", "\346\202\250\345\245\275\357\274\214\347\256\241\347\220\206\345\221\230\357\274\201", Q_NULLPTR));
        backButton->setText(QApplication::translate("adminWindows", "\346\263\250\351\224\200", Q_NULLPTR));
        modPlanButton->setText(QApplication::translate("adminWindows", "\344\277\256\346\224\271\350\277\220\350\241\214\350\256\241\345\210\222", Q_NULLPTR));
        delPlanButton->setText(QApplication::translate("adminWindows", "\345\210\240\351\231\244\350\277\220\350\241\214\350\256\241\345\210\222", Q_NULLPTR));
        addPlanButton->setText(QApplication::translate("adminWindows", "\346\267\273\345\212\240\350\277\220\350\241\214\350\256\241\345\210\222", Q_NULLPTR));
        cheUserButton->setText(QApplication::translate("adminWindows", "\346\237\245\347\234\213\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        cheSysButton->setText(QApplication::translate("adminWindows", "\346\237\245\347\234\213\347\263\273\347\273\237\346\227\245\345\277\227", Q_NULLPTR));
        updSellButton->setText(QApplication::translate("adminWindows", "\346\233\264\346\226\260\345\224\256\347\245\250\344\277\241\346\201\257", Q_NULLPTR));
        label_16->setText(QApplication::translate("adminWindows", "\346\267\273\345\212\240\350\277\220\350\241\214\350\256\241\345\210\222", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("adminWindows", "\347\241\256\350\256\244\346\267\273\345\212\240", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = addTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("adminWindows", "\350\275\246\347\253\231", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = addTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("adminWindows", "\345\210\260\350\276\276\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = addTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("adminWindows", "\345\201\234\350\275\246\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = addTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("adminWindows", "\351\207\214\347\250\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = addTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("adminWindows", "\345\235\220\345\270\2551", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = addTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("adminWindows", "\345\235\220\345\270\2552", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = addTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("adminWindows", "\345\235\220\345\270\2553", Q_NULLPTR));
        label_20->setText(QApplication::translate("adminWindows", "\350\275\246\346\254\241", Q_NULLPTR));
        addNewStation->setText(QApplication::translate("adminWindows", "\346\267\273\345\212\240\350\275\246\347\253\231", Q_NULLPTR));
        label_21->setText(QApplication::translate("adminWindows", "\345\235\220\345\270\2551", Q_NULLPTR));
        label_22->setText(QApplication::translate("adminWindows", "\345\235\220\345\270\2552", Q_NULLPTR));
        label_23->setText(QApplication::translate("adminWindows", "\345\235\220\345\270\2553", Q_NULLPTR));
        label_14->setText(QApplication::translate("adminWindows", "\345\210\240\351\231\244\350\277\220\350\241\214\350\256\241\345\210\222", Q_NULLPTR));
        label_15->setText(QApplication::translate("adminWindows", "\350\275\246\346\254\241", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("adminWindows", "\347\241\256\350\256\244\345\210\240\351\231\244", Q_NULLPTR));
        label_24->setText(QApplication::translate("adminWindows", "\345\235\220\345\270\2551", Q_NULLPTR));
        label_25->setText(QApplication::translate("adminWindows", "\345\235\220\345\270\2552", Q_NULLPTR));
        label_26->setText(QApplication::translate("adminWindows", "\344\277\256\346\224\271\350\277\220\350\241\214\350\256\241\345\210\222", Q_NULLPTR));
        addNewStation_2->setText(QApplication::translate("adminWindows", "\346\267\273\345\212\240\350\275\246\347\253\231", Q_NULLPTR));
        label_27->setText(QApplication::translate("adminWindows", "\345\235\220\345\270\2553", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("adminWindows", "\347\241\256\350\256\244\344\277\256\346\224\271", Q_NULLPTR));
        label_28->setText(QApplication::translate("adminWindows", "\350\275\246\346\254\241", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = addTable_2->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("adminWindows", "\350\275\246\347\253\231", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = addTable_2->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("adminWindows", "\345\210\260\350\276\276\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = addTable_2->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("adminWindows", "\345\201\234\350\275\246\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = addTable_2->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("adminWindows", "\351\207\214\347\250\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = addTable_2->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("adminWindows", "\345\235\220\345\270\2551", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = addTable_2->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("adminWindows", "\345\235\220\345\270\2552", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = addTable_2->horizontalHeaderItem(6);
        ___qtablewidgetitem13->setText(QApplication::translate("adminWindows", "\345\235\220\345\270\2553", Q_NULLPTR));
        label_5->setText(QApplication::translate("adminWindows", "\350\275\246\346\254\241", Q_NULLPTR));
        label_6->setText(QApplication::translate("adminWindows", "\346\227\245\346\234\237", Q_NULLPTR));
        pushButton->setText(QApplication::translate("adminWindows", "\345\274\200\345\247\213\345\224\256\347\245\250", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("adminWindows", "\345\201\234\346\255\242\345\224\256\347\245\250", Q_NULLPTR));
        label_11->setText(QApplication::translate("adminWindows", "\346\233\264\346\226\260\345\224\256\347\245\250\344\277\241\346\201\257", Q_NULLPTR));
        label_7->setText(QApplication::translate("adminWindows", "\350\275\246\346\254\241", Q_NULLPTR));
        label_8->setText(QApplication::translate("adminWindows", "\346\227\245\346\234\237", Q_NULLPTR));
        label_3->setText(QApplication::translate("adminWindows", "\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        label_17->setText(QApplication::translate("adminWindows", "ID\357\274\232", Q_NULLPTR));
        label_19->setText(QApplication::translate("adminWindows", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("adminWindows", "\347\224\250\346\210\267\346\227\245\345\277\227", Q_NULLPTR));
        label_12->setText(QApplication::translate("adminWindows", "\346\237\245\347\234\213\347\224\250\346\210\267\344\277\241\346\201\257", Q_NULLPTR));
        label_18->setText(QApplication::translate("adminWindows", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("adminWindows", "\350\264\246\345\217\267\357\274\232", Q_NULLPTR));
        checkUserButton->setText(QApplication::translate("adminWindows", "\346\237\245\350\257\242", Q_NULLPTR));
        label_13->setText(QApplication::translate("adminWindows", "\346\237\245\347\234\213\347\263\273\347\273\237\346\227\245\345\277\227", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class adminWindows: public Ui_adminWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOWS_H
