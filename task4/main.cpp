#include <iostream>
#include <tuple>
#include <string>
#include <fstream>
#include "CSVParser.h"

template <class CharT, class Traits, typename Tuple, std::size_t N>
class tuplePrinter
{
public:
	static void print(std::basic_ostream<CharT, Traits>& os, const Tuple& t)
	{
		tuplePrinter<CharT, Traits, Tuple, N - 1>::print(os, t);
		os << ", " << std::get<N - 1>(t);
	}
};

template <class CharT, class Traits, typename Tuple>
class tuplePrinter<CharT, Traits, Tuple, 1>
{
public:
	static void print(std::basic_ostream<CharT, Traits>& os, const Tuple& t)
	{
		os << std::get<0>(t);
	}
};

template<class CharT, class Traits, typename... Args>
std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, std::tuple<Args...> const& t)
{
	tuplePrinter<CharT, Traits, decltype(t), sizeof...(Args)>::print(os, t);
	return os;
}

char CSVParser<int, std::string>::columnSeparator = ';';
char CSVParser<int, std::string>::stringSeparator = '\n';

int main()
{
	std::ifstream file("test.csv");

	if (!file)
	{
		std::cout << "Can't open the file." << std::endl;
		return EXIT_FAILURE;
	}
	
	int count = 0;
	try
	{
		CSVParser<int, std::string> parser(file, 0);
		count = 1;
		for (std::tuple<int, std::string> rs : parser)
		{
			std::cout << rs << std::endl;
			count++;
		}
	}
	catch (CSVParserException& err)
	{
		if (count) std::cout << "Error in string " << count << ". ";
		std::cout << err.what() << std::endl;
	}

	file.close();
	return EXIT_SUCCESS;
}
