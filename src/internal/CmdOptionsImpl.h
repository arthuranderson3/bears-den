//
// Created by Arthur Anderson on 9/18/16.
//

#ifndef BEARS_DEN_CMDOPTIONSIMPL_H
#define BEARS_DEN_CMDOPTIONSIMPL_H

#include <boost/program_options.hpp>
#include <string>

namespace bears_den{
    namespace internal{

        namespace po = boost::program_options;

        struct CmdOptionsImpl {

            CmdOptionsImpl():
                    generic(        "generic:"),
                    configuration(  "configuration:"),
                    hidden(         "hidden:"),
                    cmdline(        "CLI options:"),
                    vm(),
                    log_level( "info" )
            {}
            po::options_description generic;
            po::options_description configuration;
            po::options_description hidden;
            po::options_description cmdline;
            po::variables_map vm;

            std::string log_level;
        };

    }
}

#endif //BEARS_DEN_CMDOPTIONSIMPL_H
