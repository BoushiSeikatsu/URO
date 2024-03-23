#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // vytvoříme horizontální layout, prvky se budou vkládat vedle sebe
    QHBoxLayout *layout = new QHBoxLayout(this);

    // vytvoříme 3 tlačítka
    QPushButton *btn1 = new QPushButton("One");
    QPushButton *btn2 = new QPushButton("Two");
    QPushButton *btn3 = new QPushButton("Three");

    // přidáme tlačítka do layoutu
    layout->addWidget(btn1);
    layout->addWidget(btn2);
    layout->addWidget(btn3);

    // Nastavíme rozvržení centrálního widgetu
    setLayout(layout);
}

MainWindow::~MainWindow() {}
