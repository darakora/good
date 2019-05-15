#include "kindnew.h"
#include "ui_kindnew.h"

Kindnew::Kindnew(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kindnew)
{
    ui->setupUi(this);
    this->setWindowTitle("Kinds");
    setupKindModel();
    setupKindUi();
    connect(ui->add_dresskind, &QPushButton::clicked, this, &Kindnew::slotAddKind);
}

Kindnew::~Kindnew()
{
    delete ui;
}

void Kindnew::setupKindModel()
{
    kindmodel = new QSqlTableModel(this);
    agecomboxmodel = new ComboBoxModel(QSqlQuery("SELECT id, age from Age"));
    categorycomboxmodel = new ComboBoxModel(QSqlQuery("SELECT id, c_name from categories"));
    kindmodel->setTable("kinds");
    kindmodel->select();
    ui->comboBox_Gender->setModel(agecomboxmodel);
    ui->comboBox_Category->setModel(categorycomboxmodel);
}

void Kindnew::setupKindUi()
{
    ui->tableView->setModel(kindmodel);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->verticalHeader()->setVisible(false);
}

void Kindnew::slotAddKind()
{
    if(!DataBase::insertIntoDressKind(QList<QVariant>{QVariant(ui->lineEdit->text()),
                                      QVariant(ui->comboBox_Category->currentData()),
                                      QVariant(ui->comboBox_Gender->currentData())}))
    {
        QMessageBox::information(this, "Error", "Error");
    }
    else {
        QMessageBox::information(this, "Info Window", "You added");
        kindmodel->select();
    }
}

void Kindnew::on_pushButton_next_clicked()
{
    hide();
    Unitswindow uwindow;
    uwindow.setModal(true);
    uwindow.exec();
}
