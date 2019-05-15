#include "categorywindow.h"
#include "ui_category.h"

CategoryWindow::CategoryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Category)
{
    ui->setupUi(this);
    this->setWindowTitle("Categories");
    setupCategoryModel();
    connect(ui->pushButton_Add, &QPushButton::clicked, this, &CategoryWindow::slotAddCategory);
    connect(ui->pushButton_next, &QPushButton::clicked, this, &CategoryWindow::on_pushButton_next_clicked);
}

CategoryWindow::~CategoryWindow()
{
    delete ui;
}

void CategoryWindow::setupCategoryModel()
{
   // categorymodel = new BaseListModel(QSqlQuery("SELECT id, c_name from categories"), this);
    //ui->listView_Category->setModel(categorymodel);
    categorymodel = new QSqlTableModel(this);
    categorymodel->setTable("categories");
    categorymodel->select();
    ui->tableView->setModel(categorymodel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->verticalHeader()->setVisible(false);
}

void CategoryWindow::changeModelSlotGoods()
{
    //ui->tableView->setModel(goodsmodel);
}


void CategoryWindow::slotAddCategory()
{
    if(!DataBase::insertIntoCategories(ui->lineEdit->text()))
    {
        QMessageBox::information(this, "Error", "Error");
    }
    else {
        QMessageBox::information(this, "Info Window", "You added");
        categorymodel->select();
    }
}

void CategoryWindow::on_pushButton_next_clicked()
{
      hide();
      Kindnew kwindow;
      kwindow.setModal(true);
      kwindow.exec();
}
