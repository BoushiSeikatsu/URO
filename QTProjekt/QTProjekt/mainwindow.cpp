#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    // Main layout
    QWidget* mainWidget = new QWidget();
    layout = new QGridLayout(this);
    setCentralWidget(mainWidget);
    mainWidget->setLayout(layout);

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

    const int n_columns = 3;
    QString my_labels[n_columns]={"Name", "City", "Age"};
    QString my_data[4][n_columns]={
        {"John Doe", "Ostrava", "30"},
        {"Jane Doe", "Ostrava", "25"},
        {"Bob Doe", "Praha", "30"},
        {"Brenda Doe", "Brno", "45"}
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

    QTableView *tableView = new QTableView(this);
    tableView->setModel(model);
    //setCentralWidget(tableView);

    //layout->setAlignment(console, Qt::AlignCenter);
    // Pridani dalsich dat

    QList<QStandardItem*> row(n_columns);
    row = {new QStandardItem("Dylan Doe"),new QStandardItem("Pardubice"), new QStandardItem("50")};
    model->appendRow(row);

    // Odstraneni dat

    //model->removeRow(1); // prvek s indexem 1, tzn. druhy v poradi

    layout->addWidget(tableView, 1, 0);

    // Notebook
    tabs = new QTabWidget();
    tabs->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    tab1 = new QFrame();
    tab1_l = new QGridLayout();
    tab1_l->addWidget(new QLabel(QString("Adresa")), 0, 0);
    tab1_l->setSizeConstraint(QLayout::SetFixedSize);
    tab1->setLayout(tab1_l);

    tabs->addTab(tab1, QString("Adresa"));

    tab2 = new QFrame();
    tab2_l = new QVBoxLayout();
    tab2_l->addWidget(new QLabel(QString("Poznámka")));
    tab2_l->addWidget(new QLabel(QString("Test")));
    tab2->setLayout(tab2_l);

    tabs->addTab(tab2, QString("Poznámka"));

    //setCentralWidget(tabs);
    layout->addWidget(tabs,2,0);


    // Spojeni signalu a slotu
    connect(tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(onTableClicked(QModelIndex)));
}

/* slot pro print dat z konkretni bunky */

void MainWindow::onTableClicked(QModelIndex index)
{
    if (index.isValid()) {
        // Ziskat data
        QString cellText = index.data().toString();
        std::string text = "Clicked: " + cellText.toStdString();
        qInfo(text.c_str());
    }
}

MainWindow::~MainWindow()
{
}
