#include <QString>
#include <QtTest>
#include <QMutex>

#include "QtHelpers/DelayedSignalEmitter.h"

class DelayedSignalEmitterTest : public QObject
{
    Q_OBJECT
    
public:
    DelayedSignalEmitterTest();
    
private Q_SLOTS:
    void testDelayedEmit();

public Q_SLOTS:
    void slotTobeCalledFromDelayedEmitTest(int arg1);

private:
    QMutex m_mutex;
    bool m_slotTobeCalledFromDelayedEmitTestWasCalled;
};

DelayedSignalEmitterTest::DelayedSignalEmitterTest()
    : m_slotTobeCalledFromDelayedEmitTestWasCalled(false)
{
}

void DelayedSignalEmitterTest::testDelayedEmit()
{
    {
        DelayedSignalEmitter s;
        QMutexLocker l(&m_mutex);
        s.setMethod(this, "slotTobeCalledFromDelayedEmitTest", Qt::DirectConnection, Q_ARG(int, 1));
    }
    QCOMPARE(m_slotTobeCalledFromDelayedEmitTestWasCalled, true);
}

void DelayedSignalEmitterTest::slotTobeCalledFromDelayedEmitTest(int arg1)
{
    const bool canBeLocked = m_mutex.tryLock();
    QVERIFY(canBeLocked == true);
    QCOMPARE(arg1, 1);
    m_slotTobeCalledFromDelayedEmitTestWasCalled = true;
    m_mutex.unlock();
}

QTEST_MAIN(DelayedSignalEmitterTest)

#include "tst_DelayedSignalEmitterTest.moc"
