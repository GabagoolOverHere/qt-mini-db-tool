#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QToolBar>
#include <QSqlQueryModel>
#include <QDockWidget>

#include "table/tableeditor.h"
#include "menu/querydialog.h"

QT_BEGIN_NAMESPACE
class QWidget;

class TableEditor;

class QueryDialog;

class QToolBar;
class QTableView;
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow();

private slots:

    void DialogWindow() const;

public slots:

    void exec();

public:
    TableEditor *table;
    QWidget *sidebar;
    QueryDialog *dialog;
    QToolBar *tool_bar;
};
