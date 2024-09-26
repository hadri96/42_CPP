/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:37:24 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/26 17:37:31 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			PmergeMe<std::vector<int> > example(argv[1]);
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
