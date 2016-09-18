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
        int get_Major() const;
        int get_Minor() const;
        int get_Fix() const;
        int get_Tweak() const;

        std::ostream& Print( std::ostream& out ) const;
        std::wostream& Print( std::wostream& out ) const;

    private:
        struct VersionImpl;
        VersionImpl* pimpl_;
    };

    std::ostream& operator<<( std::ostream& out, const Version& v );
    std::wostream& operator<<( std::wostream& out, const Version& v );
}
#endif //BEARS_DEN_VERSION_H
