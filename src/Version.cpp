//
// Created by Arthur Anderson on 9/17/16.
//

#include "Version.h"
#include <iostream>
#include "BearsDenConfig.h"
#include "internal/TWeakOrder.h"

namespace bears_den {

    struct Version::VersionImpl{

        VersionImpl() : majorMinor_( BearsDen_VERSION_MAJOR ,BearsDen_VERSION_MINOR ),
                        fixTweak_( BearsDen_VERSION_FIX, BearsDen_VERSION_TWEAK ) {}

        typedef internal::TWeakOrder<int16_t, int16_t > HighLow;
        HighLow majorMinor_;
        HighLow fixTweak_;

        bool operator<( const VersionImpl& other ) const {
            return (majorMinor_ < other.majorMinor_) || (majorMinor_ == other.majorMinor_ && fixTweak_ < other.fixTweak_ );
        }

        bool operator==( const VersionImpl& other ) const {
            return majorMinor_ == other.majorMinor_ && fixTweak_ == other.fixTweak_;
        }

        std::ostream& Print( std::ostream& out, char sep ) const {
            majorMinor_.Print( out, sep);
            out << sep;
            fixTweak_.Print(out, sep);
            return out;
        }

        std::wostream& Print( std::wostream& out, wchar_t sep ) const {
            majorMinor_.Print( out, sep);
            out << sep;
            fixTweak_.Print(out, sep);
            return out;
        }

    };


    Version::Version():pimpl_( new Version::VersionImpl ) {}
    Version::~Version() {
        delete pimpl_;
    }
    Version::Version( const Version& v ):pimpl_( new Version::VersionImpl( *(v.pimpl_) ) ){}
    Version::Version( Version&& v ):pimpl_( v.pimpl_ ){
        v.pimpl_ = nullptr;
    }
    Version& Version::operator=( const Version& v ){
        Version tmp( v );
        Swap( tmp );
        return *this;
    }

    Version& Version::operator=( Version&& v ){
        delete pimpl_;

        pimpl_ = v.pimpl_;

        delete v.pimpl_;
        v.pimpl_ = nullptr;

        return *this;
    }

    void Version::Swap( Version& v ){
        std::swap( pimpl_, v.pimpl_ );
    }


    std::ostream& operator<<( std::ostream& out, const Version& v ){
        char sep = '.';
        v.pimpl_->Print(out, sep);
        return out;
    }
    std::wostream& operator<<( std::wostream& out, const Version& v ){
        wchar_t sep = L'.';
        v.pimpl_->Print(out, sep);
        return out;
    }

}
