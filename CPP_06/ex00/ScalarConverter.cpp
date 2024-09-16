/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:37:52 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/16 19:44:08 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter &other) { (void) other; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
	(void) other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(char *value)
{
	double	converted;
	bool	is_num;

	converted = std::atof(value);
	is_num = is_number(value);
	if (static_cast <int> (converted) != converted)
		std::cout << "char : impossible" << std::endl;
	else if (converted < 32 || converted > 126)
		std::cout << "char : non displayable" << std::endl;
	else
		std::cout << "char : " << static_cast <char> (converted) << std::endl;
	if (is_number(value) && (converted < INT_MIN || converted > INT_MAX || (converted != 0 && !std::atoi(value))))
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "int : " << static_cast<int> (converted) << std::endl;
	if (converted == static_cast <int> (converted))
		std::cout << std::fixed << std::setprecision(1);
	if (is_num && (converted < FLT_MIN || converted > FLT_MAX))
		std::cout << "int : impossible" << std::endl;
	else
		std::cout << "float : " << static_cast<float>(converted) << "f" << std::endl;
	if (!is_num)
		std::cout << "double : impossible" << std::endl;
	else
		std::cout << "double : " << converted << std::endl;
}
