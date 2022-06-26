#include "../../headers/menu/querydialog.h"

QueryDialog::QueryDialog(MainWindow *window) : QDialog(window) {
    label = new QLabel(tr("Your SQL Query: "));
    query_input = new CodeEditor(this);
    label->setBuddy(query_input);

    validate_button = new QPushButton(tr("Validate"));
    cancel_button = new QPushButton(tr("Cancel"));
    validate_button->setDefault(true);

    connect(cancel_button, &QPushButton::clicked, this, &QueryDialog::close);
    connect(validate_button, &QPushButton::clicked, window, &MainWindow::exec);

    layout = new QVBoxLayout();
    layout->addWidget(query_input);
    layout->addWidget(validate_button, QDialogButtonBox::ActionRole);
    layout->addWidget(cancel_button, QDialogButtonBox::RejectRole);

    setLayout(layout);
}

void QueryDialog::closeDialog() {
    close();
}
