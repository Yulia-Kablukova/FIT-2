#include <iostream>
#include <gtest/gtest.h>
#include "linked_list.h"

//insert, erase, clear, size, äîñòóï ïî èòåðàòîðó
//Êîíñòðóêòîðû è îïåðàòîðû =
//È îïåðàòîð +=

/*
class TestLinkedList : public ::testing::Test
{
protected:
	void SetUp()
	{
		list = new LinkedList;
	}
	void TearDown()
	{
		delete list;
	}
	LinkedList *list;
};

TEST_F(TestLinkedList, InsertTest) {
	list->insert(list->end(), 5);
	EXPECT_EQ(list->listSize, 1) << "Insert didn't add new element";
}
*/

/*TEST(ClearTest, Clear_ReturnsEmptyList) {
	LinkedList *list = new LinkedList;

	list->clear();
	EXPECT_EQ(list->listSize, 0);

	delete list;
}*/
/*
int main()
{
	//::testing::InitGoogleTest();
	//return RUN_ALL_TESTS();

	system("pause");
}*/

GTEST_API_ int main(int argc, char** argv) {
	printf("Running main() from %s\n", __FILE__);
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
