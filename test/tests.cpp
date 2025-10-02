#include <gtest/gtest.h>
// #include "string"
#include "../include/six.h"

TEST(test_equalents_ravn, basic_test_set)
{
    Six arr{"12"};
    Six arr2{"12"};
    ASSERT_TRUE((arr==arr2) == 1);
}

TEST(test_equalents_more, basic_test_set)
{
    Six arr{"1042"};
    Six arr2{"144"};

    ASSERT_TRUE((arr > arr2) == 1);
}

TEST(test_equalents_less, basic_test_set)
{
    Six arr{"1042"};
    Six arr2{"144"};

    ASSERT_TRUE((arr < arr2) == 0);
}

TEST(test_equalents_more_ravn, basic_test_set)
{
    Six arr{"1042"};
    Six arr2{"144"};

    ASSERT_TRUE((arr >= arr2) == 1);
}

TEST(test_equalents_less_ravn, basic_test_set)
{
    Six arr{"1042"};
    Six arr2{"144"};

    ASSERT_TRUE((arr <= arr2) == 0);
}

TEST(test_sum, basic_test_set)
{
    Six arr{"12"};
    Six arr2{"12"};
    Six s = arr + arr2;

    Six istina{"24"};
    ASSERT_TRUE(s == istina);
}

TEST(test_sub_1, basic_test_set)
{
    Six arr{"12"};
    Six arr2{"555555"};
    Six s = arr - arr2;

    Six istina{"0"};
    ASSERT_TRUE(s == istina);
}

TEST(test_sub_2, basic_test_set)
{
    Six arr{"12"};
    Six arr2{"555555"};
    Six s = arr - arr2;

    Six istina{"0"};
    ASSERT_TRUE(s == istina);
}

TEST(test_sub_3, basic_test_set)
{
    Six arr{"1042"};
    Six arr2{"144"};
    Six s = arr - arr2;

    Six istina{"454"};
    ASSERT_TRUE(s == istina);
}

TEST(test_copy, basic_test_set)
{
    Six arr{"1042"};
    Six arr2(arr);

    ASSERT_TRUE(arr == arr2);
}

TEST(test_move, basic_test_set)
{
    Six arr{"1042"};
    Six arr2(std::move(arr));

    Six istina{"1042"};
    Six pust;
    ASSERT_TRUE((arr2 == istina) && (arr == pust));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}