#include <iostream>

#include "read.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    Read* dialog = new Read;
    dialog->show();
    return app.exec();
}