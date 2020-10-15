#include <iostream>
#include "linked_list.h"

int main()
{
	LinkedList *list = new LinkedList;

	std::cout << list->size() << std::endl << list->front() << std::endl << list->empty() << std::endl;

	system("pause");
	return 0;
}
