#include <QString>
#include <QtTest>

#include <QtHelpers/SafeConnect.h>

class SafeConnectTests : public QObject
{
    Q_OBJECT
    
public:
    SafeConnectTests();
    
public Q_SLOTS:
    void safeConnectTestSlot() {}
    void safeDisconnectTestSlot() {}
private Q_SLOTS:
    void testSafeConnect();
    void testSafeDisconnect();
};

SafeConnectTests::SafeConnectTests()
{
    setObjectName(QObject::tr("qunittest object"));
}

void SafeConnectTests::testSafeConnect()
{
    try {
        // this should succeed:
        QTimer timer;
        QtHelpers::safe_connect(&timer, SIGNAL(timeout()), this, SLOT(safeConnectTestSlot()));
    } catch (QtHelpers::FailedConnectError& e) {
        QFAIL(e.what());
    }
    try {
        // this should fail:
        QTimer timer;
        timer.setObjectName(QObject::tr("Test Timer"));
        QtHelpers::safe_connect(&timer, SIGNAL(timeout()), this, SLOT(safeConnectTestSlotThatDoesNotExist()));
        QFAIL("We should not get here, an exception was expected!");
    } catch (QtHelpers::FailedConnectError&) {
        // all good
    }
}

void SafeConnectTests::testSafeDisconnect()
{
    try {
        QTimer timer;
        QtHelpers::safe_connect(&timer, SIGNAL(timeout()), this, SLOT(safeConnectTestSlot()));
        // this should succeed:
        QtHelpers::safe_disconnect(&timer, SIGNAL(timeout()), this, SLOT(safeConnectTestSlot()));
    } catch (QtHelpers::FailedDisconnectError& e) {
        QFAIL(e.what());
    }
    try {
        QTimer timer;
        // this should fail, nothing is connected:
        QtHelpers::safe_disconnect(&timer, SIGNAL(timeout()), this, SLOT(safeConnectTestSlot()));
        QFAIL("We should not get here, an exception was expected!");
    } catch (QtHelpers::FailedDisconnectError& e) {
        // all good
    }
}

QTEST_APPLESS_MAIN(SafeConnectTests)

#include "tst_SafeConnectTests.moc"
