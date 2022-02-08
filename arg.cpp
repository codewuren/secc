/*
*   Author: CodeWuRen
*/
#include <iostream>
#include "arg.h"

QString FN = NULL;

void usage() {
    std::cout << "Usage:\n";
    std::cout << "\tsecc [arguments..][file]\n";
    std::cout << "You must make sure the file name is at the end of the arguments list.\n";
}
