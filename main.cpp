#include "cmainwindow.h"
#include <QApplication>
#include <cappcontroller.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CMainWindow w;
    CAppController controller;

    controller.ConnectToGui(&w);
    w.show();

    return a.exec();
}
