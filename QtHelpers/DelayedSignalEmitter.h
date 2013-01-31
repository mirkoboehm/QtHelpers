#ifndef DELAYEDSIGNALEMITTER_H
#define DELAYEDSIGNALEMITTER_H

#include <QGenericArgument>
#include <Qt>

class QObject;

class DelayedSignalEmitter
{
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
    Qt::ConnectionType m_type;
    QObject * m_object;
    const char* m_member;
    QGenericArgument m_val0;
    QGenericArgument m_val1;
    QGenericArgument m_val2;
    QGenericArgument m_val3;
    QGenericArgument m_val4;
    QGenericArgument m_val5;
    QGenericArgument m_val6;
    QGenericArgument m_val7;
    QGenericArgument m_val8;
    QGenericArgument m_val9;
};

#endif // DELAYEDSIGNALEMITTER_H
