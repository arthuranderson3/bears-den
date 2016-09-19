//
// Created by Arthur Anderson on 9/17/16.
//

#include "App.h"
#include "CmdOptions.h"
#include "Version.h"
#include "src/internal/TAppImpl.h"
#include <iostream>

namespace bears_den {

    struct App::AppImpl : public internal::TAppImpl< CmdOptions, Version > {
        AppImpl( int argc, char* argv[]): internal::TAppImpl<CmdOptions, Version>( argc, argv ){}
    };

    App::App( int argc, char** argv ): pimpl_( new AppImpl( argc, argv) ) {
        LOG(INFO) << "Created App!";
    }

    App::~App() {
        delete pimpl_;
    }

    void App::Run(){

        if( pimpl_->cmdOptions.exists("help") ){
            pimpl_->cmdOptions.PrintHelp( std::cout );
        }
        if( pimpl_->cmdOptions.exists("version") ){
            std::cout << "Version: " << pimpl_->version << std::endl;
        }
    }

}