#ifndef GOODS_H
#define GOODS_H
#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QMainWindow>
#include <QStringListModel>
#include "database.h"
#include <QDialog>
#include <QDialog>
#include <QMessageBox>
#include "comboboxmodel.h"

namespace Ui {
class Goods;
}

class GoodsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GoodsWindow(QWidget *parent = nullptr);
    void setupGoodsModel();
    void setupUi();
    ~GoodsWindow();

public slots:

private slots:
    void slotAddGoods();
private:
    Ui::Goods *ui;
    QSqlTableModel *goodsmodel;
    ComboBoxModel *kindcomboxmodel;
    ComboBoxModel *unitcomboxmodel;
};

#endif // GOODS_H
