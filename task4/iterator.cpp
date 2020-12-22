#include "CSVParser.h"

CSVParser<>::iterator::iterator(node* n) : cur(n) {};

CSVParser<>::iterator& CSVParser<>::iterator::operator=(const iterator& other)
{
	cur = other.cur;
	return *this;
}

bool CSVParser<>::iterator::operator!=(const iterator& other) const
{
	return cur != other.cur;
}

bool CSVParser<>::iterator::operator==(const iterator& other) const
{
	return cur == other.cur;
}

std::tuple<>& CSVParser<>::iterator::operator*()
{
	return cur->rs;
}

std::tuple<>* CSVParser<>::iterator::operator->()
{
	return &cur->rs;
}

CSVParser<>::iterator& CSVParser<>::iterator::operator++()
{
	cur = cur->next;
	return *this;
}

CSVParser<>::iterator CSVParser<>::iterator::operator++(int)
{
	node* n = cur;
	cur = cur->next;
	return n;
}
