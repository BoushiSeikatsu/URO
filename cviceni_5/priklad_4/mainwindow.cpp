#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    button = new QPushButton("Quit");
    this->setCentralWidget(button);
    connect(button, SIGNAL(clicked()), this, SLOT(stiskPrvni()));
    connect(this, SIGNAL(spoustim(int)), this, SLOT(mujSlot(int)));
}

void MainWindow::stiskPrvni(){
    qInfo("Tlacitko stisknuto!");
    emit spoustim(hodnota++);
}

void MainWindow::mujSlot(int a){
    qInfo("slot mujSlot a=%d",a);
}

MainWindow::~MainWindow() {}
