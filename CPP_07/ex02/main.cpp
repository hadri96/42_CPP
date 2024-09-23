/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:51:44 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/23 11:52:50 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> void print(T elem)
{
	std::cout << elem << std::endl;
}

#include <iostream>
#include "Array.hpp"  // Assuming your class is in a file named Array.hpp

int main()
{
	try
	{
		std::cout << "Testing default constructor:\n";
		Array<int> arr1;
		std::cout << "Array size: " << arr1.size() << "\n\n";

		std::cout << "Testing constructor with size:\n";
		Array<int> arr2(5);
		std::cout << "Array size: " << arr2.size() << "\n";

		std::cout << "Assigning values to arr2:\n";
		for (unsigned long i = 0; i < arr2.size(); ++i)
			arr2[i] = i * 10;
		std::cout << "Accessing elements of arr2:\n";
		for (unsigned long i = 0; i < arr2.size(); ++i)
			std::cout << "arr2[" << i << "] = " << arr2[i] << "\n";
		std::cout << "\n";

		std::cout << "Testing copy constructor:\n";
		Array<int> arr3 = arr2;
		std::cout << "Array size of arr3 (copy of arr2): " << arr3.size() << "\n";

		std::cout << "Accessing elements of arr3:\n";
		for (unsigned long i = 0; i < arr3.size(); ++i)
			std::cout << "arr3[" << i << "] = " << arr3[i] << "\n";
		std::cout << "\n";

		std::cout << "Testing assignment operator:\n";
		Array<int> arr4(3);
		arr4 = arr2;
		std::cout << "Array size of arr4 after assignment: " << arr4.size() << "\n";


		std::cout << "Accessing elements of arr4:\n";
		for (unsigned long i = 0; i < arr4.size(); ++i)
			std::cout << "arr4[" << i << "] = " << arr4[i] << "\n";
		std::cout << "\n";

		std::cout << "Testing out-of-bounds index access (should throw exception):\n";
		std::cout << arr2[10] << "\n";

	}
	catch (const Array<int>::MemoryAllocationFailure &e)
	{
		std::cerr << "Exception caught: " << e.what() << "\n";
	}
	catch (const Array<int>::IndexError &e)
	{
		std::cerr << "Exception caught: " << e.what() << "\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected exception: " << e.what() << "\n";
	}
	return (0);
}

