#ifndef CATEGORY_H
#define CATEGORY_H
#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QMainWindow>
#include <QStringListModel>
#include "database.h"
#include <QDialog>
#include <QMessageBox>
#include "baselistmodel.h"
#include "kindnew.h"

namespace Ui {
class Category;
}

class CategoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CategoryWindow(QWidget *parent = nullptr);
    ~CategoryWindow();

public slots:
    void changeModelSlotGoods();
    void setupCategoryModel();
private slots:
    void slotAddCategory();

    void on_pushButton_next_clicked();

private:
    Ui::Category *ui;
    QSqlTableModel *categorymodel;
};

#endif // CATEGORY_H
