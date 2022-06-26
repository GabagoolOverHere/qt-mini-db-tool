#include <QApplication>

#include "headers/connection.h"
#include "headers/window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    if (!createConnection())
        return 1;

    MainWindow mainWindow;
    mainWindow.setWindowTitle("Database");
    mainWindow.resize(1500, 800);
    mainWindow.show();

    return app.exec();
}
