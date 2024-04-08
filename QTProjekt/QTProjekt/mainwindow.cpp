#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    // Main layout
    QWidget* mainWidget = new QWidget();
    layout = new QGridLayout(this);
    setCentralWidget(mainWidget);
    mainWidget->setLayout(layout);
    //Menu part
    fileMenu = menuBar()->addMenu(tr("&Data"));
    exportData = new QAction(tr("&Export"), this);
    connect(exportData, &QAction::triggered, this, &MainWindow::exportFile);
    importData = new QAction(tr("&Import"), this);
    connect(importData, &QAction::triggered, this, &MainWindow::importFile);
    fileMenu->addAction(exportData);
    fileMenu->addAction(importData);

    optionsMenu = menuBar()->addMenu(tr("&Nastavení"));
    openOptions = new QAction(tr("&Nastavení"), this);
    connect(openOptions, &QAction::triggered, this, &MainWindow::openOptionsSlot);
    optionsMenu->addAction(openOptions);

    aboutMenu = menuBar()->addMenu(tr("&Info"));
    openAbout = new QAction(tr("&Info"));
    connect(openAbout, &QAction::triggered, this, &MainWindow::openAboutSlot);
    aboutMenu->addAction(openAbout);
    // Top part search
    searchPart = new QFrame();
    searchPartLayout = new QGridLayout(this);
    btnSearchPartMore = new QPushButton("Více");
    searchPartLayout->addWidget(btnSearchPartMore, 0, 0);
    btnSearchPartFind = new QPushButton("Hledat");
    searchPartLayout->addWidget(btnSearchPartFind, 0, 1);
    btnSearchPartReset = new QPushButton("Reset");
    searchPartLayout->addWidget(btnSearchPartReset, 0, 2);
    searchPart->setLayout(searchPartLayout);
    layout->addWidget(searchPart, 0,0);

    // Data -> Table part

    const int n_columns = 4;
    QString my_labels[n_columns]={"Číslo přihlášky", "Datum", "Jméno studenta", "Název školy"};
    QString my_data[4][n_columns]={
        {"001", "10/03/2024", "Karel Havlíček", "SPSEI Ostrava"},
        {"002", "11/03/2024", "Jana Nová", "Telekomka Ostrava"},
        {"003", "12/03/2024", "Petr Černý", "SPSEI Ostrava"},
        {"004", "13/03/2024", "Filip Novotný", "Telekomka Ostrava"}
    };

    // Vytvoreni modelu

    QStandardItemModel *model = new QStandardItemModel(0, n_columns, this); // 0 radku, 3 sloupce
    for(int i = 0; i < n_columns; i++){
        model->setHeaderData(i, Qt::Horizontal, my_labels[i]);
    }

    // Pridani dat do modelu

    for(const auto& my_item : my_data )
    {
        QList<QStandardItem*> row;
        for(int i = 0; i < n_columns; i++ )
        {
            row.append(new QStandardItem(my_item[i]));
        }
        model->appendRow(row);
    }

    // Zobrazeni modelu pomoci QTableView

    tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //setCentralWidget(tableView);

    //layout->setAlignment(console, Qt::AlignCenter);
    // Pridani dalsich dat

    QList<QStandardItem*> row(n_columns);
    row = {new QStandardItem("004"),new QStandardItem("15/03/2024"), new QStandardItem("Radoslav Socha"), new QStandardItem("Gymnázium Hladnov")};
    model->appendRow(row);

    // Odstraneni dat

    //model->removeRow(1); // prvek s indexem 1, tzn. druhy v poradi

    layout->addWidget(tableView, 1, 0);

    // Notebook
    tabs = new QTabWidget();
    tabs->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    tab1 = new QFrame();
    tab1_l = new QHBoxLayout();
    tab1_l->setSizeConstraint(QLayout::SetFixedSize);
    tab1->setLayout(tab1_l);

    tabs->addTab(tab1, QString("Přihláška"));

    tab2 = new QFrame();
    tab2_l = new QHBoxLayout();
    tab2->setLayout(tab2_l);

    tabs->addTab(tab2, QString("Student"));

    tab3 = new QFrame();
    tab3_l = new QHBoxLayout();
    tab3->setLayout(tab3_l);
    //setCentralWidget(tabs);

    tabs->addTab(tab3,QString("Škola"));

    layout->addWidget(tabs,2,0);

    fAF = new QFormLayout() ;
    fAF -> addRow ("&Číslo přihlášky:", new QLineEdit () ) ;
    fAF -> addRow ("&Datum:", new QLineEdit () ) ;
    fAF -> addRow ("&Jméno studenta:",new QLineEdit() ) ;
    fAF -> addRow ("&Název školy:",new QLineEdit() ) ;
    QWidget *appFormWidget = new QWidget;
    appFormWidget->setLayout(fAF);
    tab1_l->addWidget(appFormWidget);

    fST = new QFormLayout() ;
    fST -> addRow ("&Jméno studenta:", new QLineEdit () ) ;
    fST -> addRow ("&Pohlaví:", new QLineEdit () ) ;//Předělat na radio
    fST -> addRow ("&Adresa:",new QLineEdit() ) ;
    fST -> addRow ("&Průměr:",new QLineEdit() ) ;
    QWidget *stuFormWidget = new QWidget;
    stuFormWidget->setLayout(fST);
    tab2_l->addWidget(stuFormWidget);

    fSCH = new QFormLayout() ;
    fSCH -> addRow ("&Název školy:", new QLineEdit () ) ;
    fSCH -> addRow ("&Má prestiž:", new QLineEdit () ) ;
    fSCH -> addRow ("&Typ školy:",new QLineEdit() ) ;
    fSCH -> addRow ("&Počet přihlášek 2023/24:",new QLineEdit() ) ;
    QWidget *schFormWidget = new QWidget;
    schFormWidget->setLayout(fSCH);
    tab3_l->addWidget(schFormWidget);
    // Spojeni signalu a slotu
    connect(tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(onTableClicked(QModelIndex)));
}

/* slot pro print dat z konkretni bunky */

void MainWindow::onTableClicked(QModelIndex index)
{
    if (index.isValid()) {
        // Ziskat data
        int rowidx = this->tableView->selectionModel()->currentIndex().row();
        auto widget_item1 = this->fAF->itemAt(0, QFormLayout::FieldRole);
        ((QLineEdit*)widget_item1->widget())->setText(tableView->model()->index(rowidx , 0).data().toString());
        auto widget_item2 = this->fAF->itemAt(1, QFormLayout::FieldRole);
        ((QLineEdit*)widget_item2->widget())->setText(tableView->model()->index(rowidx , 1).data().toString());
        auto widget_item3 = this->fAF->itemAt(2, QFormLayout::FieldRole);
        ((QLineEdit*)widget_item3->widget())->setText(tableView->model()->index(rowidx , 2).data().toString());
        auto widget_item4 = this->fAF->itemAt(3, QFormLayout::FieldRole);
        ((QLineEdit*)widget_item4->widget())->setText(tableView->model()->index(rowidx , 3).data().toString());

        //studentName->setText(tableView->model()->index(rowidx , 0).data().toString());
        /*ui->txt2->setText(model->index(rowidx , 1).data().toString());
        ui->txt3->setText(model->index(rowidx , 2).data().toString());
        ui->txt4->setText(model->index(rowidx , 3).data().toString());*/
    }
}
void MainWindow::exportFile()
{

}
void MainWindow::importFile()
{

}
void MainWindow::openOptionsSlot()
{

}
void MainWindow::openAboutSlot()
{
    QDialog * window = new QDialog () ;
    QVBoxLayout* winLayout = new QVBoxLayout () ;
    window -> setWindowTitle (" Detail ") ;
    QWidget* formWrapper = new QWidget();
    QFormLayout* formLayout = new QFormLayout();
    QLineEdit* author = new QLineEdit("Michal Duba");
    author->setReadOnly(true);
    QLineEdit* login = new QLineEdit("DUB0074");
    login->setReadOnly(true);
    QLineEdit* version = new QLineEdit("0.1");
    version->setReadOnly(true);
    QLineEdit* edited = new QLineEdit("8/4/2024");
    edited->setReadOnly(true);
    formLayout -> addRow ("&Autor aplikace:", author ) ;
    formLayout -> addRow ("&Login:", login ) ;
    formLayout -> addRow ("&Verze:", version ) ;
    formLayout -> addRow ("&Poslední změna:", edited ) ;
    formWrapper->setLayout(formLayout);
    winLayout->addWidget(formWrapper);
    window -> setLayout ( winLayout ) ;
    window -> exec () ; // modální okno
}
MainWindow::~MainWindow()
{
}
