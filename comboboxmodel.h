#ifndef COMBOBOXMODEL_H
#define COMBOBOXMODEL_H

#include <QAbstractListModel>
#include <QSqlQuery>

class ComboBoxModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit ComboBoxModel(QSqlQuery query, QObject *parent = nullptr);
    using DataPair = QPair<QVariant,QVariant>;
    QVector<DataPair> container;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

private:
    QSqlQuery m_query;
};

#endif // COMBOBOXMODEL_H
