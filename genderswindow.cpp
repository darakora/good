#include "genderswindow.h"
#include "ui_mainwindow.h"

GendersWindow::GendersWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Genders");
    setupGendersModel();
}

GendersWindow::~GendersWindow()
{
    delete ui;
}

void GendersWindow::setupGendersModel()
{
    gendermodel = new QSqlTableModel(this);
    gendermodel->setTable("Genders");
    gendermodel->select();
    ui->tableView->setModel(gendermodel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->verticalHeader()->setVisible(false);
}

void GendersWindow::changeModelSlotCategory()
{
    ui->tableView->setModel(categorymodel);
}

void GendersWindow::on_pushButton_clicked()
{
    hide();
    CategoryWindow categorywindow;
    categorywindow.setModal(true);
    categorywindow.exec();
}

void GendersWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    hide();
    category->show();
}
