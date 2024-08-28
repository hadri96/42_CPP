/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:54:06 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/28 14:54:41 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	Harl	harl;

	std::string	level(argv[1]);

	harl.complain(level);
}
