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

/*template <class CharT, class Traits, typename... Args>
void print(std::basic_ostream<CharT, Traits>& os, const std::tuple<Args...>& t)
{
  tuplePrinter<CharT, Traits, decltype(t), sizeof...(Args)>::print(os, t);
}*/

template<class CharT, class Traits, typename... Args>
auto operator<<(std::basic_ostream<CharT, Traits>& os, std::tuple<Args...> const& t)
{
	tuplePrinter<CharT, Traits, decltype(t), sizeof...(Args)>::print(os, t);
}

int main()
{
	std::tuple<int, std::string, double> t(1, "Hello, world!", 5.5);
	std::cout << t;
	std::cout << std::endl;


	std::ifstream file("test.csv");
	CSVParser<int, std::string> parser(file, 0);
	for (std::tuple<int, std::string> rs : parser) {
		std::cout << rs;
		std::cout << std::endl;
	}
  file.close();

	return 0;
}
