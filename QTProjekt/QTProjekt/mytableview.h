#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QTableView>
#include <QVBoxLayout>
#include <QDialog>

class MyTableView : public QTableView
{
private:
    void mouseDoubleClickEvent(QMouseEvent *event);
public:
    MyTableView(QWidget *parent);
};

#endif // MYTABLEVIEW_H
