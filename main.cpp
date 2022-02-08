/*
*   Author: CodeWuRen
*/

#include "mainwindow.h"
#include "arg.h"

#include <iostream>
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) usage();
        else FN = argv[argc - 1];
    }
    MainWindow window;
    window.show();
    return a.exec();
}
