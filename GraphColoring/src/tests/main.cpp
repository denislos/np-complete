#include <gtest/gtest.h>

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
#ifdef _DEBUG
    ::testing::FLAGS_gtest_break_on_failure = true;
#endif
    return RUN_ALL_TESTS();
}