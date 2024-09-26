/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:25:57 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/26 17:25:57 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


bool	is_positive_integer(std::string str)
{
	for (unsigned long i = 0; i < str.length(); i ++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}
