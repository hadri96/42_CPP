/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.json                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:50:06 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/16 15:50:15 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "regex.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of parameters!" << std::endl;
		return (1);
	}

	std::cout << std::atof(argv[1]) << std::endl;

	std::cout <<  std::atoi(argv[1]) << std::endl;
	return (0);
}
