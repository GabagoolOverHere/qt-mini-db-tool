#ifndef TABLEEDITOR_H
#define TABLEEDITOR_H

#include <QDialog>
#include <QTableView>
#include "mysortfilterproxymodel.h"

QT_BEGIN_NAMESPACE
class QDialogButtonBox;

class QPushButton;

class QSqlRelationalTableModel;

class QSortFilterProxyModel;

class QLineEdit;

class QLabel;

class QTableView;

QT_END_NAMESPACE

class TableEditor : public QWidget {
Q_OBJECT


public:
    explicit TableEditor(const QString &tableName, QWidget *parent = nullptr);
    QTableView *view;

private slots:

    void submit();

    void textFilterChanged();

public slots:

    void clientsButtonClicked();

    void projectsButtonClicked();

    void databasesButtonClicked();

    void ftpsButtonClicked();

    void environmentsButtonClicked();

private:
    QSqlRelationalTableModel *model;
    QPushButton *submitButton;
    QPushButton *revertButton;
    QPushButton *quitButton;
    QDialogButtonBox *buttonBox;
    MySortFilterProxyModel *sortProxyModel;
    QLineEdit *filterPatternLineEdit;
    QLabel *filterPatternLabel;
};

#endif