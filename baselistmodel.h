#ifndef BASELISTMODEL_H
#define BASELISTMODEL_H

#include <QAbstractListModel>
#include <QSqlQuery>

class BaseListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit BaseListModel(QSqlQuery query, QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void select();

private:
    QSqlQuery m_query;
    using DataPair = QPair<QVariant, QVariant>;
    QList<DataPair> container;
};

#endif // BASELISTMODEL_H
