#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QGridLayout>
#include <QLabel>
#include <QFrame>
#include <QHBoxLayout>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QComboBox>
#include <QRadioButton>
#include <QComboBox>
#include <QStandardItemModel>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    QStandardItemModel model;
    QTableView tableView;
    QTabWidget *tabs;
    QFrame *tab1;
    QFrame *tab2;
    QGridLayout *layout;
    QGridLayout *tab1_l;
    QVBoxLayout *tab2_l;

    QFrame* searchPart;
    QGridLayout* searchPartLayout;
    QPushButton* btnSearchPartMore;
    QPushButton* btnSearchPartFind;
    QPushButton* btnSearchPartReset;

    QLabel* lblAFTabPartCP;
    QLineEdit* edtAFTabPartCP;
    QLabel* lblAFTabPartDate;
    QLineEdit* edtAFTabPartDate;
    QLabel* lblAFTabPartStudent;
    QLineEdit* edtAFTabPartStudent;
    QLabel* lblAFTabPartSchool;
    QLineEdit* edtAFTabPartSchool;

    QLabel* lblStudentTabPartName;
    QLineEdit* edtStudentTabPartName;
    QLabel* lblStudentTabPartGender;
    QLineEdit* edtStudentTabPartGender;
    QLabel* lblStudentTabPartAddress;
    QLineEdit* edtStudentTabPartAddress;

    QLabel* lblSchoolTabPartName;
    QLineEdit* edtSchoolTabPartName;
    QLabel* lblSchoolTabPartPrestige;
    QCheckBox* chkSchoolTabPartPrestige;
    QLabel* lblSchoolTabPartType;
    QComboBox* cmbSchoolTabPartType;
    QLabel* lblSchoolTabPartFocus;
    QComboBox* cbxSchoolTabPartFocus;
    QRadioButton* rbtSchoolTabPartManual;
    QRadioButton* rbtSchoolTabPartTheory;
    QRadioButton* rbtSchoolTabPartHybrid;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onTableClicked(QModelIndex index);
};
#endif // MAINWINDOW_H
