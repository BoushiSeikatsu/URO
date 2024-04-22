#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QGridLayout>
#include <QFormLayout>
#include <QLabel>
#include <QTextEdit>
#include <QFrame>
#include <QHeaderView>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QContextMenuEvent>
#include <QTableView>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QGraphicsScene>
#include <QGraphicsView>
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
#include <QPixmap>


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

    QScrollArea* selectionScroll;
    QFrame* selection;
    QHBoxLayout* selection_l;
    QFrame* leftSideWrapper;
    QVBoxLayout* leftSideWrapper_l;
    QLabel* leftSideLabel;
    QTextEdit* leftSide;
    QFrame* rightSideWrapper;
    QVBoxLayout* rightSideWrapper_l;
    QLabel* rightSideLabel;
    QComboBox* rightSideChoice;
    QTextEdit* rightSide;
    QFrame* btnWrapper;
    QVBoxLayout* btnWrapper_l;
    QPushButton* moveRight;
    QPushButton* moveLeft;

    QFrame* gallery;
    QHBoxLayout* gallery_l;
    QVBoxLayout* galleryStudent_l;
    QFrame* galleryStudent;
    QLabel* galleryStudentLabel;
    QGraphicsScene* sceneStudent;
    QGraphicsView* viewStudent;

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

    QAction* findAF_act;
    QAction* resetSearch_act;

    QAction* createAF_act;
    QAction* editAF_act;
    QAction* deleteAF_act;

    QFrame* searchPart;
    QGridLayout* searchPartLayout;
    QLineEdit* edtsearchPartToFind;
    QPushButton* btnSearchPartMore;
    QPushButton* btnSearchPartFind;
    QPushButton* btnSearchPartReset;

    QGridLayout* infoWrapper_l;
    QFrame* infoWrapper;
    QFormLayout* fAF;
    QFormLayout* fST;
    QFormLayout* fSCH;
    QLabel* lblStudentTabPartName;
    QLineEdit* edtStudentTabPartName;
    QLabel* lblStudentTabPartGender;
    QLineEdit* edtStudentTabPartGender;
    QLabel* lblStudentTabPartAddress;
    QLineEdit* edtStudentTabPartAddress;
    QFrame* crudWrapper;
    QGridLayout* crudWrapper_l;
    QPushButton* crudCreate;
    QPushButton* crudEdit;
    QPushButton* crudDelete;

    QLineEdit* edtSchoolTabPartName;
    QCheckBox* chkSchoolTabPartPrestige;
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
    void resetSearch();
    void findAF();
    void createAF();
    void editAF();
    void deleteAF();
protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
};

#endif // MAINWINDOW_H
