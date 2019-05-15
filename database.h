#ifndef DATABASE_H
#define DATABASE_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlRelation>
#include <QSqlRecord>
#include "util.h"
#include <QFile>
#include <QStandardPaths>
#include "queries.h"
#include "QVariantList"

class DataBase : public QObject
{
    Q_OBJECT

private:
    QSqlDatabase db;
    static bool queryRun(QSqlQuery& query, const char* table_name);

public:
    explicit DataBase(QObject *parent = nullptr);
    bool openDataBase();
    void restoreDataBase();
    void closeDataBase();
    bool createTables();
    static bool insertIntoGenders(const QVariantList& data);
    static bool insertIntoCategories(const QString& data);
    static bool insertIntoUnits(const QVariantList& data);
    static bool insertIntoGoods(const QVariantList& data);
    static bool insertIntoPositions(const QVariantList& data);
    static bool insertIntoDressKind(const QVariantList& data);
    void insertIntoTables();
    static void deleteCategory(QString index);
    QStringList getPersonList();



signals:

public slots:
};

#endif // DATABASE_H
