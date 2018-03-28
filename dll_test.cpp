#include "doubly_linked_list.h"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("copy test and push test")
{
    SUBCASE("SUCCESS CASE")
    {
        DoublyLinkedList list1;
        CHECK_NOTHROW(list1.push(1));
        CHECK_NOTHROW(list1.push(2));
        CHECK_NOTHROW(list1.push(3));
        DoublyLinkedList list2 = list1;
        CHECK(list2.toString() == list1.toString());
        CHECK_NOTHROW(list1.push(4));
        CHECK_NOTHROW(list2.push(5));
        CHECK_NOTHROW(list2.push(3));
        CHECK(list1.size()==4);
        CHECK(list2.size()==5);
        CHECK(list2.toString() != list1.toString());
        CHECK(list1.toString() == "1 2 3 4 ");
        CHECK(list2.toString() == "1 2 3 5 3 ");
    }
}

TEST_CASE("insert test")
{
    SUBCASE("SUCCESS CASE")
    {
        DoublyLinkedList list1;
        list1.push(0);
        list1.push(1);
        list1.push(2);
        CHECK_NOTHROW(list1.insert(0, 7));
        CHECK_NOTHROW(list1.insert(1, 6));
        CHECK_NOTHROW(list1.insert(5, 8));
        CHECK(list1.toString() == "7 6 0 1 2 8 ");
    }

    SUBCASE("FAILURE CASE")
    {
        DoublyLinkedList list1;
        CHECK_THROWS(list1.insert(7, 5));
        list1.push(1);
        CHECK_THROWS(list1.insert(5, 4));
        CHECK_THROWS(list1.insert(-7, 3));
    }
}
TEST_CASE("getElem test")
{
    SUBCASE("SUCCESS CASE")
    {
        DoublyLinkedList list1;
        list1.push(6);
        list1.push(1);
        list1.push(3);
        CHECK_NOTHROW(list1.getElem(0) == 6);
        CHECK_NOTHROW(list1.getElem(1) == 1);
        CHECK_NOTHROW(list1.getElem(2) == 3);

    }

    SUBCASE("FAILURE CASE")
    {
      DoublyLinkedList list1;
      CHECK_THROWS(list1.getElem(0));
      list1.push(6);
      list1.push(1);
      list1.push(3);
      CHECK_THROWS(list1.getElem(-11));
      CHECK_THROWS(list1.getElem(7));
    }
}
TEST_CASE("delete test")
{
    SUBCASE("SUCCESS CASE")
    {
        DoublyLinkedList list1;
        list1.push(1);
        list1.push(3);
        list1.push(7);
        list1.push(8);
        CHECK(list1.deleteElem(1) == 3);
        CHECK(list1.deleteElem(2) == 8);
        CHECK(list1.deleteElem(0) == 1);
        CHECK(list1.size()==1);
    }
        SUBCASE("FAILURE CASE")
    {
        DoublyLinkedList list1;
    CHECK_THROWS(list1.deleteElem(0));
    list1.push(1);
    list1.push(3);
    list1.push(7);
    list1.push(8);
    CHECK_THROWS(list1.deleteElem(-4));
    CHECK_THROWS(list1.deleteElem(5));
  }
}
TEST_CASE("iterator test")
{
  SUBCASE("SUCCESS CASE")
  {
  DoublyLinkedList list1;
  list1.push(1);
  list1.push(2);
  list1.push(3);
  DoublyLinkedList::iterator it = list1.begin();
  string test = "";
  for (it; it != list1.end(); ++it) {
    test.append(std::to_string(*it));
    test.append(" ");
  }
  CHECK(test == "1 2 3 ");
  }
}
