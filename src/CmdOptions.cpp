//
// Created by Arthur Anderson on 9/17/16.
//

#include "CmdOptions.h"
#include <boost/program_options.hpp>
#include <string>
#include <exception>
#include <sstream>

namespace bd {
    using namespace std;
    namespace po = boost::program_options;

    class UndefinedOptionException: public std::exception{
    public:
        UndefinedOptionException( const char* oname): option_name_(oname) {}

        virtual const char *what() const _NOEXCEPT override  {
            try {
                stringstream ss("undefined option ");
                ss << option_name_;
                return ss.str().c_str();
            }catch( ... ){
                // no nothing...
            }
            return nullptr;
        }

    private:
        std::string option_name_;
    };

    struct CmdOptions::CmdOptionsImpl {

        CmdOptionsImpl():
                generic(        "Generic:"),
                configuration(  "Configuration:"),
                hidden(         "Hidden:")
        {}
        po::options_description generic;
        po::options_description configuration;
        po::options_description hidden;
        po::options_description cmdline;
        po::variables_map vm;

        string log_level;
    };
    CmdOptions::CmdOptions(): pimpl_( new CmdOptions::CmdOptionsImpl )
    {}

    CmdOptions::~CmdOptions() {
        delete pimpl_;

    }

    void CmdOptions::_init() {

        pimpl_->generic.add_options()
                ("version,v", "print version string")
                ("help,h", "print *this* help message")
                ;

        pimpl_->configuration.add_options()
                ("log-file,lf", po::value<string>(), "Output file")
                ("log-config,lc", po::value<string>(), "The logging configuration file")
                ("log-stream,ls", po::value<string>(), "Log to an output stream: stdout default")
                ("log-level,ll", po::value<string>(&(pimpl_->log_level))->default_value("info"), "Logging level { verbose, info(default), error, debug, trace")
                ;


        pimpl_->cmdline.add(pimpl_->generic).add(pimpl_->configuration);
    }

    void CmdOptions::operator()(int argc, char **argv) {
        _init();
        po::store( po::command_line_parser( argc, argv )
                           .options(pimpl_->cmdline)
                           .run(), pimpl_->vm);
        po::notify(pimpl_->vm);
    }

    bool CmdOptions::exists( string option) const {
        return pimpl_->vm.count( option ) > 0;
    }

    string CmdOptions::get_string( string option ) const{
        return pimpl_->vm[option].as<string>();
    }

    int CmdOptions::get_int( string option ) const {
        return pimpl_->vm[option].as<int>();
    }

}