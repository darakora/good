#include "unitswindow.h"
#include "ui_unitswindow.h"

Unitswindow::Unitswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Unitswindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Units");
    setupUnitsModel();
    connect(ui->pushButton_addunit, &QPushButton::clicked, this, &Unitswindow::slotAddUnits);
}

Unitswindow::~Unitswindow()
{
    delete ui;
}

void Unitswindow::setupUnitsModel()
{
    unitsmodel = new QSqlTableModel(this);
    unitsmodel->setTable("units");
    unitsmodel->select();
    ui->tableView->setModel(unitsmodel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->verticalHeader()->setVisible(false);
}

void Unitswindow::slotAddUnits()
{
    if(!DataBase::insertIntoUnits(QList<QVariant>{QVariant(ui->lineEdit->text())}))
    {
        QMessageBox::information(this, "Error", "Error");
    }
    else {
        QMessageBox::information(this, "Info Window", "You added");
        unitsmodel->select();
    }
}

void Unitswindow::on_pushButton_Unext_clicked()
{
    hide();
    GoodsWindow gwindow;
    gwindow.setModal(true);
    gwindow.exec();
}
