/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:08:40 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/25 17:23:13 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <sstream>
# include <iostream>
# include <map>
# include <string>
# include <cstddef>
# include <ctime>

void	is_num(std::string num);

typedef struct s_date
{
	std::tm date;
	std::string date_string;
	bool operator<(const s_date &other) const;
}	t_date;

std::ostream &operator<<(std::ostream &out, const t_date &d);

class BitcoinExchange
{
	private:
		std::ifstream					db;
		std::ifstream					file;
		std::map<t_date, double>		values;

		void	load_file( std::string f );
		void	check_header(std::ifstream &f, std::string sep, std::string value);
		double	parse_line(std::ifstream &f, std::string sep, t_date *date, double limit = INT_MAX);
	public:
		BitcoinExchange( void );
		BitcoinExchange(BitcoinExchange &other);
		BitcoinExchange &operator=(BitcoinExchange &other);
		~BitcoinExchange();

		void	convert(std::string filename);

		class FileException: public std::exception
		{
			public:
				const char *what() const throw();
				~FileException() throw();

		};

		class InexistingFileException: public FileException
		{
			public:
				const char *what() const throw();
		};

		class NoPermissionException: public FileException
		{
			public:
				const char *what() const throw();
		};

		class BadReadException: public FileException
		{
			public:
				const char *what() const throw();
		};

		class EndOfFileException: public FileException
		{
			public:
				const char *what() const throw();
		};

		class BadHeaderException: public FileException
		{
			public:
				const char *what() const throw();
		};

		class DataException: public std::exception
		{

			public:
				virtual ~DataException() throw();
				virtual const char *what() const throw();
		};
		class InvalidFormat : public DataException
		{
			private:
				std::string	message;
			public:
				virtual ~InvalidFormat() throw();
				InvalidFormat(std::string m);
				const char *what() const throw();
		};

		class InvalidDate: public DataException
		{
			private:
				std::string message;

			public:
				virtual ~InvalidDate() throw();
				InvalidDate(std::string m);
				const char *what() const throw();
		};

		class InvalidAmount: public DataException
		{
			private:
				std::string message;

			public:
				virtual ~InvalidAmount() throw();
				InvalidAmount(std::string m);
				const char *what() const throw();
		};

		class DateOutOfRange: public DataException
		{
			private:
				std::string message;

			public:
				virtual ~DateOutOfRange() throw();
				DateOutOfRange(std::string m);
				const char *what() const throw();
		};

};

#endif
