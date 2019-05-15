#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QSqlTableModel>
#include <QDialogButtonBox>
#include <QMainWindow>
#include <QStringListModel>
#include "database.h"
#include "categorywindow.h"

namespace Ui {
class MainWindow;
}

class GendersWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit GendersWindow(QWidget *parent = nullptr);
    ~GendersWindow();

private:
    Ui::MainWindow *ui;
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

#endif // MAINWINDOW_H
