#include "JsonToWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JsonToWidget w;
    w.show();
    return a.exec();
}
