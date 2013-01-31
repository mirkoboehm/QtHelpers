#ifndef DELAYEDSIGNALEMITTER_H
#define DELAYEDSIGNALEMITTER_H

#include <QGenericArgument>
#include <Qt>

class QObject;

namespace QtHelpers {

class DelayedSignalEmitterPrivate;

class DelayedSignalEmitter
{
    Q_DECLARE_PRIVATE(DelayedSignalEmitter)

public:
    explicit DelayedSignalEmitter();
    ~DelayedSignalEmitter();
    void setMethod(QObject * obj, const char * member,
                   Qt::ConnectionType type = Qt::DirectConnection,
                   QGenericArgument val0 = QGenericArgument(), QGenericArgument val1 = QGenericArgument(),
                   QGenericArgument val2 = QGenericArgument(), QGenericArgument val3 = QGenericArgument(),
                   QGenericArgument val4 = QGenericArgument(), QGenericArgument val5 = QGenericArgument(),
                   QGenericArgument val6 = QGenericArgument(), QGenericArgument val7 = QGenericArgument(),
                   QGenericArgument val8 = QGenericArgument(), QGenericArgument val9 = QGenericArgument());

private:
    DelayedSignalEmitterPrivate* const d_ptr;
};

}

#endif // DELAYEDSIGNALEMITTER_H
