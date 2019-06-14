#include <iostream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "client.h"
#include "server.h"

#include "clientTest\clientTest.h"
#include "serverTest\serverTest.h"
#include "socketTest\socketTest.h"

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

