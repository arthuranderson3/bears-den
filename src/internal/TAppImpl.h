//
// Created by Arthur Anderson on 9/18/16.
//

#ifndef BEARS_DEN_APPIMPL_H
#define BEARS_DEN_APPIMPL_H
#include <glog/logging.h>

namespace bears_den {
    namespace internal {

        template< typename CLI, typename Ver >
        struct TAppImpl {
            TAppImpl(int argc, char *argv[]) : cmdOptions(argc, argv) {
                google::InitGoogleLogging(argv[0]);
                google::LogToStderr();
                //google::SetStderrLogging( google::INFO );
                //google::LogSink sink;
            }

            ~TAppImpl() {
                google::ShutdownGoogleLogging();
            }

            CLI cmdOptions;

            Ver version;
        };
    }
}
#endif //BEARS_DEN_APPIMPL_H
