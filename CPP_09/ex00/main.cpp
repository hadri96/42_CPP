/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:41:18 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/25 17:41:46 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			BitcoinExchange().convert(argv[1]);
		}
		catch(const std::exception& e)
		{
			return (1);
		}
	}
	else
	{
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return (1);
	}
	return (0);
}
