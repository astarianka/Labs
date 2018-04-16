#include "BST.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <math.h>
TEST_CASE("ADD AND TRAVELSAL TEST")
{
    SUBCASE("SUCCESS CASE")
    {
        BinaryTree test;
        CHECK_NOTHROW(test.add(6.15));
        CHECK_NOTHROW(test.add(3.832));
        CHECK_NOTHROW(test.add(9));
        CHECK_NOTHROW(test.add(15.01));
        CHECK_NOTHROW(test.add(1));
        CHECK_NOTHROW(test.add(5.4));
        CHECK_NOTHROW(test.add(8));
        CHECK_NOTHROW(test.add(80));
        CHECK_NOTHROW(test.add(-23.5));
        CHECK_NOTHROW(test.add(-8));
        CHECK_NOTHROW(test.add(0));
        CHECK(test.inOrderTraversal() == "-23.500000 -8.000000 0.000000 1.000000 3.832000 5.400000 6.150000 8.000000 9.000000 15.010000 80.000000 ");
        CHECK(test.postOrderTraversal() == "0.000000 -8.000000 -23.500000 1.000000 5.400000 3.832000 8.000000 80.000000 15.010000 9.000000 6.150000 ");
        CHECK(test.preOrderTraversal() == "6.150000 3.832000 1.000000 -23.500000 -8.000000 0.000000 5.400000 9.000000 8.000000 15.010000 80.000000 ");
        CHECK_NOTHROW(test.add(23.5));
        CHECK_NOTHROW(test.add(9));
        CHECK(test.inOrderTraversal() == "-23.500000 -8.000000 0.000000 1.000000 3.832000 5.400000 6.150000 8.000000 9.000000 9.000000 15.010000 23.500000 80.000000 ");
        CHECK(test.postOrderTraversal() == "0.000000 -8.000000 -23.500000 1.000000 5.400000 3.832000 8.000000 9.000000 23.500000 80.000000 15.010000 9.000000 6.150000 ");
        CHECK(test.preOrderTraversal() == "6.150000 3.832000 1.000000 -23.500000 -8.000000 0.000000 5.400000 9.000000 8.000000 15.010000 9.000000 80.000000 23.500000 ");
    }

    SUBCASE("FAILURE CASE")
    {
        BinaryTree test;
        CHECK_THROWS(test.inOrderTraversal());
        CHECK_THROWS(test.postOrderTraversal());
        CHECK_THROWS(test.preOrderTraversal());
    }
}
TEST_CASE("SEARCH TEST")
{
    SUBCASE("SUCCESS CASE")
    {
        BinaryTree test;
        test.add(6.15);
        test.add(3.832);
        test.add(9);
        test.add(15.01);
        test.add(1);
        test.add(5.4);
        test.add(8);
        test.add(80);
        test.add(-23.5);
        test.add(-8);
        test.add(0);

        CHECK(test.search(80) == "6.150000 9.000000 15.010000 80.000000");
        CHECK(test.search(6.15) == "6.150000");
        CHECK(test.search(-23.5) == "6.150000 3.832000 1.000000 -23.500000");
        CHECK_NOTHROW(test.add(23.5));
        CHECK(test.search(23.5) == "6.150000 9.000000 15.010000 80.000000 23.500000");
        CHECK(test.search(9) == "6.150000 9.000000");

    }

    SUBCASE("FAILURE CASE")
    {
        BinaryTree test;
        CHECK_THROWS(test.search(6.15));
        test.add(56);
        test.add(67);
        CHECK_THROWS(test.search(6.15));
    }
}
TEST_CASE("AVERADGE TEST")
{
    SUBCASE("SUCCESS CASE")
    {
        BinaryTree test;
        test.add(6.15);
        test.add(3.832);
        test.add(9);
        test.add(15.01);
        test.add(5.4);
        test.add(8);
        test.add(-23.5);
        test.add(-8);
        test.add(0);

        CHECK(round(test.averadge()*100000)/100000 == 1.76578);
test.add(23.5);
CHECK(std::to_string(test.averadge()) == "3.939200" );
CHECK_NOTHROW(test.add_averadge());
CHECK(test.inOrderTraversal() == "-23.500000 -8.000000 0.000000 3.832000 3.939200 5.400000 6.150000 8.000000 9.000000 15.010000 23.500000 ");
CHECK(test.preOrderTraversal() == "6.150000 3.832000 -23.500000 -8.000000 0.000000 5.400000 3.939200 9.000000 8.000000 15.010000 23.500000 ");
CHECK(test.postOrderTraversal() == "0.000000 -8.000000 -23.500000 3.939200 5.400000 3.832000 8.000000 23.500000 15.010000 9.000000 6.150000 ");
SUBCASE("FAILURE CASE")
{
    BinaryTree test;
    CHECK_THROWS(test.averadge()); //empty
    CHECK_THROWS(test.add_averadge()); //empty
}
    }
}
