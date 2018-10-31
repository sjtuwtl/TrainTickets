#ifndef REFUND_H
#define REFUND_H

#include <QWidget>

namespace Ui {
class refund;
}

class refund : public QWidget
{
    Q_OBJECT

public:
    explicit refund(QWidget *parent = 0);
    std::string num, sta, end, day;
    ~refund();
    void setui();

private slots:
    void on_pushButton_clicked();

private:
    Ui::refund *ui;
};

#endif // REFUND_H
