#include <gtest/gtest.h>
#include "linked_list.h"


TEST(TestLinkedList, PushBackTest) {
	LinkedList* list = new LinkedList;

	list->push_back(5);
	list->push_back(10);

	EXPECT_EQ(list->listSize, 2);
	EXPECT_EQ(list->tail->prev->data, 10);
}

TEST(TestLinkedList, PushFrontTest) {
	LinkedList* list = new LinkedList;

	list->push_front(5);
	list->push_front(10);

	EXPECT_EQ(list->listSize, 2);
	EXPECT_EQ(list->tail->next->data, 10);
}

TEST(TestLinkedList, BeginTest) {
	LinkedList* list = new LinkedList;

	list->push_back(5);
	list->push_back(10);

	EXPECT_EQ(list->begin().cur->data, 5);
}

TEST(TestLinkedList, EndTest) {
	LinkedList* list = new LinkedList;

	list->push_back(5);
	list->push_back(10);

	EXPECT_EQ(list->end().cur, list->tail);
}

TEST(TestLinkedList, InsertTest) {
	LinkedList* list = new LinkedList;

	list->insert(list->end(), 5);

	EXPECT_EQ(list->listSize, 1);
	EXPECT_EQ(list->tail->prev->data, 5);
}

TEST(TestLinkedList, SizeTest) {
	LinkedList* list = new LinkedList;

	EXPECT_EQ(0, list->size());

	list->push_back(5);
	list->push_back(10);

	EXPECT_EQ(list->listSize, list->size());
	EXPECT_EQ(2, list->size());
}

TEST(TestLinkedList, EraseTest) {
	LinkedList* list = new LinkedList;
	list->push_front(5);

	list->erase(list->begin());

	EXPECT_EQ(list->listSize, 0);
}

TEST(TestLinkedList, ClearReturnsEmptyList) {
	LinkedList* list = new LinkedList;
	list->push_back(5);
	list->push_back(10);

	list->clear();
	
	EXPECT_EQ(list->listSize, 0);
}

TEST(TestLinkedList, OperatorEqually) {
	LinkedList* list1 = new LinkedList;
	list1->push_back(5);
	list1->push_back(10);
	LinkedList* list2 = new LinkedList;
	list2->push_back(5);
	
	list2->operator=(*list1);

	EXPECT_EQ(list1->listSize, list2->listSize);
	EXPECT_EQ(list1->front(), list2->front());
}

TEST(TestLinkedList, OperatorEquallyPlus) {
	LinkedList* list1 = new LinkedList;
	list1->push_back(5);
	LinkedList* list2 = new LinkedList;
	list1->push_back(10);
	int size = list1->listSize;

	list1->operator+=(*list2);

	EXPECT_EQ(list1->listSize, size + list2->listSize);
}
