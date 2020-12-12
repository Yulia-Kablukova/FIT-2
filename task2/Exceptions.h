#pragma once
#include <iostream>
#include <exception>
#include <string>

class CalculatorException : public std::exception {
protected:
	std::string text;

public:
	virtual std::string what() = 0;
};

class OperationException : public CalculatorException {
public:
	OperationException() {
		text = "Operation error.";
	}

	OperationException(std::string _text) { 
		text = _text;
	}
};

class OperationFactoryException : public OperationException {
public:
	OperationFactoryException() {
		text = "Operation factory error.";
	}

	OperationFactoryException(std::string _text) : OperationException(_text) {}
};

class OperationNotFoundException : public OperationFactoryException {
public:
	OperationNotFoundException()
	{
		text = "Operation not found.";
	}

	OperationNotFoundException(std::string _text) : OperationFactoryException(_text) {}

	std::string what()
	{
		return text;
	}
};

class OperationAlreadyRegisteredException : public OperationFactoryException {
public:
	OperationAlreadyRegisteredException()
	{
		text = "Operation is already registered.";
	}

	OperationAlreadyRegisteredException(std::string _text) : OperationFactoryException(_text) {}

	std::string what()
	{
		return text;
	}
};

class NotEnoughElementsInStackException : public OperationException {
public:
	NotEnoughElementsInStackException() {
		text = "Not enough elements in stack.";
	}

	NotEnoughElementsInStackException(std::string _text) : OperationException(_text) {}

	std::string what()
	{
		return text;
	}
};

class NotEnoughArgumentsException : public OperationException {
public:
	NotEnoughArgumentsException() {
		text = "Not enough arguments.";
	}

	NotEnoughArgumentsException(std::string _text) : OperationException(_text) {}

	std::string what()
	{
		return text;
	}
};

class DivisionByZeroException : public OperationException {
public:
	DivisionByZeroException() {
		text = "Division by zero.";
	}

	DivisionByZeroException(std::string _text) : OperationException(_text) {}

	std::string what()
	{
		return text;
	}
};

class SqrtFromNegativeException : public OperationException {
public:
	SqrtFromNegativeException() {
		text = "Taking sqrt from a negative number.";
	}

	SqrtFromNegativeException(std::string _text) : OperationException(_text) {}

	std::string what()
	{
		return text;
	}
};

class UndefinedVariable : public OperationException {
public:
	UndefinedVariable() {
		text = "Trying to push an undefined variable.";
	}

	UndefinedVariable(std::string _text) : OperationException(_text) {}

	std::string what()
	{
		return text;
	}
};
