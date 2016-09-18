//
// Created by Arthur Anderson on 9/17/16.
//

#include "Version.h"
#include "BearsDenConfig.h"
#include <iostream>

namespace bears_den {

    struct Version::VersionImpl{
        VersionImpl(int major_, int minor_, int fix_, int tweak_) : major_(major_), minor_(minor_), fix_(fix_),
                                                                    tweak_(tweak_) {}

        int major_;
        int minor_;
        int fix_;
        int tweak_;
    };

    Version::Version():pimpl_( new VersionImpl( BearsDen_VERSION_MAJOR, BearsDen_VERSION_MINOR, BearsDen_VERSION_FIX, BearsDen_VERSION_TWEAK ) ) {}
    Version::~Version() {
        delete pimpl_;
    }
    Version::Version( const Version& v ):pimpl_( new VersionImpl( *(v.pimpl_) ) ){}
    Version::Version( Version&& v ):pimpl_( v.pimpl_ ){
        v.pimpl_ = nullptr;
    }
    Version& Version::operator=( const Version& v ){
        Version tmp( v );
        delete pimpl_;
        pimpl_ = tmp.pimpl_;
        tmp.pimpl_ = nullptr;
        return *this;
    }

    Version& Version::operator=( Version&& v ){
        delete pimpl_;
        pimpl_ = v.pimpl_;
        delete v.pimpl_;
        v.pimpl_ = nullptr;
    }

    int Version::get_Major() const {
        return pimpl_->major_;
    }

    int Version::get_Minor() const {
        return pimpl_->minor_;
    }

    int Version::get_Fix() const {
        return pimpl_->fix_;
    }

    int Version::get_Tweak() const {
        return pimpl_->tweak_;
    }

    std::ostream& Version::Print( std::ostream& out ) const{
        char dot = '.';
        out << pimpl_->major_ << dot << pimpl_->minor_ << dot << pimpl_->fix_ << dot << pimpl_->tweak_;
        return out;
    }

    std::wostream& Version::Print( std::wostream& out ) const{
        wchar_t dot = L'.';
        out << pimpl_->major_ << dot << pimpl_->minor_ << dot << pimpl_->fix_ << dot << pimpl_->tweak_;
        return out;
    }


    std::ostream& operator<<( std::ostream& out, const Version& v ){
        v.Print(out);
        return out;
    }
    std::wostream& operator<<( std::wostream& out, const Version& v ){
        v.Print( out );
        return out;
    }

}
