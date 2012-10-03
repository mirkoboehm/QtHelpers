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
};

SafeConnectTests::SafeConnectTests()
{
}

void SafeConnectTests::testSafeConnect()
{
    setObjectName(QObject::tr("qunittest object"));
    try {
        // this should succeed:
        QTimer timer;
        QtHelpers::safe_connect(&timer, SIGNAL(timeout()), this, SLOT(safeConnectTestSlot()));
    } catch (QtHelpers::FailedConnectError& e) {
        QFAIL(e.what());
        qDebug() << e.what();
    }
    try {
        // this should fail:
        QTimer timer;
        timer.setObjectName(QObject::tr("Test Timer"));
        QtHelpers::safe_connect(&timer, SIGNAL(timeout()), this, SLOT(safeConnectTestSlotThatDoesNotExist()));
        QFAIL("We should not get here, an exception was expected!");
    } catch (QtHelpers::FailedConnectError& e) {
        qDebug() << e.what();
    }
}

QTEST_APPLESS_MAIN(SafeConnectTests)

#include "tst_SafeConnectTests.moc"
