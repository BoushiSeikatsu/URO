#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    button = new QPushButton("Quit");
    this->setCentralWidget(button);
}

MainWindow::~MainWindow() {}
