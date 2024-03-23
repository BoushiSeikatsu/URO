#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    button = new QPushButton("Quit");
    this->setCentralWidget(button);
    connect(button, SIGNAL(clicked()), this, SLOT(stiskPrvni()));
}

void MainWindow::stiskPrvni(){
    qInfo("Tlacitko stisknuto!");
}

MainWindow::~MainWindow() {}
