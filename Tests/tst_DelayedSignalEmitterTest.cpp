/* © 2013 Mirko Boehm <mirko@agile-workers.com>
 * This file is part of QtHelpers.
 *
 * QtHelpers is licensed under the LGPL version 3.0.
 */
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
    void testDelayedSlotInvokation();
    void testDelayedSignalEmit();
    void testClear();
    void testFailingEmit();
    void testFailingOptionalEmit();

public Q_SLOTS:
    void slotToBeCalledFromDelayedEmitTest(int arg1);
    void slotToBeConnectedToTestSignal(int arg1, int arg2);

Q_SIGNALS:
    void testSignal(int arg1, int arg2);

private:
    QMutex m_mutex;
    bool m_slotToBeCalledFromDelayedEmitTestWasCalled;
    bool m_slotToBeConnectedToTestSignalWasCalled;
};

DelayedSignalEmitterTest::DelayedSignalEmitterTest()
    : m_slotToBeCalledFromDelayedEmitTestWasCalled(false)
    , m_slotToBeConnectedToTestSignalWasCalled(false)
{
    connect(this, SIGNAL(testSignal(int,int)), SLOT(slotToBeConnectedToTestSignal(int,int)));
}

void DelayedSignalEmitterTest::testDelayedSlotInvokation()
{
    try {
        QtHelpers::DelayedSignalEmitter s;
        QMutexLocker l(&m_mutex);
        QVERIFY(!s.hasSignal());
        s.setMethod(this, "slotToBeCalledFromDelayedEmitTest", Qt::DirectConnection, Q_ARG(int, 1));
        QVERIFY(s.hasSignal());
    } catch(QtHelpers::DelayedSignalEmitter::Exception& e) {
        QFAIL(qPrintable(e.message()));
    }
    QCOMPARE(m_slotToBeCalledFromDelayedEmitTestWasCalled, true);
}

void DelayedSignalEmitterTest::testDelayedSignalEmit()
{
    try {
        QtHelpers::DelayedSignalEmitter s;
        QMutexLocker l(&m_mutex);
        QVERIFY(!s.hasSignal());
        s.setMethod(this, "testSignal", Qt::DirectConnection, Q_ARG(int, 1), Q_ARG(int, 2));
        QVERIFY(s.hasSignal());
    } catch(QtHelpers::DelayedSignalEmitter::Exception& e) {
        QFAIL(qPrintable(e.message()));
    }
    QCOMPARE(m_slotToBeCalledFromDelayedEmitTestWasCalled, true);
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

void DelayedSignalEmitterTest::slotToBeCalledFromDelayedEmitTest(int arg1)
{
    const bool canBeLocked = m_mutex.tryLock();
    m_mutex.unlock();
    QVERIFY(canBeLocked == true);
    QCOMPARE(arg1, 1);
    m_slotToBeCalledFromDelayedEmitTestWasCalled = true;
}

void DelayedSignalEmitterTest::slotToBeConnectedToTestSignal(int arg1, int arg2)
{
    const bool canBeLocked = m_mutex.tryLock();
    m_mutex.unlock();
    QVERIFY(canBeLocked == true);
    QCOMPARE(arg1, 1);
    QCOMPARE(arg2, 2);
    m_slotToBeConnectedToTestSignalWasCalled = true;
}

QTEST_MAIN(DelayedSignalEmitterTest)

#include "tst_DelayedSignalEmitterTest.moc"
