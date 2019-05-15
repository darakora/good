#ifndef UNITSWINDOW_H
#define UNITSWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QStringListModel>
#include "database.h"
#include <QDialog>
#include <QMessageBox>
#include "goodswindow.h"

namespace Ui {
class Unitswindow;
}

class Unitswindow : public QDialog
{
    Q_OBJECT

public:
    explicit Unitswindow(QWidget *parent = nullptr);
    ~Unitswindow();

public slots:
    void setupUnitsModel();
    void slotAddUnits();

private slots:
    void on_pushButton_Unext_clicked();

private:
    Ui::Unitswindow *ui;
    QSqlTableModel *unitsmodel;

};

#endif // UNITSWINDOW_H
