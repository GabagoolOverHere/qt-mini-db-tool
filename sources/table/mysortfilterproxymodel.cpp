#include "../../headers/table/mysortfilterproxymodel.h"

MySortFilterProxyModel::MySortFilterProxyModel(QObject *parent) : QSortFilterProxyModel(parent) {}

bool MySortFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const {
    QModelIndex index1 = sourceModel()->index(sourceRow, 2, sourceParent);
    QModelIndex index2 = sourceModel()->index(sourceRow, 4, sourceParent);

    return (sourceModel()->data(index1).toString().contains(filterRegularExpression()) ||
            sourceModel()->data(index2).toString().contains(filterRegularExpression()));
}


