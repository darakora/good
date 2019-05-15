#ifndef GENDERWINDOW_H
#define GENDERWINDOW_H

#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QMainWindow>
#include <QStringListModel>
#include "database.h"
#include "categorywindow.h"
#include <QDialog>

namespace Ui {
class Genderwindow;
}

class Agewindow : public QDialog
{
    Q_OBJECT

public:
    explicit Agewindow(QWidget *parent = nullptr);
    ~Agewindow();

private:
    Ui::Genderwindow *ui;
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    QSqlTableModel *gendermodel;
    QSqlTableModel *categorymodel;
    QSqlTableModel *goodsmodel;
    CategoryWindow *category;
    void setupGendersModel();
    void setupStringListModel();

public slots:
    void changeModelSlotCategory();


private slots:
    void on_pushButton_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);
};

#endif // GENDERWINDOW_H
