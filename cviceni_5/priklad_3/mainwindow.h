#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QPushButton *button;
    int hodnota;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void stiskPrvni();
};
#endif // MAINWINDOW_H
