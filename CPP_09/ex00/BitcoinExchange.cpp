/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:11:11 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/24 17:11:18 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	BitcoinExchange::load_file( void )
{
	file = std::ifstream(filename);
	if (!file.good())
		throw BitcoinExchange::FileException::InexistingFileException();
	if (!file.is_open())
		throw BitcoinExchange::FileException::NoPermissionException();
}




