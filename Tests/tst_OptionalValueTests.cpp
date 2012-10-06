/* © 2012 Mirko Boehm <mirko@agile-workers.com>
 * This file is part of QtHelpers.
 *
 * QtHelpers is licensed under the LGPL version 3.0.
 */

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
    void testUnsetValue();
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

void OptionalValueTests::testUnsetValue()
{
    using namespace QtHelpers;

    Optional<int> i = 4;
    QCOMPARE(true, i.isSet());
    QCOMPARE(4, i.value());
    i.unSet();
    QCOMPARE(false, i.isSet());
}

QTEST_APPLESS_MAIN(OptionalValueTests)

#include "tst_OptionalValueTests.moc"
