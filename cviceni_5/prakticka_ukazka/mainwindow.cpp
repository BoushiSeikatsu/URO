#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    edit = new QLineEdit();
    btn = new QPushButton("Click");
    lbl = new QLabel("None");

    layout->addWidget(edit);
    layout->addWidget(btn);
    layout->addWidget(lbl);

    // nastavení
    edit->setMaximumWidth(50);
    layout->setAlignment(edit, Qt::AlignCenter);
    layout->setAlignment(lbl, Qt::AlignCenter);

    connect(btn, SIGNAL(clicked()), this, SLOT(mySlot()));
}

void MainWindow::mySlot() {
    this->lbl->setText(this->edit->text());
}

MainWindow::~MainWindow() {}
