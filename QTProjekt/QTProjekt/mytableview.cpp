#include "mytableview.h"

MyTableView::MyTableView(QWidget *parent) : QTableView(parent) {}
void MyTableView::mouseDoubleClickEvent(QMouseEvent *event)
{
    QDialog * window = new QDialog () ;
    QVBoxLayout * winLayout = new QVBoxLayout () ;
    window -> setWindowTitle (" Detail ") ;
    // ...
    window -> setLayout ( winLayout ) ;
    window -> exec () ; // modální okno

}
