#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QMainWindow>
#include <QStringListModel>
#include <QMainWindow>
#include "goodswindow.h"
#include "database.h"
#include "agewindow.h"
#include "password.h"

namespace Ui {
class Authorization;
}

class Authorization : public QMainWindow
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    ~Authorization();

private slots:
    void on_buttonContinue_clicked();
    void on_buttonExit_clicked();

private:
    Ui::Authorization *ui;
    Agewindow *gendermodel;
    Password *pass;
};

#endif // AUTHORIZATION_H
