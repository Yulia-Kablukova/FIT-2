#include "linked_list.h"

LinkedList::iterator & LinkedList::iterator::operator=(const iterator & other)
{
	cur = other.cur;
	return *this;
}

bool LinkedList::iterator::operator!=(const iterator & other) const
{
	return cur != other.cur;
}

bool LinkedList::iterator::operator==(const iterator & other) const
{
	return cur == other.cur;
}

//���������� ������ �� ������� ������� ���������.
value_type & LinkedList::iterator::operator*()
{
	return cur->data;
}

//���������� ��������� �� ������� ������� ���������.
value_type * LinkedList::iterator::operator->()
{
	return &cur->data;
}

LinkedList::iterator & LinkedList::iterator::operator++()
{
	cur++;
	return *this;
}

LinkedList::iterator LinkedList::iterator::operator++(int)
{
	node* n = cur;
	cur++;
	return n;
}

LinkedList::iterator & LinkedList::iterator::operator--()
{
	cur--;
	return *this;
}

LinkedList::iterator LinkedList::iterator::operator--(int)
{
	node* n = cur;
	cur--;
	return n;
}
