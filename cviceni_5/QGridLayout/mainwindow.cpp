#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // vytvoříme grid layout,  prvky se budou vkládat do mřížky
    QGridLayout *layout = new QGridLayout(this);

    // vytvoříme 3 tlačítka
    QPushButton *btn1 = new QPushButton("One");
    QPushButton *btn2 = new QPushButton("Two");
    QPushButton *btn3 = new QPushButton("Three");

    // přidáme tlačítka do layoutu
    // prvek, row, column, rowspan, columnspan
    layout->addWidget(btn1, 0, 0);
    layout->addWidget(btn2, 0, 1);
    layout->addWidget(btn3, 1, 0, 1, 2);

    // Nastavíme rozvržení
    setLayout(layout);
}

MainWindow::~MainWindow() {}
