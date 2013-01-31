#include <QMetaObject>
#include <QtDebug>

#include "DelayedSignalEmitter.h"

namespace QtHelpers {

class DelayedSignalEmitterPrivate {
public:
    DelayedSignalEmitterPrivate(bool mustSucceed_)
        : mustSucceed(mustSucceed_)
        , type(Qt::AutoConnection)
        , object(0)
        , member(0)
    {}
    bool mustSucceed;
    Qt::ConnectionType type;
    QObject * object;
    const char* member;
    QGenericArgument val0;
    QGenericArgument val1;
    QGenericArgument val2;
    QGenericArgument val3;
    QGenericArgument val4;
    QGenericArgument val5;
    QGenericArgument val6;
    QGenericArgument val7;
    QGenericArgument val8;
    QGenericArgument val9;
};

DelayedSignalEmitter::Exception::Exception(const QString &message)
    : QtException(message)
{
}

DelayedSignalEmitter::DelayedSignalEmitter(bool mustSucceed)
    : d_ptr(new DelayedSignalEmitterPrivate(mustSucceed))
{
}

DelayedSignalEmitter::~DelayedSignalEmitter()
{
    Q_D(DelayedSignalEmitter);
    if (hasSignal()) {
        if (!QMetaObject::invokeMethod(d->object, d->member, d->type,
                                       d->val0,d-> val1,d-> val2, d->val3, d->val4,
                                       d->val5, d->val6, d->val7, d->val8, d->val9)) {
            if (d->mustSucceed) {
                const QString msg = QObject::tr("Error invoking meta method \"%1\" on object 0x%2 of class %3")
                        .arg(d->member)
                        .arg((qulonglong)d->object, 8, 16)
                        .arg(d->object->metaObject()->className());
                throw Exception(msg);
            }
        }
    }
    delete d_ptr;
}

void DelayedSignalEmitter::setMethod(QObject *object, const char *member,
                                     Qt::ConnectionType type,
                                     QGenericArgument val0, QGenericArgument val1,
                                     QGenericArgument val2, QGenericArgument val3, QGenericArgument val4,
                                     QGenericArgument val5, QGenericArgument val6, QGenericArgument val7,
                                     QGenericArgument val8, QGenericArgument val9)
{
    Q_D(DelayedSignalEmitter);
    d->object = object;
    d->member = member;
    d->type = type;
    d->val0 = val0;
    d->val1 = val1;
    d->val2 = val2;
    d->val3 = val3;
    d->val4 = val4;
    d->val5 = val5;
    d->val6 = val6;
    d->val7 = val7;
    d->val8 = val8;
    d->val9 = val9;
}

bool DelayedSignalEmitter::hasSignal() const
{
    Q_D(const DelayedSignalEmitter);
    return d->object!=0 && d->member != 0;
}

void DelayedSignalEmitter::clear()
{
    Q_D(DelayedSignalEmitter);
    d->object = 0;
    d->member = 0;
    Q_ASSERT(!hasSignal());
}

}
