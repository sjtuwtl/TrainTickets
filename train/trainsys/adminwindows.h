#ifndef ADMINWINDOWS_H
#define ADMINWINDOWS_H

#include <QWidget>

namespace Ui {
class adminWindows;
}

class adminWindows : public QWidget
{
    Q_OBJECT

public:
    explicit adminWindows(QWidget *parent = 0);
    ~adminWindows();

private slots:
    void on_backButton_clicked();

    void on_cheSysButton_clicked();

    void on_addPlanButton_clicked();

    void on_delPlanButton_clicked();

    void on_modPlanButton_clicked();

    void on_updSellButton_clicked();

    void on_cheUserButton_clicked();

    void on_checkUserButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_addNewStation_clicked();

    void on_pushButton_7_clicked();

    void on_addNewStation_2_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::adminWindows *ui;
};

#endif // ADMINWINDOWS_H
