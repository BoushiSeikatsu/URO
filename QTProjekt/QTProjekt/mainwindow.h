#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QGridLayout>
#include <QFormLayout>
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
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QDialog>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    QStandardItemModel model;
    QTableView* tableView;
    QTabWidget *tabs;
    QFrame *tab1;
    QFrame *tab2;
    QFrame* tab3;
    QFrame* tab2Inner;
    QGridLayout *layout;
    QHBoxLayout *tab1_l;
    QHBoxLayout *tab2_l;
    QHBoxLayout* tab3_l;

    QMenu* fileMenu;
    QAction *exportData;
    QAction* importData;
    QMenu* optionsMenu;
    QAction* openOptions;
    QMenu* aboutMenu;
    QAction* openAbout;

    QFrame* searchPart;
    QGridLayout* searchPartLayout;
    QPushButton* btnSearchPartMore;
    QPushButton* btnSearchPartFind;
    QPushButton* btnSearchPartReset;

    QFormLayout* fAF;
    QFormLayout* fST;
    QFormLayout* fSCH;
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
    void exportFile();
    void importFile();
    void openOptionsSlot();
    void openAboutSlot();
};
#endif // MAINWINDOW_H
