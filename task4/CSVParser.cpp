#include "CSVParser.h"

CSVParser<>::CSVParser(std::ifstream& file, int _size)
{
	tail = new node;
	tail->next = tail->prev = tail;
	size = _size;

	std::string line;
	while (std::getline(file, line))
	{
		push_back(line);
	}
}

template <typename... Args>
template<class CharT, class Traits>
auto CSVParser<Args...>::operator<<(std::basic_ostream<CharT, Traits>& os)
{

}

CSVParser<>::iterator CSVParser<>::begin()
{
	return tail->next;
}

CSVParser<>::iterator CSVParser<>::end()
{
	return tail;
}

template <typename... Args>
void CSVParser<Args...>::push_back(const std::string& value)
{
	node* tmp = new node;
	//std::get<1>(tmp->rs) = value;
	tmp->prev = tail->prev;
	tmp->next = tail;
	tail->prev->next = tmp;
	tail->prev = tmp;
}
