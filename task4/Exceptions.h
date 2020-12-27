#pragma once
#include <iostream>
#include <exception>
#include <string>

class CSVParserException : public std::exception {
protected:
	std::string text;

public:
	virtual std::string what() = 0;

	CSVParserException() {
		text = "Parser error.";
	}

	CSVParserException(std::string _text) {
		text = _text;
	}
};

class NotEnoughLinesException : public CSVParserException {
public:
	NotEnoughLinesException() {
		text = "Not enough lines in the file.";
	}

	NotEnoughLinesException(std::string _text) : CSVParserException(_text) {}

	std::string what()
	{
		return text;
	}
};

class InvalidTypeException : public CSVParserException {
public:
	InvalidTypeException() {
		text = "Data type doesn't matches the data.";
	}

	InvalidTypeException(int column) {
		text = "Column " + std::to_string(column) + ": data type doesn't matches the data.";
	}

	InvalidTypeException(std::string _text) : CSVParserException(_text) {}

	std::string what()
	{
		return text;
	}
};

class NotSupportedTypeException : public CSVParserException {
public:
	NotSupportedTypeException() {
		text = "Type is not supported.";
	}

	NotSupportedTypeException(std::string _text) : CSVParserException(_text) {}

	NotSupportedTypeException(int column) {
		text = "Column " + std::to_string(column) + ": type is not supported.";
	}

	std::string what()
	{
		return text;
	}
};
