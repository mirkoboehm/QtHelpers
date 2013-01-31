#include <QMetaObject>
#include <QtDebug>

#include "DelayedSignalEmitter.h"

class DelayedSignalEmitterPrivate {
public:
    DelayedSignalEmitterPrivate()
        : type(Qt::AutoConnection)
        , object(0)
        , member(0)
    {}

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

DelayedSignalEmitter::DelayedSignalEmitter()
    : d_ptr(new DelayedSignalEmitterPrivate())
{
}

DelayedSignalEmitter::~DelayedSignalEmitter()
{
    Q_D(DelayedSignalEmitter);
    if (d->object!=0 && d->member != 0) {
        if (!QMetaObject::invokeMethod(d->object, d->member, d->type,
                                       d->val0,d-> val1,d-> val2, d->val3, d->val4,
                                       d->val5, d->val6, d->val7, d->val8, d->val9)) {
            //FIXME exception?
            qDebug() << Q_FUNC_INFO << "error invoking method" << d->member << "on object" << d->object;
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
