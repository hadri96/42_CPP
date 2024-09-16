/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:19:59 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/16 19:20:19 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	is_number(char * string)
{
	int		i = 0, dot = 0;
	double	num;

	num = std::atof(string);
	if (num != 0)
		return (true);
	while (string[i] && (string[i] == '0' || string[i] == '.'))
	{
		if (string[i] == '.')
			dot++;
		i++;
	}
	if (dot < 2 && (!string[i] || (string[i] == 'f' && !string[i + 1])))
		return (true);
	return (false);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of parameters!" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
