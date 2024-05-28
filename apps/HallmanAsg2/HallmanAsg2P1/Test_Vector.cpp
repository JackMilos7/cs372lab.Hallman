//File: test_Vector.cpp
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <gtest/gtest.h>
#include "Vector.h"

TEST(VectorTest, Addition) {
    Vector v1({1.0, 2.0, 3.0});
    Vector v2({4.0, 5.0, 6.0});
    Vector result = v1 + v2;

    ASSERT_EQ(result.size(), 3);
    EXPECT_DOUBLE_EQ(result[0], 5.0);
    EXPECT_DOUBLE_EQ(result[1], 7.0);
    EXPECT_DOUBLE_EQ(result[2], 9.0);
}

TEST(VectorTest, Subtraction) {
    Vector v1({1.0, 2.0, 3.0});
    Vector v2({4.0, 5.0, 6.0});
    Vector result = v1 - v2;

    ASSERT_EQ(result.size(), 3);
    EXPECT_DOUBLE_EQ(result[0], -3.0);
    EXPECT_DOUBLE_EQ(result[1], -3.0);
    EXPECT_DOUBLE_EQ(result[2], -3.0);
}

TEST(VectorTest, ScalarMultiplication) {
    Vector v({1.0, 2.0, 3.0});
    double scalar = 2.0;
    Vector result = v * scalar;

    ASSERT_EQ(result.size(), 3);
    EXPECT_DOUBLE_EQ(result[0], 2.0);
    EXPECT_DOUBLE_EQ(result[1], 4.0);
    EXPECT_DOUBLE_EQ(result[2], 6.0);
}

TEST(VectorTest, DotProduct) {
    Vector v1({1.0, 2.0, 3.0});
    Vector v2({4.0, 5.0, 6.0});
    double result = v1.dot(v2);

    EXPECT_DOUBLE_EQ(result, 32.0);
}

TEST(VectorTest, Norm) {
    Vector v({3.0, 4.0});
    double result = v.norm();

    EXPECT_DOUBLE_EQ(result, 5.0);
}

TEST(VectorTest, SizeMismatchThrows) {
    Vector v1({1.0, 2.0, 3.0});
    Vector v2({4.0, 5.0});
    
    EXPECT_THROW(v1 + v2, std::invalid_argument);
    EXPECT_THROW(v1 - v2, std::invalid_argument);
    EXPECT_THROW(v1.dot(v2), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}