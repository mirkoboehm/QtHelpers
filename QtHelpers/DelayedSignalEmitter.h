/* © 2013 Mirko Boehm <mirko@agile-workers.com>
 * This file is part of QtHelpers.
 *
 * QtHelpers is licensed under the LGPL version 3.0.
 */
#ifndef DELAYEDSIGNALEMITTER_H
#define DELAYEDSIGNALEMITTER_H

#include <stdexcept>

#include <QGenericArgument>
#include <Qt>

#include "QtException.h"

class QObject;

namespace QtHelpers {

class DelayedSignalEmitterPrivate;

class DelayedSignalEmitter
{
    Q_DECLARE_PRIVATE(DelayedSignalEmitter)

public:
    class Exception : public QtException {
    public:
        explicit Exception(const QString& message);
    };

    explicit DelayedSignalEmitter(bool mustSucceed = true);
    ~DelayedSignalEmitter();

    void setMethod(QObject * obj, const char * member,
                   Qt::ConnectionType type = Qt::DirectConnection,
                   QGenericArgument val0 = QGenericArgument(), QGenericArgument val1 = QGenericArgument(),
                   QGenericArgument val2 = QGenericArgument(), QGenericArgument val3 = QGenericArgument(),
                   QGenericArgument val4 = QGenericArgument(), QGenericArgument val5 = QGenericArgument(),
                   QGenericArgument val6 = QGenericArgument(), QGenericArgument val7 = QGenericArgument(),
                   QGenericArgument val8 = QGenericArgument(), QGenericArgument val9 = QGenericArgument());


    bool hasSignal() const;

    void clear();

private:
    DelayedSignalEmitterPrivate* const d_ptr;
};

}

#endif // DELAYEDSIGNALEMITTER_H
