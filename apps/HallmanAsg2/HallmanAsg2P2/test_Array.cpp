//File: test_Array.cpp
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <gtest/gtest.h>
#include "Array.h"

TEST(ArrayTest, Addition) {
    Array<double, 3> a1({1.0, 2.0, 3.0});
    Array<double, 3> a2({4.0, 5.0, 6.0});
    Array<double, 3> result = a1 + a2;

    ASSERT_EQ(result.size(), 3);
    EXPECT_DOUBLE_EQ(result[0], 5.0);
    EXPECT_DOUBLE_EQ(result[1], 7.0);
    EXPECT_DOUBLE_EQ(result[2], 9.0);
}

TEST(ArrayTest, Subtraction) {
    Array<double, 3> a1({1.0, 2.0, 3.0});
    Array<double, 3> a2({4.0, 5.0, 6.0});
    Array<double, 3> result = a1 - a2;

    ASSERT_EQ(result.size(), 3);
    EXPECT_DOUBLE_EQ(result[0], -3.0);
    EXPECT_DOUBLE_EQ(result[1], -3.0);
    EXPECT_DOUBLE_EQ(result[2], -3.0);
}

TEST(ArrayTest, ScalarMultiplication) {
    Array<double, 3> a({1.0, 2.0, 3.0});
    double scalar = 2.0;
    Array<double, 3> result = a * scalar;

    ASSERT_EQ(result.size(), 3);
    EXPECT_DOUBLE_EQ(result[0], 2.0);
    EXPECT_DOUBLE_EQ(result[1], 4.0);
    EXPECT_DOUBLE_EQ(result[2], 6.0);
}

TEST(ArrayTest, DotProduct) {
    Array<double, 3> a1({1.0, 2.0, 3.0});
    Array<double, 3> a2({4.0, 5.0, 6.0});
    double result = a1.dot(a2);

    EXPECT_DOUBLE_EQ(result, 32.0);
}

TEST(ArrayTest, Norm) {
    Array<double, 2> a({3.0, 4.0});
    double result = a.norm();

    EXPECT_DOUBLE_EQ(result, 5.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}