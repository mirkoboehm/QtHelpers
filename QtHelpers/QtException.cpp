#include "QtException.h"

namespace QtHelpers {

class QtExceptionPrivate {
public:
    QString msg;
};

QtException::QtException(const QString &message)
    : std::runtime_error( message.toStdString() )
    , d_ptr(new QtExceptionPrivate)
{
    Q_D(QtException);
    d->msg = message;
}

QtException::~QtException() throw()
{
}

QString QtException::message() const
{
    Q_D(const QtException);
    return d->msg;
}

}
