#ifndef ADREGISTER_H
#define ADREGISTER_H

#include <QWidget>
#include <QMessageBox>


namespace Ui {
class adregister;
}

class adregister : public QWidget
{
    Q_OBJECT

public:
    explicit adregister(QWidget *parent = 0);
    ~adregister();

private slots:
    void on_sureButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::adregister *ui;
    std::string a, b, c, d;
};

#endif // ADREGISTER_H
