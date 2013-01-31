#ifndef QTHELPERS_QTEXCEPTION_H
#define QTHELPERS_QTEXCEPTION_H

#include <stdexcept>

#include <QString>

namespace QtHelpers {

class QtExceptionPrivate;

class QtException : public std::runtime_error
{
    Q_DECLARE_PRIVATE(QtException)

public:
    explicit QtException( const QString& message );
    ~QtException() throw();
    QString message() const;

private:
    QtExceptionPrivate* const d_ptr;
};

}

#endif // QTHELPERS_QTEXCEPTION_H
