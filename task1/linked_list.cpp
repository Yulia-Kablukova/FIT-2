#include "linked_list.h"

int LinkedList::size() const
{
	return listSize;
}

bool LinkedList::empty() const
{
	if (listSize)
		return false;
	return true;
}

value_type & LinkedList::front()
{
	return head->data;
}

const value_type & LinkedList::front() const
{
	return head->data;
}

value_type & LinkedList::back()
{
	return end->data;
}

const value_type & LinkedList::back() const
{
	return end->data;
}
