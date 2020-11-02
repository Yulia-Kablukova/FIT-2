#include <gtest/gtest.h>
#include "linked_list.h"

class TestLinkedList : public ::testing::Test
{
protected:
	void SetUp()
	{
		list = new LinkedList;
	}
	void TearDown() {}
	LinkedList* list;
};

TEST_F(TestLinkedList, InsertTest) {
	list->insert(list->end(), 5);
	EXPECT_EQ(list->listSize, 1);
}

TEST_F(TestLinkedList, EraseDeleteElement) {
	list->insert(list->end(), 5);
	list->erase(list->end().cur->prev);
	EXPECT_EQ(list->listSize, 0);
}

TEST_F(TestLinkedList, ClearReturnsEmptyList) {
	list->clear();
	EXPECT_EQ(list->listSize, 0);
}

TEST_F(TestLinkedList, SizeTest) {
	EXPECT_EQ(list->listSize, list->size());
	list->insert(list->end(), 5);
	EXPECT_EQ(list->listSize, list->size());
}
