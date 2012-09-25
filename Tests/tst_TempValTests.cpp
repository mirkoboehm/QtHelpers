#include <QString>
#include <QtTest>

class TempValTests : public QObject
{
    Q_OBJECT
    
public:
    TempValTests();
    
private Q_SLOTS:
    void testCase1();
};

TempValTests::TempValTests()
{
}

void TempValTests::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TempValTests)

#include "tst_TempValTests.moc"
