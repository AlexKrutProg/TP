#include "AddTestCase.h"
#include "Functions.h"

TEST(AddTestCase, Math) {
    ASSERT_LT(Add(5, 4), Add(5, 5));
}

