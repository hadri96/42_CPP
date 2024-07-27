/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:09:42 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 12:09:42 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	to_upper(char *str)
{
	for (int i = 0; str[i]; i++)
		str[i] = std::toupper(str[i]);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			to_upper(argv[i]);
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
	return (0);
}
