//
// Created by Arthur Anderson on 9/17/16.
//

#ifndef BEARS_DEN_VERSION_H
#define BEARS_DEN_VERSION_H

#include <iosfwd>

namespace bears_den {

    class Version {

    public:
        Version();
       ~Version();
        Version( const Version& v );
        Version( Version&& v );
        Version& operator=( const Version& v );
        Version& operator=( Version&& v );


        void Swap( Version& v );

    private:
        struct VersionImpl;
        VersionImpl* pimpl_;

        friend std::ostream& operator<<( std::ostream& , const Version& );
        friend std::wostream& operator<<( std::wostream& , const Version& );
    };

    std::ostream & operator<<( std::ostream& out, const Version& v );
    std::wostream & operator<<( std::wostream& out, const Version& v );
}
#endif //BEARS_DEN_VERSION_H
