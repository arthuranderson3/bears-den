//
// Created by Arthur Anderson on 9/17/16.
//

#include "App.h"
#include "CmdOptions.h"
#include <glog/logging.h>
#include "Version.h"
#include <iostream>

namespace bears_den {
    struct AppImpl{
        AppImpl( int argc, char* argv[]):cmdOptions( argc, argv)
        {
            google::InitGoogleLogging( argv[0] );
            google::LogToStderr();
            //google::SetStderrLogging( google::INFO );
            //google::LogSink sink;
        }
        ~AppImpl(){
            google::ShutdownGoogleLogging();
        }
        CmdOptions cmdOptions;

        Version version;
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

    Version App::get_Version() const {
        return pimpl_->version;
    }
}