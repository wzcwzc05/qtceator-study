#include <QApplication>
#include <QDialog>
#include <QLabel>
#include "TransparentWidget.h"
int main(int argc, char * argv[])
{
    QApplication a(argc, argv);
    TransparentWidget w;
    w. show();
    return a. exec();
}
