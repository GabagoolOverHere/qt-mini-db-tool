#pragma once

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>

static bool createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("your database");
    db.setHostName("localhost");
    db.setUserName("your user");
    db.setPassword("your super safe password");
    db.setPort(3306);
    if (!db.open()) {
        QMessageBox::critical(
            nullptr,
            QObject::tr("Cannot open database"),
            QObject::tr(
                "Unable to establish a database connection.\n"
                "This example needs mariadb support. Please read "
                "the Qt SQL driver documentation for information how "
                "to build it.\n\n"
                "Click Cancel to exit."
            ),
            QMessageBox::Cancel);

        return false;
    }

    return true;
}
