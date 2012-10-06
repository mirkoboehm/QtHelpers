/* © 2012 Mirko Boehm <mirko@agile-workers.com>
 * This file is part of QtHelpers.
 *
 * QtHelpers is licensed under the LGPL version 3.0.
 */

#ifndef OPTIONAL_H
#define OPTIONAL_H

#include <QtGlobal>

namespace QtHelpers {

template <typename T>
class Optional {
public:
    explicit Optional() : set_( false ) {}

    Optional( const T& v_ ) : set_( true ), v_( v_ ) {}

    Optional& operator=( const T& v2 ) {
        v_ = v2;
        set_ = true;
        return *this;
    }

    bool operator==( const Optional<T>& other ) const {
        return (set_ == false && other.set_ == false) || (set_ && other.set_ && v_ == other.v_);
    }

    bool operator!=( const Optional<T>& other ) const {
        return !(*this == other);
    }

    bool operator<( const Optional<T>& other ) const {
        if ( set_ != other.set_ )
            return !set_;
        else
            return v_ < other.v_;
    }

    bool operator>( const Optional<T>& other ) const {
        if ( set_ != other.set_ )
            return set_;
        else
            return v_ > other.v_;
    }

    bool operator>=( const Optional<T>& other ) const {
        if ( set_ != other.set_ )
            return set_;
        else
            return v_ >= other.v_;
    }

    bool isSet() const {
        return set_;
    }

    void unSet() {
        set_ = false;
        v_ = T();
    }

    const T& value() const {
        Q_ASSERT( set_ );
        return v_;
    }

    const T& value( const T& defaultValue ) const {
        if ( set_ )
            return v_;
        else
            return defaultValue;
    }

private:
    bool set_ : 1;
    T v_;
};

}

#endif // OPTIONAL_H
