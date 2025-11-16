#include <gtest/gtest.h>
#include <pocketracing/pocketracing.hpp>

TEST(All, All)
{
    ASSERT_NO_THROW(pocketracing::server server(1357));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
