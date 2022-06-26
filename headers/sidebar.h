#ifndef TESTDB_SIDEBAR_H
#define TESTDB_SIDEBAR_H


#include <QWidget>
#include <QVBoxLayout>
#include "window.h"

QT_BEGIN_NAMESPACE
class QPushButton;

class MainWindow;

class QVBoxLayout;

QT_END_NAMESPACE

class Sidebar : public QWidget {

Q_OBJECT
public:
    explicit Sidebar(MainWindow *parent = nullptr);

private:
    QVBoxLayout *layout;
    QPushButton *clients_button;
    QPushButton *projects_button;
    QPushButton *databases_button;
    QPushButton *fpts_button;
    QPushButton *envs_button;
    QDialogButtonBox *button_box;
};


#endif
