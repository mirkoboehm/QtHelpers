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
    void testClear();
    void testFailingEmit();
    void testFailingOptionalEmit();

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
        QtHelpers::DelayedSignalEmitter s;
        QMutexLocker l(&m_mutex);
        QVERIFY(!s.hasSignal());
        s.setMethod(this, "slotTobeCalledFromDelayedEmitTest", Qt::DirectConnection, Q_ARG(int, 1));
        QVERIFY(s.hasSignal());
    }
    QCOMPARE(m_slotTobeCalledFromDelayedEmitTestWasCalled, true);
}

void DelayedSignalEmitterTest::testClear()
{
    QtHelpers::DelayedSignalEmitter s;
    QVERIFY(!s.hasSignal());
    s.setMethod(this, "slotTobeCalledFromDelayedEmitTest", Qt::DirectConnection, Q_ARG(int, 1));
    QVERIFY(s.hasSignal());
    s.clear();
    QVERIFY(!s.hasSignal());
}

void DelayedSignalEmitterTest::testFailingEmit()
{
    try {
        {
            QtHelpers::DelayedSignalEmitter s;
            s.setMethod(this, "no_such_method");
        }
        QFAIL("An exception should have occured before getting here");
    } catch(QtHelpers::DelayedSignalEmitter::Exception& e) {
        qDebug() <<"(Expected)"<< qPrintable(e.message());
    }
}

void DelayedSignalEmitterTest::testFailingOptionalEmit()
{
    try {
        QtHelpers::DelayedSignalEmitter s(false); //mustSucceed is false
        s.setMethod(this, "no_such_method");
    } catch(QtHelpers::DelayedSignalEmitter::Exception& e) {
        QFAIL("No exception should expected in this case");
    }
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
