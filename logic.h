#ifndef LOGIC_H
#define LOGIC_H
#include <QString>
#include <QWidget>
#include <QRegExp>

const QString password = "12345";

bool checkPassword(QString _password);
QString calcCost(QString value);

template<class T>
bool fieldsIsFill(QWidget* form)
{
    QList<T*> fields = form->findChildren<T*>();
    for(auto i : fields)
    {
        if(i->text().isEmpty())
            return false;
    }
    return true;
}


#endif // LOGIC_H
