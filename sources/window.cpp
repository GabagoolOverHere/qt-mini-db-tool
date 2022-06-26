#include "../headers/window.h"
#include "../headers/sidebar.h"

MainWindow::MainWindow() {
    table = new TableEditor("projects");
    sidebar = new Sidebar(this);
    dialog = new QueryDialog(this);

    tool_bar = addToolBar("Menu");
    const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
    QAction *sql_query = new QAction(newIcon, tr("&New query"), this);
    sql_query->setShortcuts(QKeySequence::New);
    sql_query->setStatusTip("Create a new SQL query");
    tool_bar->addAction(sql_query);
    connect(sql_query, &QAction::triggered, this, &MainWindow::DialogWindow);


    setCentralWidget(table);

    auto *dock = new QDockWidget(tr("Tables"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setWidget(sidebar);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
}

void MainWindow::DialogWindow() const {
    dialog->show();
}

void MainWindow::exec() {
    QSqlQueryModel *model = new QSqlQueryModel(table);
    model->setQuery(dialog->query_input->toPlainText());
    table->view->setModel(model);
}