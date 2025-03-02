#include <gtest/gtest.h>
#include <sstream>
#include "../main.cpp" 

using namespace std;

string captureHanoiOutput(int n) {
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    
    moveCount = 0; 
    hanoi(n, 'A', 'B', 'C');
    
    cout.rdbuf(old); 
    return buffer.str();
}

// Тест для 1 диска
TEST(HanoiTest, OneDisk) {
    string expected = "Крок 1: Перемістити диск 1 з A на C\n";
    EXPECT_EQ(captureHanoiOutput(1), expected);
}

// Тест для 2 дисків
TEST(HanoiTest, TwoDisks) {
    string expected = 
        "Крок 1: Перемістити диск 1 з A на B\n"
        "Крок 2: Перемістити диск 2 з A на C\n"
        "Крок 3: Перемістити диск 1 з B на C\n";
    EXPECT_EQ(captureHanoiOutput(2), expected);
}

// Тест для 3 дисків
TEST(HanoiTest, ThreeDisks) {
    string expected = 
        "Крок 1: Перемістити диск 1 з A на C\n"
        "Крок 2: Перемістити диск 2 з A на B\n"
        "Крок 3: Перемістити диск 1 з C на B\n"
        "Крок 4: Перемістити диск 3 з A на C\n"
        "Крок 5: Перемістити диск 1 з B на A\n"
        "Крок 6: Перемістити диск 2 з B на C\n"
        "Крок 7: Перемістити диск 1 з A на C\n";
    EXPECT_EQ(captureHanoiOutput(3), expected);
}

// Тест загальної кількості ходів
TEST(HanoiTest, MoveCount) {
    moveCount = 0;
    hanoi(4, 'A', 'B', 'C');
    EXPECT_EQ(moveCount, 15);  // Для 4 дисків має бути 2^4 - 1 = 15 ходів
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

