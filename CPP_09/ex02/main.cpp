/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:43:38 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/27 15:43:56 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		try
		{
			PmergeMe<std::vector<int> > example(argv);

			std::cout << example << "\n\n";
			std::vector<int> arr = example.getNumbers();
			std::vector<int> sorted = example.merge_insert(arr);
			for (std::vector<int>::const_iterator	it = sorted.begin(); it != sorted.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl << "Time to process\n----------------" << std::endl;
			display_times(argv);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return (1);
	}
	return (0);
}
