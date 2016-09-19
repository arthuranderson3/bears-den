//
// Created by Arthur Anderson on 9/17/16.
//

#ifndef BEARS_DEN_APP_H
#define BEARS_DEN_APP_H

namespace bears_den {

    class App {

    public:
        App(int argc, char* argv[] );
        ~App();
        App( const App& ) = delete;
        App& operator=( const App& ) = delete;
        App( const App&& ) = delete;

        App();

        App& operator=( const App&& ) = delete;

        void Run();

    private:
        struct AppImpl;
        AppImpl* pimpl_;
    };

}

#endif //BEARS_DEN_APP_H
