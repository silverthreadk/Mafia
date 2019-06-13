#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>

namespace {
    class socketTest : public testing::Test {
    protected:
        virtual void SetUp() {
        }
    };

    TEST_F(socketTest, test) {
        ASSERT_EQ(1, 1);
    }
}