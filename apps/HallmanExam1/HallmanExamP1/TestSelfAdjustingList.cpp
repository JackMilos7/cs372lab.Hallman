//File: TestSelfAdjustingList.cpp
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <gtest/gtest.h>
#include "SelfAdjustingList.h"

void printInt(int data) {
    std::cout << data << " ";
}

TEST(SelfAdjustingListTest, InsertAndFind) {
    SelfAdjustingList<int> selfAdjustingList;
    selfAdjustingList.push_back(1);
    selfAdjustingList.push_back(2);
    selfAdjustingList.push_back(3);
    selfAdjustingList.push_back(4);

    std::cout << "SelfAdjusting List before find: ";
    selfAdjustingList.traverse(printInt);
    std::cout << std::endl;

    int* foundItem = selfAdjustingList.find(3);
    ASSERT_NE(foundItem, nullptr);
    EXPECT_EQ(*foundItem, 3);

    std::cout << "SelfAdjusting List after find(3): ";
    selfAdjustingList.traverse(printInt);  
    std::cout << std::endl;

    foundItem = selfAdjustingList.find(2);
    ASSERT_NE(foundItem, nullptr);
    EXPECT_EQ(*foundItem, 2);

    std::cout << "SelfAdjusting List after find(2): ";
    selfAdjustingList.traverse(printInt);  
    std::cout << std::endl;

    foundItem = selfAdjustingList.find(5);
    EXPECT_EQ(foundItem, nullptr);

    std::cout << "SelfAdjusting List after find(5): ";
    selfAdjustingList.traverse(printInt); 
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}