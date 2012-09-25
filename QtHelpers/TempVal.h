#ifndef TEMPVAL_H
#define TEMPVAL_H

namespace QtHelpers {

template <typename T>
class TemporaryValue {
public:
    explicit TemporaryValue( T& v, const T& tv )
        : var_(v)
        , oldValue_( v ) {
        var_ = tv;
    }

    ~TemporaryValue() { var_ = oldValue_; }
    const T& oldValue() const { return oldValue_; }

private:
    T& var_;
    const T oldValue_;
};

}

#endif // TEMPVAL_H
