#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout(this);
    console = new QLineEdit("0");
    layout->setSizeConstraint(QLayout::SetNoConstraint);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setHorizontalSpacing(0);
    layout->setVerticalSpacing(0);
    console->setFixedWidth(300);
    console->setAlignment(Qt::AlignRight);
    btn0 = new QPushButton("0");
    btn1 = new QPushButton("1");
    btn2 = new QPushButton("2");
    btn3 = new QPushButton("3");
    btn4 = new QPushButton("4");
    btn5 = new QPushButton("5");
    btn6 = new QPushButton("6");
    btn7 = new QPushButton("7");
    btn8 = new QPushButton("8");
    btn9 = new QPushButton("9");
    btnClear = new QPushButton("AC");
    btnPlus = new QPushButton("+");
    btnMinus = new QPushButton("-");
    btnMod = new QPushButton("%");
    btnDiv = new QPushButton("/");
    btnMul = new QPushButton("*");
    btnEqual = new QPushButton("=");
    btnDot = new QPushButton(".");
    btnSign = new QPushButton("+/-");
    layout->addWidget(btn0,5,0,1,2);
    layout->addWidget(btn1,4,0);
    layout->addWidget(btn2,4,1);
    layout->addWidget(btn3,4,2);
    layout->addWidget(btnPlus,4,3);
    layout->addWidget(btn4,3,0);
    layout->addWidget(btn5,3,1);
    layout->addWidget(btn6,3,2);
    layout->addWidget(btnMinus,3,3);
    layout->addWidget(btn7,2,0);
    layout->addWidget(btn8,2,1);
    layout->addWidget(btn9,2,2);
    layout->addWidget(btnMul,2,3);
    layout->addWidget(btnClear,1,0);
    layout->addWidget(btnSign,1,1);
    layout->addWidget(btnMod,1,2);
    layout->addWidget(btnDiv,1,3);
    layout->addWidget(console,0,0, 1, 4);
    layout->addWidget(btnEqual,5,3);
    layout->addWidget(btnDot, 5, 2);
    // nastavení
    layout->setAlignment(console, Qt::AlignCenter);

    //connect(btn, SIGNAL(clicked()), this, SLOT(mySlot()));
    connect(btn0, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btn1, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btn4, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btn5, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btn6, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btn7, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btn8, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btn9, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btnPlus, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btnMinus, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btnMul, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btnDiv, SIGNAL(clicked()), this, SLOT(putChar()));
    connect(btnClear, SIGNAL(clicked()), this, SLOT(clearConsole()));
    connect(btnEqual, SIGNAL(clicked()), this, SLOT(solveEquation()));
    connect(btnSign, SIGNAL(clicked()), this, SLOT(changeSign()));
    connect(btnMod, SIGNAL(clicked()), this, SLOT(applyMod()));
}

void MainWindow::mySlot() {
    //this->lbl->setText(this->edit->text());
}
void MainWindow::putChar()
{
    QObject* senderObj = sender();
    QPushButton* button = qobject_cast<QPushButton*>(senderObj);
    QString str = this->console->text();
    str = str + button->text();
    this->console->setText(str);
}
void MainWindow::clearConsole()
{
    this->console->setText("");
}
double MainWindow::calculate(double a, double b, char op)
{
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: return std::numeric_limits<double>::quiet_NaN();
    }
}
void MainWindow::solveEquation()
{
    QRegularExpression regex("([0-9]+)([*,\/,+,-])([0-9]+)");  // Match number-operator-number pattern
    QString equation = this->console->text();
    QRegularExpressionMatch match = regex.match(equation);
    if (match.hasMatch()) {
        double a = match.captured(1).toDouble();
        double b = match.captured(3).toDouble();
        char op = match.captured(2).toStdString()[0];
        this->console->setText(QString::number(calculate(a, b, op)));
    }
}
void MainWindow::changeSign()
{
    QString str = this->console->text();
    int result = -1*str.toInt();
    this->console->setText(QString::number(result));
}
void MainWindow::applyMod()
{
    QString str = this->console->text();
    float result = str.toFloat()/100;
    this->console->setText(QString::number(result));
}

MainWindow::~MainWindow() {}
