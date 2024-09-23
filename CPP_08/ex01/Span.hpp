/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:40:00 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/23 14:41:01 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <iostream>


class Span
{
	private:
		unsigned int		N, contains;
		std::vector<int>	values;

	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(Span &other);
		~Span();

		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);

		int		shortestSpan( void );
		int		longestSpan( void );

		class NoNumberError: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class NoSpaceError: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

#endif
