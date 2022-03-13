#include <gtest/gtest.h>
#include <iostream>
#include "main_tests.cpp"

int main(int argc, int *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
