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
    createActions();
    createMenus();
    // Top part search
    searchPart = new QFrame();
    searchPartLayout = new QGridLayout(this);
    searchPartLayout->setSizeConstraint(QLayout::SetFixedSize);
    searchPartLayout->setAlignment(Qt::AlignRight);
    btnSearchPartMore = new QPushButton("Více");
    searchPartLayout->addWidget(btnSearchPartMore, 0, 0);
    btnSearchPartFind = new QPushButton("Hledat");
    searchPartLayout->addWidget(btnSearchPartFind, 0, 1);
    btnSearchPartReset = new QPushButton("Reset");
    searchPartLayout->addWidget(btnSearchPartReset, 0, 2);
    searchPart->setLayout(searchPartLayout);
    layout->addWidget(searchPart, 0,0, Qt::AlignRight);

    // Data -> Table part
    createTable();
    //setCentralWidget(tableView);

    //layout->setAlignment(console, Qt::AlignCenter);
    // Pridani dalsich dat

    /*QList<QStandardItem*> row(n_columns);
    row = {new QStandardItem("004"),new QStandardItem("15/03/2024"), new QStandardItem("Radoslav Socha"), new QStandardItem("Gymnázium Hladnov")};
    model->appendRow(row);*/

    // Odstraneni dat

    //model->removeRow(1); // prvek s indexem 1, tzn. druhy v poradi

    layout->addWidget(tableView, 1, 0);

    // Notebook
    tabs = new QTabWidget();
    tabs->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    tab1 = new QFrame();
    tab1_l = new QHBoxLayout();
    //tab1_l->setSizeConstraint(QLayout::SetFixedSize);//Potom by to chtelo vycentrovat a fixnout size
    tab1_l->setAlignment(selection, Qt::AlignHCenter);
    tab1->setLayout(tab1_l);
    tabs->addTab(tab1, QString("Správa"));

    tab2 = new QFrame();
    tab2_l = new QHBoxLayout();
    tab2->setLayout(tab2_l);

    tabs->addTab(tab2, QString("Galerie"));
    gallery = new QFrame();
    gallery_l = new QHBoxLayout();
    tab2_l->addWidget(gallery);
    gallery->setLayout(gallery_l);
    galleryStudent = new QFrame();
    galleryStudent_l = new QVBoxLayout();
    galleryStudent->setLayout(galleryStudent_l);
    gallery_l->addWidget(galleryStudent);
    QLabel* tmp = new QLabel("Obrázek studenta");
    galleryStudentLabel = new QLabel("Obrázek studenta");
    sceneStudent = new QGraphicsScene();
    viewStudent = new QGraphicsView(sceneStudent);
    sceneStudent->addPixmap(QPixmap(":/student.png"));
    QPixmap image("E:\\Python Scripts\\URO\\QTProjekt\\QTProjekt\\student.png");
    image = image.scaled(200,150);
    galleryStudentLabel->setPixmap(image);
    galleryStudent_l->addWidget(tmp);
    galleryStudent_l->addWidget(galleryStudentLabel);
    //galleryStudent_l->addWidget(viewStudent);


    //tab3 = new QFrame();
    //tab3_l = new QHBoxLayout();
    //tab3->setLayout(tab3_l);
    //setCentralWidget(tabs);

    //tabs->addTab(tab3,QString("Škola"));


    infoWrapper = new QFrame();
    infoWrapper_l = new QGridLayout();
    infoWrapper->setLayout(infoWrapper_l);

    fAF = new QFormLayout() ;
    fAF -> addRow ("&Číslo přihlášky:", new QLineEdit () ) ;
    fAF -> addRow ("&Datum:", new QLineEdit () ) ;
    fAF -> addRow ("&Jméno studenta:",new QLineEdit() ) ;
    fAF -> addRow ("&Název školy:",new QLineEdit() ) ;
    QWidget *appFormWidget = new QWidget;
    appFormWidget->setLayout(fAF);
    //tab1_l->addWidget(appFormWidget);
    infoWrapper_l->addWidget(appFormWidget, 0, 0);

    fST = new QFormLayout() ;
    fST -> addRow ("&Jméno studenta:", new QLineEdit () ) ;
    fST -> addRow ("&Pohlaví:", new QLineEdit () ) ;//Předělat na radio
    fST -> addRow ("&Adresa:",new QLineEdit() ) ;
    fST -> addRow ("&Průměr:",new QLineEdit() ) ;
    QWidget *stuFormWidget = new QWidget;
    stuFormWidget->setLayout(fST);
    //tab2_l->addWidget(stuFormWidget);
    infoWrapper_l->addWidget(stuFormWidget, 0, 1);
    cmbSchoolTabPartType = new QComboBox();
    QStringList list2 = QStringList();
    list2.append("Střední odborná škola");
    list2.append("Střední průmyslová škola");
    list2.append("Gymnázium");
    list2.append("Učiliště");
    cmbSchoolTabPartType->insertItems(0, list2);
    fSCH = new QFormLayout() ;
    fSCH -> addRow ("&Název školy:", new QLineEdit () ) ;
    fSCH -> addRow ("&Má prestiž:", new QCheckBox () ) ;
    fSCH -> addRow ("&Typ školy:", cmbSchoolTabPartType ) ;
    fSCH -> addRow ("&Počet přihlášek 2023/24:",new QLineEdit() ) ;
    QWidget *schFormWidget = new QWidget;
    schFormWidget->setLayout(fSCH);
    //tab3_l->addWidget(schFormWidget);
    infoWrapper_l->addWidget(schFormWidget, 0, 2);
    infoWrapper_l->setSpacing(15);
    layout->addWidget(infoWrapper, 2, 0);
    // Spojeni signalu a slotu
    connect(tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(onTableClicked(QModelIndex)));

    layout->addWidget(tabs,3,0);
    selection = new QFrame();
    selection_l = new QHBoxLayout();
    selection->setLayout(selection_l);
    tab1_l->addWidget(selection, Qt::AlignHCenter);
    leftSideWrapper = new QFrame();
    leftSideWrapper_l = new QVBoxLayout();
    leftSideWrapper->setLayout(leftSideWrapper_l);
    leftSideLabel = new QLabel("Odvolaní studenti");
    leftSide = new QTextEdit();
    leftSideWrapper_l->addWidget(leftSideLabel);
    leftSideWrapper_l->addWidget(leftSide);
    rightSideWrapper = new QFrame();
    rightSideWrapper_l = new QVBoxLayout();
    rightSideWrapper->setLayout(rightSideWrapper_l);
    rightSideChoice = new QComboBox();
    QStringList list = QStringList();
    list.append("SPSEI Ostrava");
    list.append("Telekomka");
    list.append("Gymnázium Hladnov");
    rightSideChoice->insertItems(0, list);
    rightSideLabel = new QLabel("Přijatí studenti");
    rightSide = new QTextEdit();
    tab1_l->addWidget(rightSideChoice);
    rightSideWrapper_l->addWidget(rightSideLabel);
    rightSideWrapper_l->addWidget(rightSide);
    btnWrapper_l = new QVBoxLayout();
    btnWrapper = new QFrame();
    btnWrapper->setLayout(btnWrapper_l);
    QString linearGradientLeft = QString("qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));");
    QString linearGradientRight = QString("qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(0, 0, 0, 255));");
    moveRight = new QPushButton("-->");
    moveRight->setStyleSheet(QString("background-color: %1").arg(linearGradientRight));
    moveRight->setMinimumWidth(100);
    moveLeft = new QPushButton("<--");
    moveLeft->setStyleSheet(QString("background-color: %1").arg(linearGradientLeft));
    moveLeft->setMinimumWidth(100);
    btnWrapper_l->addWidget(moveRight);
    btnWrapper_l->addWidget(moveLeft);
    selection_l->addWidget(leftSideWrapper);
    selection_l->addWidget(btnWrapper);
    selection_l->addWidget(rightSideWrapper);
}

void MainWindow::createActions()
{
    this->cut_act = new QAction("Vyjmout");
    this->copy_act = new QAction("Kopírovat");
    this->paste_act = new QAction("Vložit");
    this->delete_act = new QAction("Smazat");

    exportData = new QAction(tr("&Export"), this);
    importData = new QAction(tr("&Import"), this);
    connect(exportData, &QAction::triggered, this, &MainWindow::exportFile);
    connect(importData, &QAction::triggered, this, &MainWindow::importFile);

    openOptions = new QAction(tr("&Nastavení"), this);
    connect(openOptions, &QAction::triggered, this, &MainWindow::openOptionsSlot);

    openAbout = new QAction(tr("&Info"));
    qtInfo = new QAction(tr("&Qt verze"));
    connect(openAbout, &QAction::triggered, this, &MainWindow::openAboutSlot);
    connect(qtInfo, &QAction::triggered, this, &MainWindow::openQtInfo);
}
void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&Data"));
    fileMenu->addAction(exportData);
    fileMenu->addAction(importData);

    optionsMenu = menuBar()->addMenu(tr("&Nastavení"));
    optionsMenu->addAction(openOptions);

    aboutMenu = menuBar()->addMenu(tr("&Info"));
    aboutMenu->addAction(openAbout);
    aboutMenu->addAction(qtInfo);
}
void MainWindow::createTable()
{
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
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->setModel(model);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}
/* slot pro print dat z konkretni bunky */
void MainWindow::createTabs()
{

}
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
void MainWindow::openQtInfo()
{
    QMessageBox::aboutQt(this);
}
void MainWindow::exportFile()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Uložit tabulku"), "",
                                                    tr("Text file (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }
        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_6_5);
        int rowCount = tableView->model()->rowCount();
        int columnCount = tableView->model()->columnCount();
        out << rowCount;
        out << columnCount;

        for(int row = 0; row < rowCount; row++)
            for(int column = 0; column < columnCount; column++) {
                out << tableView->model()->index(row , column).data().toString();
            }
    }
}
void MainWindow::importFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Načíst tabulku"), "",
                                                    tr("Text file (*.txt);;All Files (*)"));
    /*if (fileName.isEmpty())
        return;
    else {

        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_6_5);
        int rowCount, columnCount;
        in >> rowCount;
        in >> columnCount;
        for(int row = 0; row < rowCount; row++)
            for(int column = 0; column < columnCount; column++) {
                QString item;
                in >> item;
                tableView->model()->index(row , column).data() = item;//setItem(row, column, item)
            }
    }*/
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
#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(this->cut_act);
    menu.addAction(this->copy_act);
    menu.addAction(this->paste_act);
    menu.addSeparator();
    menu.addAction(this->delete_act);
    menu.exec(event->globalPos());
    qInfo() << "Relativní X: " << event->x();
    qInfo() << "Relativní Y: " << event->y();
    qInfo() << "Absolutní X: " << event->globalX();
    qInfo() << "Absolutní y: " << event->globalY();
}
#endif // QT_NO_CONTEXTMENU
MainWindow::~MainWindow()
{
}
