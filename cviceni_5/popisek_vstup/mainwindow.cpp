#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    // vytvoříme form layout, každý řádek bude obsahovat dvojici widgetů
    QFormLayout *layout = new QFormLayout(this);

    QLineEdit *edit1 = new QLineEdit();
    QLineEdit *edit2 = new QLineEdit();

    layout->addRow("Jméno:", edit1);
    layout->addRow("Příjmení:", edit2);

    layout->setLabelAlignment(Qt::AlignRight); // jak zarovnat popisky doprava

    // Nastavíme rozvržení
    setLayout(layout);
}

MainWindow::~MainWindow() {}
