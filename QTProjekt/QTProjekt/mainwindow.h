#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QGridLayout>
#include <QFormLayout>
#include <QLabel>
#include <QFrame>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QContextMenuEvent>
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
#include <QFileDialog>
#include <QDialog>


class MainWindow : public QMainWindow
{
private:
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
    QAction* qtInfo;

    QAction* cut_act;
    QAction* copy_act;
    QAction* paste_act;
    QAction* delete_act;

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

    void createActions();
    void createMenus();
    void createTable();
    void createTabs();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onTableClicked(QModelIndex index);
    void exportFile();
    void importFile();
    void openOptionsSlot();
    void openAboutSlot();
    void openQtInfo();
protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
};

#endif // MAINWINDOW_H
