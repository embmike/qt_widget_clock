#include "main_window.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wid;
    MainWindow w{&wid};

    w.show();

    return QCoreApplication::exec();
}
