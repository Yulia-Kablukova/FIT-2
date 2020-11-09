#include <gtest/gtest.h>
#include "linked_list.h"

TEST(TestLinkedList, PushBackTest) {
	LinkedList list;

	list.push_back(5);
	list.push_back(10);

	EXPECT_EQ(list.size(), 2);
	EXPECT_EQ(list.front(), 5);
	EXPECT_EQ(list.back(), 10);
}

TEST(TestLinkedList, PushFrontTest) {
	LinkedList list;

	list.push_front(5);
	list.push_front(10);

	EXPECT_EQ(list.size(), 2);
	EXPECT_EQ(list.front(), 10);
	EXPECT_EQ(list.back(), 5);
}

TEST(TestLinkedList, BeginTest) {
	LinkedList list;

	list.push_back(5);
	list.push_back(10);

	EXPECT_EQ(*(list.begin()), 5);
}

TEST(TestLinkedList, EndTest) {
	LinkedList list;
	LinkedList::iterator it = list.end();

	list.push_back(5);
	list.push_back(10);

	EXPECT_EQ(list.end(), it);
}

TEST(TestLinkedList, InsertTest) {
	LinkedList list;

	list.insert(list.end(), 5);

	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(list.back(), 5);
}

TEST(TestLinkedList, SizeTest) {
	LinkedList list;

	EXPECT_EQ(0, list.size());

	list.push_back(5);
	list.push_back(10);

	EXPECT_EQ(2, list.size());
}

TEST(TestLinkedList, EraseTest) {
	LinkedList list;
	list.push_back(5);
	list.push_back(10);

	list.erase(list.begin());

	EXPECT_EQ(list.size(), 1);
	EXPECT_EQ(list.front(), 10);
}

TEST(TestLinkedList, ClearReturnsEmptyList) {
	LinkedList list;
	list.push_back(5);
	list.push_back(10);

	list.clear();

	EXPECT_EQ(list.size(), 0);
}

TEST(TestLinkedList, OperatorEquallyTest) {
	LinkedList list1;
	list1.push_back(5);
	list1.push_back(10);
	LinkedList list2;
	list2.push_back(5);

	list2 = list1;

	EXPECT_EQ(list1.size(), list2.size());
	EXPECT_EQ(list1.front(), list2.front());
	EXPECT_EQ(list1.back(), list2.back());
}

TEST(TestLinkedList, OperatorEquallyPlusTest) {
	LinkedList list1;
	list1.push_back(5);
	LinkedList list2;
	list2.push_back(10);

	list1 += list2;

	EXPECT_EQ(list1.size(), 1 + list2.size());
}
