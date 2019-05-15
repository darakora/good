#include "password.h"
#include "ui_password.h"
#include "logic.h"

Password::Password(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Password)
{
    ui->setupUi(this);
}

Password::~Password()
{
    delete ui;
}

void Password::on_buttonSignIn_clicked()
{
    if(checkPassword(ui->linePassword->text()))
    {
        hide();
        gender = new Agewindow();
        gender->setModal(true);
        gender->exec();
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Wrong password");
    }
}

