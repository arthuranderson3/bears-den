#include <iostream>
#include "src/App.h"
#include "src/Version.h"
#include <string>

namespace bd = bears_den;
int main( int argc, char* argv[] ) {

    bd::App app( argc, argv);
    app.Run();

    return 0;
}