/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:47:59 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/27 15:57:46 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define THRESHOLD 32
# include <vector>
# include <deque>
# include <iostream>
# include <string>

bool	is_positive_integer(char *str);
void	display_times(char **args);

template <typename T>
class PmergeMe
{
	private:
		T	numbers;

		int	binary_insert_pos(T &array, int i, int arr_len)
		{
			int start = 0;
			int end = arr_len;

			while (start < end)
			{
				int mid = start + (end - start) / 2;
				if (array[mid] < i)
					start = mid + 1;
				else
					end = mid;
			}
			return start;
		}

	public:
		PmergeMe(char **nums)
		{
			int	i = 0;
			while (nums[++i])
			{
				if (is_positive_integer(nums[i]))
					numbers.push_back(std::atoi(nums[i]));
				else
					throw InvalidValueException(nums[i]);
			}
		}
		PmergeMe(const PmergeMe &other): numbers (T(other.numbers)) {}
		PmergeMe &operator=(const PmergeMe &other)
		{
			if (this != &other)
				numbers = other.numbers;
			return (*this);
		}

		~PmergeMe() {}

		T	merge (T &right, T &left)
		{
			typename T::const_iterator	it_right = right.begin(), it_left = left.begin();
			T					result;

			while (it_right != right.end() && it_left != left.end())
			{
				if (*it_right < *it_left)
				{
					result.push_back(*it_right);
					++it_right;
				}
				else
				{
					result.push_back(*it_left);
					++it_left;
				}
			}
			while (it_right != right.end())
			{
				result.push_back(*it_right);
				++it_right;
			}
			while (it_left != left.end())
			{
				result.push_back(*it_left);
				++it_left;
			}
			return (result);
		}

		T	insertion_binary_sort(T &array)
		{
			T result;
			if (array.empty())
				return result;

			result.push_back(array[0]);

			for (size_t i = 1; i < array.size(); ++i)
			{
				int pos = binary_insert_pos(result, array[i], result.size());
				result.insert(result.begin() + pos, array[i]);
			}
			return result;
		}

		T merge_insert(T &array)
		{
			T result;

			if (array.size() < THRESHOLD)
				result = insertion_binary_sort(array);
			else
			{
				int half = array.size() / 2;
				T left(array.begin(), array.begin() + half);
				T right(array.begin() + half, array.end());
				T sorted_left = merge_insert(left);
				T sorted_right = merge_insert(right);
				result = merge(sorted_left, sorted_right);
			}
			return result;
		}

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

		T getNumbers( void ) const { return numbers; }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const PmergeMe<T> &array)
{
	T numbers = array.getNumbers();

	for (typename T::const_iterator	it = numbers.begin(); it != numbers.end(); ++it)
		out << *it << " ";
	out << std::endl;
	return (out);
}

#endif
