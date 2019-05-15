#include "database.h"

#include <QDebug>


bool DataBase::queryRun(QSqlQuery &query, const char *table_name)
{
    if(!query.exec())
    {
        qDebug() << "error in " << table_name;
        qDebug() << query.lastError().text();
        return false;
    }
    qDebug() << "ok";
    return true;
}

DataBase::DataBase(QObject *parent) : QObject(parent)
{
#ifdef DEBUG
    qDebug() << "DataBase";
#endif
    if(!QFile(DATABASE_PATH).exists())
           {
               restoreDataBase();
           }
           else
           {
               openDataBase();
           }
}

bool DataBase::openDataBase()
{
#ifdef DEBUG
    qDebug() << "openDataBase";
#endif

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("server");
    db.setDatabaseName(DATABASE_PATH);
    return db.open();
}

void DataBase::restoreDataBase()
{
#ifdef DEBUG
    qDebug() << "restoreDataBase";
#endif
    openDataBase();
    createTables();
    insertIntoTables();
}

void DataBase::closeDataBase()
{

}

bool DataBase::createTables()
{
     QSqlQuery query;
     return query.exec(CREATE_AGE)&&
             query.exec(CREATE_CATEGORIES) &&
             query.exec(CREATE_KINDS) &&
             query.exec(CREATE_UNITS ) &&
             query.exec(CREATE_GOODS) &&
             query.exec(CREATE_POSITIONS);
}

bool DataBase::insertIntoGenders(const QVariantList &data)
{
   QSqlQuery query;
   query.prepare("INSERT INTO Age("
                 "age"
                 ")"
                 "values(:age)");
   query.bindValue(":age", data[0].toString());
   return queryRun(query, "Age");

}

bool DataBase::insertIntoCategories(const QString &data)
{
   QSqlQuery query;
   query.prepare("INSERT INTO categories("
                 "c_name"
                 ")"
                 "values(:c_name)");
   query.bindValue(":c_name", data);
   return queryRun(query, "categories");

}

bool DataBase::insertIntoUnits(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO units("
                  "u_name"
                  ")"
                  "values(:u_name)");
    query.bindValue(":u_name", data[0].toString());
    return queryRun(query, "units");
}

bool DataBase::insertIntoGoods(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO goods("
                  "g_name,"
                  "g_kind,"
                  "g_unit,"
                  "g_price"
                  ")"
                  "values(:g_name, :g_kind, :g_unit, :g_price)");
    query.bindValue(":g_name", data[0].toString());
    query.bindValue(":g_kind", data[1].toInt());
    query.bindValue(":g_unit", data[2].toInt());
    query.bindValue(":g_price", data[3].toReal());
    return queryRun(query, "goods");
}

bool DataBase::insertIntoPositions(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO positions("
                  "p_goods,"
                  "p_count,"
                  "p_weight"
                  ")"
                  "values(:p_goods, :p_count, :p_weight)");
    query.bindValue(":p_goods", data[0].toInt());
    query.bindValue(":p_count", data[1].toInt());
    query.bindValue(":p_weight", data[2].toInt());
    return queryRun(query, "positions");
}

bool DataBase::insertIntoDressKind(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO kinds("
                  "d_name,"
                  "d_category,"
                  "d_age"
                  ")"
                  "values(:d_name, :d_category, :d_age)");
    query.bindValue(":d_name", data[0].toString());
    query.bindValue(":d_category", data[1].toInt());
    query.bindValue(":d_age", data[2].toInt());
    return queryRun(query, "kinds");
}

void DataBase::insertIntoTables()
{
    insertIntoGenders(QVariantList{QVariant("hello")});
    insertIntoDressKind(QVariantList{QVariant("cream"), QVariant(1), QVariant(1)});
    insertIntoDressKind(QVariantList{QVariant("bread"), QVariant(1), QVariant(1)});
    insertIntoDressKind(QVariantList{QVariant("meat"), QVariant(1), QVariant(1)});
    insertIntoCategories("Milk");
    insertIntoCategories("Grocery");
    insertIntoCategories("Meat");
    insertIntoUnits(QVariantList{QVariant("l")});
    insertIntoUnits(QVariantList{QVariant("ml")});
    insertIntoUnits(QVariantList{QVariant("gr")});
    insertIntoUnits(QVariantList{QVariant("kg")});
    insertIntoUnits(QVariantList{QVariant("mg")});
    insertIntoGoods(QVariantList{QVariant("chees"), QVariant(1), QVariant(2), QVariant(100)});
}

void DataBase::deleteCategory(QString index)
{
    QSqlQuery query;
    query.prepare("delete from categories where c_name = :index");
    query.bindValue(":index", index.toInt());
    query.exec();
}


