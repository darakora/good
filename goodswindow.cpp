#include "goodswindow.h"
#include "ui_goods.h"
#include <QSqlQuery>


GoodsWindow::GoodsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Goods)
{
    ui->setupUi(this);
    this->setWindowTitle("Goods");
    setupGoodsModel();
    setupUi();
    connect(ui->pushButton_additem, &QPushButton::clicked, this, &GoodsWindow::slotAddGoods);
}
void GoodsWindow::setupGoodsModel()
{
    goodsmodel = new QSqlTableModel(this);
    kindcomboxmodel = new ComboBoxModel(QSqlQuery("SELECT d_id, d_name from Dress_kinds"));
    unitcomboxmodel = new ComboBoxModel(QSqlQuery("SELECT u_id, u_name from units"));
    goodsmodel->setTable("goods");
    goodsmodel->select();
    ui->comboBox_kind->setModel(kindcomboxmodel);
    ui->comboBox_unit->setModel(unitcomboxmodel);
}

void GoodsWindow::setupUi()
{
    ui->tableView->setModel(goodsmodel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnWidth(1,205);
    ui->tableView->setColumnWidth(2,200);
    ui->tableView->verticalHeader()->setVisible(false);
}

GoodsWindow::~GoodsWindow()
{
    delete ui;
}

void GoodsWindow::slotAddGoods()
{
    if(!DataBase::insertIntoGoods(QList<QVariant>{QVariant(ui->lineEdit_additem->text()),
                                  QVariant(ui->comboBox_kind->currentData()),
                                  QVariant(ui->comboBox_unit->currentData()),
                                  QVariant(ui->lineEdit_price->text())}))
    {
        QMessageBox::information(this, "Error", "Error");
    }
    else {
        QMessageBox::information(this, "Info Window", "You added");
        goodsmodel->select();
    }
}


