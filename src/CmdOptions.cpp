//
// Created by Arthur Anderson on 9/17/16.
//

#include "CmdOptions.h"
#include "internal/CmdOptionsImpl.h"

#include <exception>
#include <sstream>

namespace bears_den {

    using namespace std;
    namespace intern = bears_den::internal;
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

    CmdOptions::CmdOptions( int argc, char* argv[] ): pimpl_( new intern::CmdOptionsImpl )
    {
        _init( argc, argv );
    }

    CmdOptions::~CmdOptions() {
        delete pimpl_;

    }

    void CmdOptions::_init(int argc, char **argv) {

        pimpl_->generic.add_options()
                ("version,v", "print version string")
                ("help,h", "print *this* help message")
                ;

        pimpl_->configuration.add_options()
                ("log-level",
                 po::value<string>(&(pimpl_->log_level))->default_value("info"),
                 "Logging level { verbose, info, error, debug, trace" )
                ;


        pimpl_->cmdline.add(pimpl_->generic).add(pimpl_->configuration);

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

    std::ostream& CmdOptions::PrintHelp( std::ostream& out ) const
    {
        out << pimpl_->cmdline << std::endl;
        return out;
    }

}