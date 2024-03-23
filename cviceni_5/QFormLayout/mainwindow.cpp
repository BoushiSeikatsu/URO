#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // vytvoříme form layout, každý řádek bude obsahovat dvojici widgetů
    QFormLayout *layout = new QFormLayout(this);

    // vytvoříme 2 tlačítka a 2 vstupní textová pole
    QPushButton *btn1 = new QPushButton("One");
    QPushButton *btn2 = new QPushButton("Two");
    QLineEdit *edit1 = new QLineEdit();
    QLineEdit *edit2 = new QLineEdit();

    // přidáme dvojice do layoutu
    layout->addRow(btn1, edit1);
    layout->addRow(btn2, edit2);

    // Nastavíme rozvržení
    setLayout(layout);
}

MainWindow::~MainWindow() {}
