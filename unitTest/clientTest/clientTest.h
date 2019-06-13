#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>

namespace {
    class clientTest : public testing::Test {
    protected:
        virtual void SetUp() {
        }
    };

    TEST_F(clientTest, test) {
        ASSERT_EQ(1, 1);
    }
}

