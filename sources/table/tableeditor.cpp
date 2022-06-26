#include <QtWidgets>
#include <QtSql>

#include "../../headers/table/tableeditor.h"

TableEditor::TableEditor(const QString &tableName, QWidget *parent) : QWidget(parent) {
    model = new QSqlRelationalTableModel(this);
    model->setTable(tableName);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->setRelation(4, QSqlRelation("clients", "id", "company_name"));
    model->setRelation(9, QSqlRelation("project_statuses", "id", "name"));
    model->submit();

    sortProxyModel = new MySortFilterProxyModel(this);
    sortProxyModel->setSourceModel(model);


    view = new QTableView;
    view->setModel(sortProxyModel);
    view->setSortingEnabled(true);
    view->resizeColumnsToContents();
    view->setAlternatingRowColors(true);

    filterPatternLineEdit = new QLineEdit;
    filterPatternLineEdit->setClearButtonEnabled(true);
    filterPatternLabel = new QLabel(tr("&Search by name:"));
    filterPatternLabel->setBuddy(filterPatternLineEdit);

    submitButton = new QPushButton(tr("Submit"));
    submitButton->setDefault(true);
    revertButton = new QPushButton(tr("&Revert"));
    quitButton = new QPushButton(tr("Quit"));

    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);


    connect(filterPatternLineEdit, &QLineEdit::textChanged, this, &TableEditor::textFilterChanged);
    connect(submitButton, &QPushButton::clicked, this, &TableEditor::submit);
    connect(revertButton, &QPushButton::clicked, model, &QSqlRelationalTableModel::revertAll);
    connect(quitButton, &QPushButton::clicked, this, &TableEditor::close);

    auto *tableLayout = new QHBoxLayout;
    tableLayout->addWidget(view);
    tableLayout->addWidget(buttonBox);

    auto *filtersLayout = new QVBoxLayout;
    filtersLayout->addWidget(filterPatternLabel);
    filtersLayout->addWidget(filterPatternLineEdit);

    auto *dataLayout = new QVBoxLayout;
    dataLayout->addLayout(tableLayout);
    dataLayout->addLayout(filtersLayout);

    setLayout(dataLayout);

    setWindowTitle(tr("Cached Table"));

    submit();
}

void TableEditor::submit() {
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("Cached Table"),
                             tr("The database reported an error: %1").arg(model->lastError().text()));
    }
}

void TableEditor::textFilterChanged() {
    QString search = filterPatternLineEdit->text();
    QRegularExpression regex(search, QRegularExpression::CaseInsensitiveOption);

    sortProxyModel->setFilterRegularExpression(regex);
}

void TableEditor::clientsButtonClicked() {
    model->setTable("clients");
    submit();
}

void TableEditor::projectsButtonClicked() {
    model->setTable("projects");
    submit();
}

void TableEditor::databasesButtonClicked() {
    model->setTable("databases");
    submit();
}

void TableEditor::ftpsButtonClicked() {
    model->setTable("ftps");
    submit();
}

void TableEditor::environmentsButtonClicked() {
    model->setTable("environments");
    submit();
}
