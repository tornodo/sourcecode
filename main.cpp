#include "test/alltest.h"

#include <iostream>

GTEST_API_ int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
