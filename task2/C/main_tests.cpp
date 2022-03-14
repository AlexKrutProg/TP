#include "A/index.h"
#include "B/lib.h"
#include <gtest/gtest.h>

TEST(ATest, test1) {
    ASSERT_EQ(arr[0], 1);
    ASSERT_EQ(arr[4], 5);
}

TEST(BTest, test2) {
    ASSERT_EQ(create_love("Sonechka"), "Sonechka, I love you!");
}

