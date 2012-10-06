#include <QString>
#include <QtTest>

#include <QtHelpers/Optional.h>

class OptionalValueTests : public QObject
{
    Q_OBJECT

public:
    OptionalValueTests();

private Q_SLOTS:
    void testOptionalValue();
};

OptionalValueTests::OptionalValueTests()
{
}

void OptionalValueTests::testOptionalValue()
{
    using namespace QtHelpers;

    Optional<int> i;
    QCOMPARE(false, i.isSet());

    i = 4;
    QCOMPARE(true, i.isSet());
    QCOMPARE(4, i.value());

}

QTEST_APPLESS_MAIN(OptionalValueTests)

#include "tst_OptionalValueTests.moc"
