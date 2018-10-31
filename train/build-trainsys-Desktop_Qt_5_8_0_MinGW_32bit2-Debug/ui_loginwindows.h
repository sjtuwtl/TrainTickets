/********************************************************************************
** Form generated from reading UI file 'loginwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOWS_H
#define UI_LOGINWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loginWindows
{
public:
    QWidget *centralWidget;
    QRadioButton *normalChoice;
    QRadioButton *adminChoice;
    QCommandLinkButton *backCommand;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *usrnameLable;
    QLineEdit *usernameEdit;
    QLabel *passwordLable;
    QLineEdit *passwordEdit;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QPushButton *registerButton;
    QPushButton *loginButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *loginWindows)
    {
        if (loginWindows->objectName().isEmpty())
            loginWindows->setObjectName(QStringLiteral("loginWindows"));
        loginWindows->resize(400, 300);
        centralWidget = new QWidget(loginWindows);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        normalChoice = new QRadioButton(centralWidget);
        normalChoice->setObjectName(QStringLiteral("normalChoice"));
        normalChoice->setGeometry(QRect(90, 140, 89, 16));
        normalChoice->setChecked(true);
        adminChoice = new QRadioButton(centralWidget);
        adminChoice->setObjectName(QStringLiteral("adminChoice"));
        adminChoice->setGeometry(QRect(220, 140, 89, 16));
        backCommand = new QCommandLinkButton(centralWidget);
        backCommand->setObjectName(QStringLiteral("backCommand"));
        backCommand->setGeometry(QRect(320, 200, 71, 41));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 50, 241, 81));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        usrnameLable = new QLabel(layoutWidget);
        usrnameLable->setObjectName(QStringLiteral("usrnameLable"));

        gridLayout->addWidget(usrnameLable, 0, 0, 1, 1);

        usernameEdit = new QLineEdit(layoutWidget);
        usernameEdit->setObjectName(QStringLiteral("usernameEdit"));

        gridLayout->addWidget(usernameEdit, 0, 1, 1, 1);

        passwordLable = new QLabel(layoutWidget);
        passwordLable->setObjectName(QStringLiteral("passwordLable"));

        gridLayout->addWidget(passwordLable, 1, 0, 1, 1);

        passwordEdit = new QLineEdit(layoutWidget);
        passwordEdit->setObjectName(QStringLiteral("passwordEdit"));
        passwordEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(passwordEdit, 1, 1, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 170, 301, 31));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 3, 1, 1);

        registerButton = new QPushButton(widget);
        registerButton->setObjectName(QStringLiteral("registerButton"));

        gridLayout_2->addWidget(registerButton, 0, 2, 1, 1);

        loginButton = new QPushButton(widget);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        gridLayout_2->addWidget(loginButton, 0, 1, 1, 1);

        loginWindows->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(loginWindows);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        loginWindows->setMenuBar(menuBar);
        mainToolBar = new QToolBar(loginWindows);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        loginWindows->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(loginWindows);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        loginWindows->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());

        retranslateUi(loginWindows);

        QMetaObject::connectSlotsByName(loginWindows);
    } // setupUi

    void retranslateUi(QMainWindow *loginWindows)
    {
        loginWindows->setWindowTitle(QApplication::translate("loginWindows", "\347\231\273\345\275\225", Q_NULLPTR));
        normalChoice->setText(QApplication::translate("loginWindows", "\346\231\256\351\200\232\347\224\250\346\210\267", Q_NULLPTR));
        adminChoice->setText(QApplication::translate("loginWindows", "\347\256\241\347\220\206\345\221\230\347\224\250\346\210\267", Q_NULLPTR));
        backCommand->setText(QApplication::translate("loginWindows", "\351\200\200\345\207\272", Q_NULLPTR));
        usrnameLable->setText(QApplication::translate("loginWindows", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        passwordLable->setText(QApplication::translate("loginWindows", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("loginWindows", "\347\256\241\347\220\206\345\221\230\346\263\250\345\206\214", Q_NULLPTR));
        registerButton->setText(QApplication::translate("loginWindows", "\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
        loginButton->setText(QApplication::translate("loginWindows", "\347\231\273\345\275\225", Q_NULLPTR));
        menu->setTitle(QString());
        menu_2->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class loginWindows: public Ui_loginWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOWS_H
