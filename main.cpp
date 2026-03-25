#include "main_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setOrganizationName(QString("Mike Netz Engineering"));
    a.setApplicationName(QString("LCD Qt Widget Clock"));

    MainWindow w{};
    w.show();

    return QCoreApplication::exec();
}
