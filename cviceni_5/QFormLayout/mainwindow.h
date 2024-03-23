#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>


class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton* btn1;
    QPushButton* btn2;
    QLineEdit* edit1;
    QLineEdit* edit2;
};
#endif // MAINWINDOW_H
