#include <iostream>
#include "src/CmdOptions.h"
#include <string>

int main( int argc, char* argv[] ) {
    bd::CmdOptions co;
    co(argc, argv);
    std::cout << co.get_string("log-level");
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}