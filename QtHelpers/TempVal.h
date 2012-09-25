#ifndef TEMPVAL_H
#define TEMPVAL_H

namespace QtHelpers {

template <typename T>
class TemporaryValue {
public:
    explicit TemporaryValue( T& v, const T& tv )
        : var(v)
        , oldValue( v ) {
        var = tv;
    }

    ~TemporaryValue() {
        var = oldValue;
    }

private:
    T& var;
    const T oldValue;
};

}

#endif // TEMPVAL_H
