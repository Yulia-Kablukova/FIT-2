#pragma once
#include <iostream>
#include <fstream>
#include <tuple>
#include <string>
#include <typeinfo>
#include "Exceptions.h"

template <typename... Args>
class CSVParser
{
	std::ifstream& file;
	int size;
	int skipNumber;
	static char columnSeparator;
	static char stringSeparator;

public:
	class iterator;

	CSVParser(std::ifstream& _file, int _skipNumber) : file(_file)
	{
		skipNumber = _skipNumber;
		//try
		//{
			skipLines(file, skipNumber);
		//}
		//catch (CSVParserException& err)
		//{
			//std::cout << err.what() << std::endl;
		//}
		file.seekg(0, SEEK_END);
		size = file.tellg();
	}

	iterator begin()
	{
		file.seekg(0, SEEK_SET);
		skipLines(file, skipNumber);
		return file;
	}

	iterator end()
	{
		file.seekg(0, SEEK_END);
		return file;
	}

	void skipLines(std::ifstream& _file, int _skipNumber)
	{
		std::string str;
		for (int i = 0; i < _skipNumber; i++)
		{
			if (!getLine(_file, str))
			{
				throw NotEnoughLinesException("Not enough lines in the file or skipNumber is incorrect.");
			}
		}
	}

	static int getLine(std::ifstream& _file, std::string& str)
	{
		char c;
		_file.get(c);
		if (_file.eof())
			return 0;
		while (c != stringSeparator && !_file.eof())
		{
			str += c;
			_file.get(c);
		}
		return str.size();
	}

	class iterator {
		friend class CSVParser;

		std::ifstream& file;
		int pos;
		std::tuple<Args...> cur;

		iterator(std::ifstream& _file) : file(_file)
		{
			pos = file.tellg();
			cur = getTuple();
		};

	public:
		iterator& operator=(const iterator& other)
		{
			file = other.file;
			pos = other.pos;
			cur = other.cur;
			return *this;
		}
		bool operator!=(const iterator& other) const
		{
			return pos != other.pos;
		}
		bool operator==(const iterator& other) const
		{
			return pos == other.pos;
		}
		std::tuple<Args...>& operator*()
		{
			return cur;
		}
		std::tuple<Args...>* operator->()
		{
			return &cur;
		}
		iterator& operator++()
		{
			file.clear();
			file.seekg(pos, SEEK_SET);
			std::string line;
			getLine(file, line);
			pos = file.tellg();
			cur = getTuple();
			return *this;
		}
		iterator operator++(int)
		{
			int tmp = pos;

			file.seekg(pos, SEEK_SET);
			std::string line;
			getLine(file, line);
			pos = file.tellg();
			cur = getTuple();

			file.seekg(tmp, SEEK_SET);
			return file;
		}

		
		template <std::size_t N>
		class tupleMaker
		{
		public:
			static void getTuple(std::tuple<Args...>& t, std::string& line)
			{
				tupleMaker<N - 1>::getTuple(t, line);

				std::string item;
				while (line[0] != columnSeparator && line.size() != 0)
				{
					item += line[0];
					line.erase(0, 1);
				}
				line.erase(0, 1);
				
				if (typeid(std::get<N - 1>(t)) == typeid(int))
				{
					try
					{
						std::get<N - 1>(t) = stoi(item);
					}
					catch (std::exception& err)
					{
						throw InvalidTypeException(N);
					}
					return;
				}

				if (typeid(std::get<N - 1>(t)).name() == "double")
				{
					try
					{
						std::get<N - 1>(t) = stod(item);
					}
					catch (std::exception& err)
					{
						throw InvalidTypeException(N);
					}
					return;
				}

				if (typeid(std::get<N - 1>(t)).name() == typeid(std::string).name())
				{
					try
					{
						std::get<N - 1>(t) = item;
					}
					catch (std::exception& err)
					{
						throw InvalidTypeException(N);
					}
					return;
				}

				throw NotSupportedTypeException(N);
			}
		};
		template <>
		class tupleMaker<1>
		{
			friend class CSVParser;
		public:
			static void getTuple(std::tuple<Args...>& t, std::string& line)
			{
				std::string item;
				while (line[0] != columnSeparator && line.size() != 0)
				{
					item += line[0];
					line.erase(0, 1);
				}
				line.erase(0, 1);

				if (typeid(std::get<0>(t)) == typeid(int))
				{
					try
					{
						std::get<0>(t) = stoi(item);
					}
					catch (std::exception &err)
					{
						throw InvalidTypeException(1);
					}
					return;
				}
					
				if (typeid(std::get<0>(t)).name() == "double")
				{
					try
					{
						std::get<0>(t) = stod(item);
					}
					catch (std::exception& err)
					{
						throw InvalidTypeException(1);
					}
					return;
				}
					
				if (typeid(std::get<0>(t)).name() == typeid(std::string).name())
				{
					try
					{
						std::get<0>(t) = stoi(item);
					}
					catch (std::exception& err)
					{
						throw InvalidTypeException(1);
					}
					return;
				}
					
				throw NotSupportedTypeException(1);
			}
		};
		std::tuple<Args...> getTuple()
		{
			file.seekg(pos, SEEK_SET);

			std::string line;
			std::tuple<Args...> t;

			if (pos != -1 && getLine(file, line))
			{
				tupleMaker<sizeof...(Args)>::getTuple(t, line);
			}
			return t;
		}
	};
};
