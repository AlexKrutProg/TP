//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST(AddTestCase, Math) {
    ASSERT_LT(Add(5, 4), Add(5, 5));
}

