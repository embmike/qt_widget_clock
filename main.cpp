/**
 * @file main.cpp
 * @brief Einstiegspunkt der Anwendung.
 */
#include "main_window.h"

#include <QApplication>

/**
 * @brief Einstiegspunkt der Anwendung.
 * @param argc Anzahl der Kommandozeilenargumente.
 * @param argv Kommandozeilenargumente.
 * @return Rückgabecode der Qt-Ereignisschleife.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName(QString("Mike Netz Engineering"));
    a.setApplicationName(QString("LCD Qt Widget Clock"));

    MainWindow w{};
    w.show();

    return QCoreApplication::exec();
}
