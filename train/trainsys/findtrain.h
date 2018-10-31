#ifndef FINDTRAIN_H
#define FINDTRAIN_H

#include <QWidget>
#include <QMessageBox>
#include <string>
using std::string;

namespace Ui {
class findtrain;
}

class findtrain : public QWidget
{
    Q_OBJECT

public:
    explicit findtrain(QWidget *parent = 0);
    ~findtrain();

private slots:
    void on_pushButtonresearch_clicked();

private:
    Ui::findtrain *ui;
    string a, b, c;
};

#endif // FINDTRAIN_H
