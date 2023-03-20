// Dominic Gasperini
// Passphrase Generator

// includes
#include "MainWindow.h"
#include <QApplication>

/**
 * @brief qMain
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    // create application
    QApplication a(argc, argv);
    MainWindow w;

    // show application
    w.show();
    return a.exec();
}
