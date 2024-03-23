#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QPushButton *button;
    int hodnota=0;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void stiskPrvni();
    void mujSlot(int a);
signals:
    void spoustim(int n);
};
#endif // MAINWINDOW_H
