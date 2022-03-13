#include "A/index.h"
#include "B/lib.h"

TEST(arr, test1) {
    ASSERT_EQ(arr[0], 1)
    ASSERT_EQ(arr[4], 5)
}

TEST(create_love, test2) {
    ASSERT_EQ(create_love("Sonechka"), "Sonechka, I love you!")
