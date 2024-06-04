//File: TestReceiptBag.cpp 
//Author: Jackson Hallman
//Student Num: 00102945
//Email: jhallma5@my.athens.edu

#include <gtest/gtest.h>
#include "V2ReceiptBag.h"

TEST(ReceiptBagTest, InsertAndRemove) {
    ReceiptBag<int> bag;
    int receipt1 = bag.insert(10);
    int receipt2 = bag.insert(20);

    EXPECT_NO_THROW({
        int item1 = bag.remove(receipt1);
        EXPECT_EQ(item1, 10);
    });

    EXPECT_NO_THROW({
        int item2 = bag.remove(receipt2);
        EXPECT_EQ(item2, 20);
    });
}

TEST(ReceiptBagTest, InvalidReceipt) {
    ReceiptBag<int> bag;
    int receipt = bag.insert(30);

    EXPECT_THROW(bag.remove(receipt + 1), std::invalid_argument);

    EXPECT_NO_THROW({
        int item = bag.remove(receipt);
        EXPECT_EQ(item, 30);
    });

    EXPECT_THROW(bag.remove(receipt), std::invalid_argument);
}

TEST(ReceiptBagTest, ReuseReceipts) {
    ReceiptBag<int> bag;
    int receipt1 = bag.insert(40);
    int receipt2 = bag.insert(50);
    bag.remove(receipt1);
    int receipt3 = bag.insert(60);

    EXPECT_NE(receipt1, receipt3);

    EXPECT_NO_THROW({
        int item2 = bag.remove(receipt2);
        EXPECT_EQ(item2, 50);
    });

    EXPECT_NO_THROW({
        int item3 = bag.remove(receipt3);
        EXPECT_EQ(item3, 60);
    });
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}