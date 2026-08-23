#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // =========================================
    // GLOBAL NIGHT MODE
    // =========================================

    app.setStyleSheet(

        // Main background
        "QMainWindow, QWidget {"
        "background-color: #0F1115;"
        "color: #B0B3B8;"
        "}"

        // Labels
        "QLabel {"
        "color: #B0B3B8;"
        "background: transparent;"
        "}"

        // Message boxes
        "QMessageBox {"
        "background-color: #181B21;"
        "color: #B0B3B8;"
        "}"

        "QMessageBox QLabel {"
        "color: #B0B3B8;"
        "}"

        "QMessageBox QPushButton {"
        "background-color: #2563EB;"
        "color: #B0B3B8;"
        "border-radius: 7px;"
        "padding: 8px 20px;"
        "}"

        "QMessageBox QPushButton:hover {"
        "background-color: #3B82F6;"
        "}"

        // Input dialogs
        "QInputDialog {"
        "background-color: #181B21;"
        "color: #B0B3B8;"
        "}"
        );

    MainWindow window;

    window.show();

    return app.exec();
}
