
#include "TreeTestCase.h"
#include "Tree.h"
#include <filesystem>


TEST(TreeTestCase, NotExist) {
    ASSERT_THROW(GetTree("longLongAnyWay", true), std::invalid_argument);
}

TEST(TreeTestCase, OperatorEq) {
    ASSERT_EQ(GetTree(".", true), GetTree(".", true));
}

TEST(TreeTestCase, NotDirectory) {
    ASSERT_THROW(GetTree("./Tree.cpp", false), std::invalid_argument);
}

TEST(TreeTestCase, NotDirectorySec) {
    namespace fs = std::filesystem;
    using std::filesystem::is_directory;
    for (const auto & entry : fs::directory_iterator(".")) {
        if (!is_directory(entry.path())) {
            ASSERT_THROW(GetTree(entry.path(), false), std::invalid_argument);
            break;
        }
    }
}

TEST(TreeTestCase, Last) {
    ASSERT_NO_FATAL_FAILURE(FilterEmptyNodes(GetTree(".", false), "."));
}








