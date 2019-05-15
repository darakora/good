#include "comboboxmodel.h"

ComboBoxModel::ComboBoxModel(QSqlQuery query, QObject *parent)
    : QAbstractListModel(parent)
{
    query.exec();
    while(query.next())
    {
        container.push_back(DataPair(query.value(0), query.value(1)));
    }
}

int ComboBoxModel::rowCount(const QModelIndex &parent) const
{
    return container.count();
}

QVariant ComboBoxModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    const DataPair &data = container.at(index.row());
    QVariant value;
    switch (role) {
    case Qt::DisplayRole:{
        value = data.second;
    }
        break;
    case Qt::UserRole:{
        value = data.first;
    }
        break;
    default:
        break;
    }
    return value;
}

