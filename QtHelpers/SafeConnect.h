#ifndef SAFECONNECT_H
#define SAFECONNECT_H

#include <stdexcept>

#include <QObject>

namespace QtHelpers {

class FailedSafeConnectError : public std::runtime_error {
public:
    explicit FailedSafeConnectError(const std::string& arg)
        : std::runtime_error(arg)
    {}
};

class FailedConnectError : public FailedSafeConnectError {
public:
    explicit FailedConnectError(const std::string& arg)
        : FailedSafeConnectError(arg)
    {}
};

class FailedDisconnectError : public FailedSafeConnectError {
public:
    explicit FailedDisconnectError(const std::string& arg)
        : FailedSafeConnectError(arg)
    {}
};

namespace {

QString qobject_description(const QObject* object) {
    const QString address(object == 0
                          ? QObject::tr("(null)")
                          : QObject::tr("%1@%2")
                            .arg(object->metaObject()->className())
                            .arg(QString::number(ulong(object), 16).toUpper()));
    if (object && !object->objectName().isEmpty()) {
        const QString addressWithName = QObject::tr("\"%1\"[%2]").arg(object->objectName()).arg(address);
        return addressWithName;
    } else {
        return address;

    }
}

QString method_description(const char* method) {
    const QString text(method == 0 ? QObject::tr("(null") : QString(method));
    return text;
}

QString connection_description(const QObject* sender, const char* signal,
                               const QObject* receiver, const char* method)
{
    const QString senderString = qobject_description(sender);
    const QString signalString = method_description(signal);
    const QString receiverString = qobject_description(receiver);
    const QString methodString = method_description(method);
    const QString signalSlotSignature = QObject::tr("%1.%2->%3.%4")
            .arg(senderString).arg(signalString)
            .arg(receiverString).arg(methodString);
    return signalSlotSignature;
}

std::string connect_error_description(const QObject* sender, const char* signal,
                                      const QObject* receiver, const char* method,
                                      Qt::ConnectionType type)
{

    const QString desc = QObject::tr("Error connecting %1")
            .arg(connection_description(sender, signal, receiver, method));
    return desc.toStdString();
}

std::string disconnect_error_description(const QObject* sender, const char* signal,
                                         const QObject* receiver, const char* method)
{
    const QString desc = QObject::tr("Error disconnecting: %1").arg(connection_description(sender, signal, receiver, method));
    return desc.toStdString();
}

}

inline void safe_connect(const QObject *sender, const char *signal,
                         const QObject *receiver, const char *method,
                         Qt::ConnectionType type = Qt::AutoConnection) {
    if (!QObject::connect(sender, signal, receiver, method, type) ) {
        throw FailedConnectError(connect_error_description(sender, signal, receiver, method, type));
    }
}

inline void safe_connect(const QObject *sender, const QMetaMethod &signal,
                         const QObject *receiver, const QMetaMethod &method,
                         Qt::ConnectionType type = Qt::AutoConnection) {
    if (!QObject::connect(sender, signal, receiver, method, type) ) {
        //TODO: implement
        // throw FailedConnectError(connect_error_description(sender, signal, receiver, method, type));
    }
}


inline void disconnect(const QObject *sender, const char *signal,
                       const QObject *receiver, const char *member) {
    if (!QObject::disconnect(sender, signal, receiver, member) ) {
        throw FailedDisconnectError(disconnect_error_description(sender, signal, receiver, member));
    }
}

inline void disconnect(const QObject *sender, const QMetaMethod &signal,
                       const QObject *receiver, const QMetaMethod &member) {
    if (!QObject::disconnect(sender, signal, receiver, member) ) {
        //TODO: implement
        // throw FailedDisconnectError(connect_error_description(sender, signal, receiver, member));
    }
}

}

#endif // SAFECONNECT_H
