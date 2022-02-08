/*
*   Author: CodeWuRen
*/

#include "mainwindow.h"
#include "arg.h"

#include <iostream>
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    if (argc > 1) {
        FN = argv[argc - 1];
        std::cout << argv[argc - 1] << std::endl;
    } else {
        std::cout << "No arg" << std::endl;
    }
    MainWindow window;
    window.show();
    return a.exec();
}
