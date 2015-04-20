#ifndef CALCDIV_H
#define CALCDIV_H

#include <QWidget>

class CalcDiv : public QWidget
{
    Q_OBJECT

public:
    CalcDiv(QWidget *parent = 0);
    ~CalcDiv();

private:
    int firstNumb;
    int secondNumb;
    float result;

signals:
    getResult(QString result);

private slots:
    void setFirstNumb(QString str);
    void setSecondNumb(QString str);
    void setResult();
};

#endif // CALCDIV_H
