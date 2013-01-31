#include <QMetaObject>
#include <QtDebug>

#include "DelayedSignalEmitter.h"

DelayedSignalEmitter::DelayedSignalEmitter()
    : m_type(Qt::DirectConnection)
    , m_object(0)
    , m_member(0)
{
}

DelayedSignalEmitter::~DelayedSignalEmitter()
{
    if (m_object!=0 && m_member != 0) {
        if (!QMetaObject::invokeMethod(m_object, m_member, m_type,
                                       m_val0, m_val1, m_val2, m_val3, m_val4,
                                       m_val5, m_val6, m_val7, m_val8, m_val9)) {
            //FIXME exception?
            qDebug() << Q_FUNC_INFO << "error invoking method" << m_member << "on object" << m_object;
        }
    }
}

void DelayedSignalEmitter::setMethod(QObject *object, const char *member,
                                     Qt::ConnectionType type,
                                     QGenericArgument val0, QGenericArgument val1,
                                     QGenericArgument val2, QGenericArgument val3, QGenericArgument val4,
                                     QGenericArgument val5, QGenericArgument val6, QGenericArgument val7,
                                     QGenericArgument val8, QGenericArgument val9)
{
    m_object = object;
    m_member = member;
    m_type = type;
    m_val0 = val0;
    m_val1 = val1;
    m_val2 = val2;
    m_val3 = val3;
    m_val4 = val4;
    m_val5 = val5;
    m_val6 = val6;
    m_val7 = val7;
    m_val8 = val8;
    m_val9 = val9;
}
