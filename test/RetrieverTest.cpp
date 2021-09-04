#include "gtest/gtest.h"
#include <utility>

class RetrieverTest : public ::testing::Test{
    protected:
        int a = 10;
};

TEST_F(RetrieverTest, test){
    EXPECT_EQ(a, 10);
};