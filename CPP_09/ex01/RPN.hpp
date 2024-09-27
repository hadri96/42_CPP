/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:43:13 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/27 17:43:23 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <cstring>
# include <iostream>
# include <exception>



class RPN
{
	private:
		std::stack<int>	numbers;
		std::string		ops, numbers_string, input;

		int count_ops(std::string args);
		int count_numbers(std::string args);

	public:
		RPN(std::string args);
		RPN(RPN &other);
		RPN &operator=(RPN &other);
		~RPN();

		int	sum( void );

		class MismatchOperatorsNumbersException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class InvalidFirstElementsException : public std::exception
		{
		public:
			const char *what() const throw();
		};

		class InvalidNumberException : public std::exception
		{
		public:
			const char *what() const throw();
		};

		class InvalidCharacterException : public std::exception
		{
		private:
			char ch;

		public:
			virtual ~InvalidCharacterException() throw();
			InvalidCharacterException(char c);
			const char *what() const throw();
		};
};

#endif
