//
// Created by Arthur Anderson on 9/17/16.
//

#ifndef BEARS_DEN_CMDOPTIONS_H
#define BEARS_DEN_CMDOPTIONS_H

#include <iosfwd>


namespace bd {

    class UndefinedOptionException;

    class CmdOptions {
    public:
        CmdOptions();
        ~CmdOptions();
        void operator()( int argc, char* argv[] );
        bool exists( std::string option ) const;
        std::string get_string( std::string option ) const;
        int get_int( std::string option ) const;

    private:
        void _init();
        struct CmdOptionsImpl;
        CmdOptionsImpl* pimpl_;
    };

}

#endif //BEARS_DEN_CMDOPTIONS_H
