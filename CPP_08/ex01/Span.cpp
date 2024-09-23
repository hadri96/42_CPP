/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:41:49 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/23 14:42:55 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n): N(n), contains(0) { values.reserve(N); }

Span::Span(const Span &other): N(other.N), contains(other.contains), values(other.values) {}

Span &Span::operator=(Span &other)
{
	if (this != &other)
	{
		N = other.N;
		contains = other.contains;
		values = std::vector<int>(other.values);
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n)
{
	if (contains == N)
		throw NoSpaceError();
	std::vector<int>::iterator it = std::lower_bound(values.begin(), values.end(), n);
	values.insert(it, n);
	contains++;
}
void	Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	if (std::distance(start, end) > N - contains)
		throw NoSpaceError();
	else
	{
		for (std::vector<int>::iterator it2 = start; it2 != end; ++it2)
		{
			std::vector<int>::iterator it = std::lower_bound(values.begin(), values.end(), *it2);
			values.insert(it, *it2);
			contains++;
		}
	}
}

int		Span::shortestSpan( void )
{
	if (contains < 2)
		throw NoNumberError();
	int min = *(values.end() - 1) - *(values.begin());
	for (std::vector<int>::iterator it = values.begin(); it != values.end() - 1; ++it)
	{
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	}
	return (min);
}
int		Span::longestSpan( void )
{
	if (contains < 2)
		throw NoNumberError();
	int max = *(values.end() - 1) - *(values.begin());
	for (std::vector<int>::iterator it = values.begin(); it != values.end() - 1; ++it)
	{
		if (*(it + 1) - *it > max)
			max = *(it + 1) - *it;
	}
	return (max);
}

const char *Span::NoNumberError::what() const throw()
{
	return ("A minimum of two numbers must be in the object to calculate a Span");
}

const char *Span::NoSpaceError::what() const throw()
{
	return ("Insufficient space in this vector");
}
