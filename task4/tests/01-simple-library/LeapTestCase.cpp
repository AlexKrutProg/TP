#include "LeapTestCase.h"

#include <Functions.h>

TEST(LeapTestCase, NoLeapYear2Month) {
    ASSERT_NE(29, GetMonthDays(2003, 2));
}

TEST(LeapTestCase, LeapYear2Month) {
    ASSERT_EQ(29, GetMonthDays(1976, 2));
}

TEST(LeapTestCase, BadMonth) {
    ASSERT_THROW(GetMonthDays(1977, 13), std::invalid_argument);
}

TEST(LeapTestCase, NoLeapYearOrdinaryMonth) {
    ASSERT_LE(GetMonthDays(1977, 11), 30);
}

TEST(LeapTestCase, OrdinaryYearOrdinaryMonth) {
    ASSERT_LE(GetMonthDays(2022, 5), 31);
}

TEST(LeapTestCase, LeapYear400) {
    ASSERT_TRUE(IsLeap(2000));
}

TEST(LeapTestCase, YearNot400) {
    ASSERT_FALSE(IsLeap(100));
}

TEST(LeapTestCase, BadYear) {
    ASSERT_THROW(IsLeap(-13), std::invalid_argument);
}



