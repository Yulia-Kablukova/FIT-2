#include "linked_list.h"

LinkedList::const_iterator::const_iterator(node* n) : cur(n) {};

LinkedList::const_iterator& LinkedList::const_iterator::operator=(const const_iterator& other)
{
	cur = other.cur;
	return *this;
}

bool LinkedList::const_iterator::operator!=(const const_iterator& other) const
{
	return cur != other.cur;
}

bool LinkedList::const_iterator::operator==(const const_iterator& other) const
{
	return cur == other.cur;
}

//Возвращает ссылку на текущий элемент коллекции.
const value_type& LinkedList::const_iterator::operator*() const
{
	return cur->data;
}

//Возвращает указатель на текущий элемент коллекции.
const value_type* LinkedList::const_iterator::operator->() const
{
	return &cur->data;
}

LinkedList::const_iterator& LinkedList::const_iterator::operator++()
{
	cur = cur->next;
	return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator++(int)
{
	node* n = cur;
	cur = cur->next;
	return n;
}

LinkedList::const_iterator& LinkedList::const_iterator::operator--()
{
	cur = cur->prev;
	return *this;
}

LinkedList::const_iterator LinkedList::const_iterator::operator--(int)
{
	node* n = cur;
	cur = cur->prev;
	return n;
}
