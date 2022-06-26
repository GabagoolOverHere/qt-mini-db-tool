#include <QPushButton>
#include "../headers/sidebar.h"

Sidebar::Sidebar(MainWindow *window) : QWidget(window) {
    clients_button = new QPushButton(tr("Clients"));
    projects_button = new QPushButton(tr("Projects"));
    databases_button = new QPushButton(tr("Databases"));
    fpts_button = new QPushButton(tr("Ftps"));
    envs_button = new QPushButton(tr("Environments"));

    button_box = new QDialogButtonBox(Qt::Vertical);
    button_box->addButton(clients_button, QDialogButtonBox::ActionRole);
    button_box->addButton(projects_button, QDialogButtonBox::ActionRole);
    button_box->addButton(databases_button, QDialogButtonBox::ActionRole);
    button_box->addButton(fpts_button, QDialogButtonBox::ActionRole);
    button_box->addButton(envs_button, QDialogButtonBox::ActionRole);

    connect(clients_button, &QPushButton::clicked, window->table, &TableEditor::clientsButtonClicked);
    connect(projects_button, &QPushButton::clicked, window->table, &TableEditor::projectsButtonClicked);
    connect(databases_button, &QPushButton::clicked, window->table, &TableEditor::databasesButtonClicked);
    connect(fpts_button, &QPushButton::clicked, window->table, &TableEditor::ftpsButtonClicked);
    connect(envs_button, &QPushButton::clicked, window->table, &TableEditor::environmentsButtonClicked);

    layout = new QVBoxLayout(this);
    layout->addWidget(button_box);

    setLayout(layout);
}
