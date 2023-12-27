#include "bombs.cpp"
#include <gtest/gtest.h>
#include <utility>

// Custom comparison operator for pairs
bool operator==(const std::pair<Bomb, int>& l, const std::pair<Bomb, int>& r) {
    return l.first.x == r.first.x && l.first.y == r.first.y && l.first.r == r.first.r && l.second == r.second;
}

// Test cases
TEST(F, A) {
    {
        std::ofstream out("input.txt");
        out << "2 1 3\n6 1 4\n";
        out.close();
        ASSERT_EQ(std::make_pair(Bomb(6, 1, 4), 2), solve("input.txt"));
    }

    {
        std::ofstream out("input.txt");
        out << "1 1 5\n10 10 5\n";
        out.close();
        ASSERT_EQ(std::make_pair(Bomb(1, 1, 5), 1), solve("input.txt"));
    }

    {
        std::ofstream out("input.txt");
        out << "1 2 3\n2 3 1\n3 4 2\n4 5 3\n5 6 4\n";
        out.close();
        ASSERT_EQ(std::make_pair(Bomb(1, 2, 3), 5), solve("input.txt"));
    }
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

