/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:43:30 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/27 17:44:31 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	valid_format(std::string args)
{
	std::string valid = "+-*/ ";

	for (int i = 0; args[i]; i++)
	{
		if (!std::isdigit(args[i]) && valid.find(args[i]) == std::string::npos)
			throw RPN::InvalidCharacterException(args[i]);
	}
}

bool	is_number(std::string str)
{
	for (unsigned long i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	if (std::atoi(str.c_str()) > 9)
		throw RPN::InvalidNumberException();
	return (true);
}

bool	is_op(std::string str)
{
	std::string valid = "+-*/";
	for (unsigned long i = 0; i < str.length(); i++)
	{
		if (valid.find(str[i]) == std::string::npos)
			return (false);
	}
	return (true);
}

int	RPN::count_numbers(std::string args)
{
	int	count  = 0;

	for (unsigned long i = 0; i < args.length(); i++)
	{
		while (i < args.length())
		{
			if (std::isdigit(args[i]))
				break ;
			i++;
		}
		if (std::isdigit(args[i]))
		{
			count++;
			while (args[i + 1] && std::isdigit(args[i + 1]))
			{
				i++;
			}
		}
	}
	return (count);
}

int RPN::count_ops(std::string args)
{
	std::string	valid = "+-*/";
	int			ops_count = 0;

	for (int i = 0; args[i]; i++)
	{
		while (args[i] && valid.find(args[i]) == std::string::npos)
			i++;
		if (valid.find(args[i]) != std::string::npos)
		{
			ops_count++;
		}
	}
	return (ops_count);
}

RPN::RPN(std::string args): ops(""), numbers_string(""), input(args)
{
	int ops_count, numbers_count;

	valid_format(args);
	ops_count = count_ops(args);
	(void) ops_count;
	numbers_count = count_numbers(args);
	if (ops_count != numbers_count - 1)
		throw MismatchOperatorsNumbersException();
}

RPN::RPN(RPN &other): \
numbers(std::stack<int>(other.numbers)), ops(other.ops), numbers_string(other.numbers_string)
{}

RPN &RPN::operator=(RPN &other)
{
	if (this != &other)
	{
		ops = other.ops;
		numbers_string = other.numbers_string;
		numbers = other.numbers;
	}
	return (*this);
}

RPN::~RPN() {}

int	RPN::sum( void )
{
	int				next_space, a, b;
	std::string		elem;

	next_space = input.find(' ');
	elem = input.substr(0, next_space);
	input = input.substr(next_space + 1, input.length() - 1);
	for (int j = 0; j < 2; j++)
	{
		if (is_number(elem))
			numbers.push(std::atoi(elem.c_str()));
		else
			throw InvalidFirstElementsException();
	}
	while (input.find(' ') != std::string::npos || input[0])
	{
		if (input.length() == 1)
		{
			elem = input.substr(0, 2);
			input = input.substr(1, 2);
		}
		else
		{
			elem = input.substr(0, next_space);
			input = input.substr(next_space + 1, input.length() - 1);
		}
		if (is_number(elem))
			numbers.push(std::atoi(elem.c_str()));
		else if (is_op(elem))
		{
			b = numbers.top();
			numbers.pop();
			a = numbers.top();
			numbers.pop();
			switch (elem[0])
			{
				case '*':
					numbers.push(a * b);
					break;
				case '+':
					numbers.push(a + b);
					break;
				case '-':
					numbers.push(a - b);
					break;
				case '/':
					numbers.push(a / b);
					break;
			}
		}
	}
	return (numbers.top());
}

const char* RPN::MismatchOperatorsNumbersException::what() const throw()
{
	return "Mismatch between the number of operators and numbers.";
}

const char *RPN::InvalidFirstElementsException::what() const throw()
{
	return "First two elements must be numbers";
}

const char *RPN::InvalidNumberException::what() const throw()
{
	return "Numbers can only be between 0 and 10";
}

RPN::InvalidCharacterException::InvalidCharacterException(char c) : ch(c) {}

RPN::InvalidCharacterException::~InvalidCharacterException() throw() {}

const char* RPN::InvalidCharacterException::what() const throw()
{
	static std::string msg = "Invalid character: ";
	msg += ch;
	return (msg.c_str());
}
