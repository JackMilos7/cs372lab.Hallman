//File: TestCircularList.cpp
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <gtest/gtest.h>
#include "CircularList.h"

void printInt(int data) {
    std::cout << data << " ";
}

TEST(CircularListTest, InsertAndTraverse) {
    CircularList<int> circularList;
    circularList.push_back(1);
    circularList.push_back(2);
    circularList.push_back(3);

    std::cout << "Circular List: ";
    circularList.traverse(printInt); 
    std::cout << std::endl;

    std::cout << "Circle from position 1: ";
    circularList.circle(1, printInt); 
    std::cout << std::endl;
}

TEST(CircularListTest, CircularBehavior) {
    CircularList<int> circularList;
    circularList.push_front(1);
    circularList.push_back(2);
    circularList.push_back(3);

    EXPECT_EQ(circularList.front(), 1);
    EXPECT_EQ(circularList.back(), 3);

    circularList.pop_front();
    EXPECT_EQ(circularList.front(), 2);

    circularList.pop_back();
    EXPECT_EQ(circularList.back(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}