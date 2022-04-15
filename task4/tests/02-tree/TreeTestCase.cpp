
#include "TreeTestCase.h"
#include "Tree.h"

TEST(TreeTestCase, NotExist) {
    ASSERT_THROW(GetTree("longLongAnyWay", true), std::invalid_argument);
}

TEST(TreeTestCase, OperatorEq) {
    ASSERT_EQ(GetTree(".", false), GetTree(".", false));
}

TEST(TreeTestCase, NotDirectory) {
    ASSERT_THROW(GetTree("./Tree.cpp", false), std::invalid_argument);
}


TEST(TreeTestCase, Filter) {
    ASSERT_NO_FATAL_FAILURE(FilterEmptyNodes(GetTree(".", false), "."));
}



