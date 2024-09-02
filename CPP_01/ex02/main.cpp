/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:58:32 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/02 13:58:32 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

int	main(void)
{
	std::string	str;

	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Memory address of string variable: " << &str << std::endl;
	std::cout << "Memory address of pointer variable: " << &stringPTR << std::endl;
	std::cout << "Memory address of reference variable: " << &stringREF << std::endl;

	std::cout << "Value of string variable: " << str << std::endl;
	std::cout << "Value of pointer variable: " << *stringPTR << std::endl;
	std::cout << "Value of reference variable: " << stringREF << std::endl;

	return 0;
}
