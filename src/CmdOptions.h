//
// Created by Arthur Anderson on 9/17/16.
//

#ifndef BEARS_DEN_CMDOPTIONS_H
#define BEARS_DEN_CMDOPTIONS_H

#include <iosfwd>


namespace bears_den {

    class UndefinedOptionException;
    namespace internal{ struct CmdOptionsImpl; }

    class CmdOptions {
    public:
        CmdOptions( int argc, char* argv[] );
        ~CmdOptions();
        bool exists( std::string option ) const;
        std::string get_string( std::string option ) const;
        int get_int( std::string option ) const;

        std::ostream& PrintHelp( std::ostream& out ) const;
    private:
        void _init(int argc, char* argv[]);
        internal::CmdOptionsImpl* pimpl_;
    };

}

#endif //BEARS_DEN_CMDOPTIONS_H
