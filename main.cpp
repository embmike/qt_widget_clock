#include "main_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wid; // For to show context menu on right click on the clock
    MainWindow w{&wid};

    w.show();

    return QCoreApplication::exec();
}
