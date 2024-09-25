/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:01:03 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/25 21:01:31 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			RPN example(argv[1]);
			std::cout << example.sum() << std::endl;
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
