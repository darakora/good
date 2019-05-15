#ifndef KINDNEW_H
#define KINDNEW_H

#include <QDialog>
#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QStringListModel>
#include "database.h"
#include <QDialog>
#include <QMessageBox>
#include "comboboxmodel.h"
#include "unitswindow.h"

namespace Ui {
class Kindnew;
}

class Kindnew : public QDialog
{
    Q_OBJECT

public:
    explicit Kindnew(QWidget *parent = nullptr);
    ~Kindnew();

public slots:
    void slotAddKind();
private slots:

    void on_pushButton_next_clicked();

private:
    Ui::Kindnew *ui;
    QSqlTableModel *kindmodel;
    ComboBoxModel *agecomboxmodel;
    ComboBoxModel *categorycomboxmodel;

    void setupKindModel();
    void setupKindUi();
};

#endif // KINDNEW_H
