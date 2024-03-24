#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <iostream>
class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QLineEdit* console;
    QPushButton* btn0;
    QPushButton* btn1;
    QPushButton* btn2;
    QPushButton* btn3;
    QPushButton* btn4;
    QPushButton* btn5;
    QPushButton* btn6;
    QPushButton* btn7;
    QPushButton* btn8;
    QPushButton* btn9;
    QPushButton* btnClear;
    QPushButton* btnPlus;
    QPushButton* btnMinus;
    QPushButton* btnMod;
    QPushButton* btnDiv;
    QPushButton* btnMul;
    QPushButton* btnEqual;
    QPushButton* btnDot;
    QPushButton* btnSign;
    double calculate(double a, double b, char op);
private slots:
    void mySlot();
    void putChar();
    void clearConsole();
    void solveEquation();
    void changeSign();
    void applyMod();
};
#endif // MAINWINDOW_H
