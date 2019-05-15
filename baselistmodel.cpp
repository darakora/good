#include "baselistmodel.h"

BaseListModel::BaseListModel(QSqlQuery query, QObject *parent)
    : QAbstractListModel(parent),
      m_query(query)
{
    select();
}

QVariant BaseListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int BaseListModel::rowCount(const QModelIndex &parent) const
{
    return container.count();
}

QVariant BaseListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    const DataPair &data = container.at(index.row());
    QVariant value;
    switch(role)
    {
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

void BaseListModel::select()
{
    while(m_query.next())
    {
        container.push_back(DataPair(m_query.value(0), m_query.value(1)));
    }
}
