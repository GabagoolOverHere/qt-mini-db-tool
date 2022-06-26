#ifndef TESTDB_QUERYDIALOG_H
#define TESTDB_QUERYDIALOG_H


#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include "codeeditor.h"
#include "../window.h"

QT_BEGIN_NAMESPACE
class QLabel;

class MainWindow;

class CodeEditor;

class QPushButton;

class QVBoxLayout;

QT_END_NAMESPACE

class QueryDialog : public QDialog {
Q_OBJECT

public:
    explicit QueryDialog(MainWindow *parent = nullptr);

    CodeEditor *query_input;

private slots:

    void closeDialog();

private:
    QLabel *label;
    QPushButton *validate_button;
    QPushButton *cancel_button;
    QVBoxLayout *layout;
};


#endif //TESTDB_QUERYDIALOG_H
