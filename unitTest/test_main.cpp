#include <iostream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "client.h"
#include "server.h"

#include "clientTest\clientTest.h"
#include "serverTest\serverTest.h"
#include "socketTest\socketTest.h"

// MS C++ compiler/linker has a bug on Windows (not on Windows CE), which
// causes a link error when _tmain is defined in a static library and UNICODE
// is enabled. For this reason instead of _tmain, main function is used on
// Windows. See the following link to track the current status of this bug:
// http://connect.microsoft.com/VisualStudio/feedback/ViewFeedback.aspx?FeedbackID=394464  // NOLINT

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

