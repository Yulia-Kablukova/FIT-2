#include "linked_list.h"

LinkedList::iterator::iterator(node* n) : cur(n) {}

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

//Возвращает ссылку на текущий элемент коллекции.
value_type & LinkedList::iterator::operator*()
{
	return cur->data;
}

//Возвращает указатель на текущий элемент коллекции.
value_type * LinkedList::iterator::operator->()
{
	return &cur->data;
}

LinkedList::iterator & LinkedList::iterator::operator++()
{
	cur = cur->next;
	return *this;
}

LinkedList::iterator LinkedList::iterator::operator++(int)
{
	node* n = cur;
	cur = cur->next;
	return n;
}

LinkedList::iterator & LinkedList::iterator::operator--()
{
	cur = cur->prev;
	return *this;
}

LinkedList::iterator LinkedList::iterator::operator--(int)
{
	node* n = cur;
	cur = cur->prev;
	return n;
}
