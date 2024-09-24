/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:36:09 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/23 13:39:19 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	for (int i = 1; i < 6; i += 1)
		vec.push_back(i);
	std::cout << "Test with std::vector: " << ::easyfind(vec, 3) << "\n";  // Should return 3

	try
	{
		std::cout << "Test with std::vector (not found): " << ::easyfind(vec, 6) << "\n";  // Should throw ValueNotFound
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << "\n";
	}

	std::deque<int> deq;
	for (int i = 10; i < 60; i += 10)
		deq.push_back(i);
	std::cout << "Test with std::deque: " << ::easyfind(deq, 20) << "\n";  // Should return 20
	try
	{
		std::cout << "Test with std::deque (not found): " << ::easyfind(deq, 60) << "\n";  // Should throw ValueNotFound
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	std::list<int> lst;
	for (int i = 100; i < 600; i += 100)
		lst.push_back(i);
	std::cout << "Test with std::list: " << ::easyfind(lst, 300) << "\n";
	try
	{
		std::cout << "Test with std::list (not found): " << ::easyfind(lst, 600) << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}

	std::array<int, 5> arr = {7, 8, 9, 10, 11};
	std::cout << "Test with std::array: " << ::easyfind(arr, 9) << "\n";
	try
	{
		std::cout << "Test with std::array (not found): " << ::easyfind(arr, 12) << "\n";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << "\n";
	}
	return 0;
}
