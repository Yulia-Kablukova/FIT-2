#pragma once
#include <iostream>
#include <fstream>
#include <tuple>
#include <string>

template <typename... Args>
class CSVParser
{
	struct node
	{
		std::tuple<Args...> rs;
		node* next;
		node* prev;
	};
	node* tail;
	int size;

public:
	class iterator {
		friend class CSVParser;
		node* cur;
		iterator(node* n);

	public:
		iterator& operator=(const iterator& other);
		bool operator!=(const iterator& other) const;
		bool operator==(const iterator& other) const;
		std::tuple<Args...>& operator*();
		std::tuple<Args...>* operator->();
		iterator& operator++();
		iterator operator++(int);
	};

	template<class CharT, class Traits>
	auto operator<<(std::basic_ostream<CharT, Traits>& os);

	CSVParser(std::ifstream& _file, int _size);
	iterator begin();
	iterator end();
	void push_back(const std::string& value);
};
