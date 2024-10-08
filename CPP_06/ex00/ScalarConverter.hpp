/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:03:02 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/17 12:03:04 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <cfloat>
# include <limits.h>
# include <iomanip>

bool	is_number(char *string);

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &other);
		ScalarConverter &operator=(ScalarConverter &other);
		~ScalarConverter();
	public:
		static void	convert(char *value);
};

#endif
