/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:37:12 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/26 17:37:12 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define THRESHOLD 16
# include <vector>
# include <deque>
# include <iostream>
# include <string>

bool	is_positive_integer(std::string str);

template <typename T>
class PmergeMe
{
	private:
		T	numbers;
	public:
		PmergeMe(std::string num_string)
		{
			std::string 	num;
			unsigned long	next_space, len;

			next_space = num_string.find(' ');
			while (next_space != std::string::npos || num_string[0])
			{
				len = num_string.length();
				if (num_string.find(' ') == std::string::npos)
				{
					num = num_string.substr(0, len);
					num_string = num_string.substr(len, 2);
				}
				else
				{
					num = num_string.substr(0, next_space);
					num_string = num_string.substr(next_space + 1, len - 1);
				}
				next_space = num_string.find(' ');
				if (is_positive_integer(num))
					numbers.push_back(std::atoi(num.c_str()));
				else
					throw InvalidValueException(num);
				std::cout << num << std::endl;
			}
		}
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe() {}

		T	merge (T right, T left);
		T	insertion_binary_search(T numbers, int to_ins);
		T	merge_insert( T numbers );

		class InvalidValueException : public std::exception
		{
			private:
				std::string message;
			public:
				virtual ~InvalidValueException() throw() {}
				InvalidValueException(std::string value): message(value) {}
				const char *what() const throw()
				{
					static std::string error_message;
					error_message = "Invalid value: Please only enter positive integers => " + message;
					return error_message.c_str();
				}
		};


};

#endif
