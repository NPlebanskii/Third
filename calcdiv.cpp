#include "calcdiv.h"

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

CalcDiv::CalcDiv(QWidget *parent)
    : QWidget(parent)
{
    QLabel *firstLabel = new QLabel("&First number:");
    QLabel *secondLabel = new QLabel("&Second number:");
    QLabel *resultLabel = new QLabel("&Result:");

    QLineEdit *firstNumber = new QLineEdit;
    QLineEdit *secondNumber = new QLineEdit;
    QLineEdit *result = new QLineEdit;

    QPushButton *divButton = new QPushButton("/");

    firstNumber->setFixedWidth(40);
    firstNumber->setMaxLength(5);
    secondNumber->setFixedWidth(40);
    secondNumber->setMaxLength(5);
    result->setFixedWidth(40);
    result->setMaxLength(5);

    result->setReadOnly(true);

    firstLabel->setBuddy(firstNumber);
    secondLabel->setBuddy(secondNumber);
    resultLabel->setBuddy(result);

    connect(firstNumber, SIGNAL(textChanged(QString)), this, SLOT(setFirstNumb(QString)));
    connect(secondNumber, SIGNAL(textChanged(QString)), this, SLOT(setSecondNumb(QString)));
    connect(divButton, SIGNAL(clicked()), this, SLOT(setResult()));
    connect(this, SIGNAL(getResult(QString)), result, SLOT(setText(QString)));

    QHBoxLayout *firstNumbLayout = new QHBoxLayout;
    QHBoxLayout *secondNumbLayout = new QHBoxLayout;
    QHBoxLayout *resultLayout = new QHBoxLayout;

    firstNumbLayout->addWidget(firstLabel);
    firstNumbLayout->addWidget(firstNumber);

    secondNumbLayout->addWidget(secondLabel);
    secondNumbLayout->addWidget(secondNumber);

    resultLayout->addWidget(resultLabel);
    resultLayout->addWidget(result);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(firstNumbLayout);
    leftLayout->addLayout(secondNumbLayout);
    leftLayout->addLayout(resultLayout);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addLayout(leftLayout);
    layout->addWidget(divButton);

    setLayout(layout);

}

CalcDiv::~CalcDiv()
{

}

void CalcDiv::setFirstNumb(QString str)
{
    int firstNumb = str.toInt();
    this->firstNumb = firstNumb;
}

void CalcDiv::setSecondNumb(QString str)
{
    int secondNumb = str.toInt();
    this->secondNumb = secondNumb;
}

void CalcDiv::setResult()
{
    this->result = (float)this->firstNumb / (float)this->secondNumb;
    emit getResult(QString::number(this->result));
}
