/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:11:25 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/24 17:11:51 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <string.h>

class BitcoinExchange
{
	private:
		std::string						filename;
		std::ifstream					file;
		std::map<std::string, double>	values;

		void	load_file( void );
	public:
		BitcoinExchange(std::string file);
		BitcoinExchange(BitcoinExchange &other);
		BitcoinExchange &operator=(BitcoinExchange &other);
		~BitcoinExchange();

		class FileException: public std::exception
		{
			public:
				class	WrongHeaderException: public std::exception
				{
					const char *what() const throw();
				};

				class InexistingFileException: public std::exception
				{
					const char *what() const throw();
				};

				class NoPermissionException: public std::exception
				{
					const char *what() const throw();
				};
		};

};

#endif
