#ifndef REGISTERWINDOWS_H
#define REGISTERWINDOWS_H

#include <QWidget>
#include <QMessageBox>

using std::string;

namespace Ui {
class registerWindows;
}

class registerWindows : public QWidget
{
    Q_OBJECT

public:
    explicit registerWindows(QWidget *parent = 0);
    ~registerWindows();

private slots:
    void on_sureButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::registerWindows *ui;
    string a, b, c;

};

#endif // REGISTERWINDOWS_H
