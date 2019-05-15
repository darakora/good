#include "agewindow.h"
#include <QApplication>
#include "goodswindow.h"
#include "kindnew.h"
#include "unitswindow.h"
#include "authorization.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBase db;
    db.insertIntoTables();
    /*Agewindow gw;
    gw.show();
    CategoryWindow cw;
    cw.show();
    KindWindow dkw;
    dkw.show();
    GoodsWindow gow;
    gow.show();
    Unitwindow uw;
    uw.show();*/
    Authorization auw;
    auw.show();

    return a.exec();
}
