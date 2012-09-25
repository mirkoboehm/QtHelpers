#include <QString>
#include <QtTest>

#include "QtHelpers/TempVal.h"

class TempValTests : public QObject
{
    Q_OBJECT
    
public:
    TempValTests();
    
private Q_SLOTS:
    void testTemporaryAssignment();
};

TempValTests::TempValTests()
{
}

void TempValTests::testTemporaryAssignment()
{
    int a = 3;
    {
        QtHelpers::TemporaryValue<int> tempA(a, 4);
        QCOMPARE(a, 4);
        QCOMPARE(tempA.oldValue(), 3);
    }
    QCOMPARE(a, 3);
}

QTEST_APPLESS_MAIN(TempValTests)

#include "tst_TempValTests.moc"
