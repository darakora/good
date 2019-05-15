#include "authorization.h"
#include "ui_authorization.h"

Authorization::Authorization(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);
}

Authorization::~Authorization()
{
    delete ui;
}

void Authorization::on_buttonContinue_clicked()
{
    if(ui->admin->isChecked())
    {
        hide();
        pass = new Password(this);
        pass->setModal(true);
        pass->exec();
    }
    else if(ui->user->isChecked())
    {
        hide();
        gendermodel = new Agewindow;
        gendermodel->setModal(true);
        gendermodel->exec();
    }
    else
    {
        QMessageBox::critical(this, "Error", "You should select between USER and ADMIN!");
    }
}

void Authorization::on_buttonExit_clicked()
{
    close();
}
