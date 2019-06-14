#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>

namespace {
    class serverTest : public testing::Test {
    protected:
        virtual void SetUp() {
        }
    };

    TEST_F(serverTest, test) {
        ASSERT_EQ(1, 1);
    }
}