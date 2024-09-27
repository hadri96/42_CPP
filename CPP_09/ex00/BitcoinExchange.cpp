/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:12:25 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/27 13:17:36 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	is_num(std::string num)
{
	int	dots = 0;

	for (int i = 0; num[i]; i++)
	{
		if (num[i] == '.')
			dots++;
		if (dots > 1 || (!std::isdigit(num[i]) && num[i] != '.'))
			throw BitcoinExchange::InvalidAmount(num);
	}
}
bool t_date::operator<(const s_date &other) const
{
	if (date.tm_year != other.date.tm_year)
		return date.tm_year < other.date.tm_year;
	if (date.tm_mon != other.date.tm_mon)
		return date.tm_mon < other.date.tm_mon;
	return date.tm_mday < other.date.tm_mday;
}

std::ostream &operator<<(std::ostream &out, const t_date &d)
{
	out << d.date.tm_mday << "-" << d.date.tm_mon + 1 << "-" << d.date.tm_year + 1900;
	return (out);
}

void	is_date(std::string date, std::tm *date_obj)
{
	std::memset(date_obj, 0, sizeof(std::tm));
	std::istringstream ss(date);
	ss >> std::get_time(date_obj, "%Y-%m-%d");
	if (ss.fail())
		throw BitcoinExchange::InvalidDate(date);
}

bool	is_leap_year(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void	valid_date(t_date date)
{
	int m = date.date.tm_mon + 1, d = date.date.tm_mday, y = date.date.tm_year + 1900;
	bool	leap;

	leap = is_leap_year(y);
	if (((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		|| (m == 2 && leap && d > 29) || (m == 2 && !leap && d > 28))
		throw BitcoinExchange::InvalidDate(date.date_string);
}

std::istream &secure_getline(std::istream &stream,
		std::string &s, std::ptrdiff_t const buf_size, char const delimiter = '\n')
{
	const std::ptrdiff_t MAX_BUF_SIZE = 1024 * 1024;
	if (buf_size <= 1 || buf_size > MAX_BUF_SIZE)
	{
		stream.setstate(std::ios::failbit);
		return (stream);
	}
	if (!stream.good())
		return (stream);
	s.resize(buf_size);
	stream.getline(&s[0], buf_size, delimiter);
	if (stream.fail() && !stream.eof())
		return (stream);
	std::ptrdiff_t const n = std::char_traits<char>::length(&s[0]);
	s.resize(n);
	return (stream);
}

void	BitcoinExchange::load_file( std::string f )
{
	std::ifstream *check;

	if (f == "data.csv")
	{
		this->db.open("data.csv");
		check = &this->db;
	}
	else
	{
		this->file.open(f);
		check = &this->file;
	}
	if (!check->good())
		throw BitcoinExchange::InexistingFileException();
	if (!check->is_open())
		throw BitcoinExchange::NoPermissionException();
}

void	BitcoinExchange::check_header(std::ifstream &f, std::string sep, std::string value )
{
	std::string	line;
	if (secure_getline(f, line, 300, '\n'))
	{
		if (line.substr(0, line.find(sep)) != "date"
			|| line.substr(line.find(sep) + sep.length(), line.rfind('e')) != value)
			throw BitcoinExchange::BadHeaderException();
	}
	else
	{
		if (f.eof())
			throw BitcoinExchange::EndOfFileException();
		if (f.fail())
			throw BitcoinExchange::BadReadException();
	}
}

double	BitcoinExchange::parse_line(std::ifstream &f, std::string sep, t_date *date, double limit)
{
	std::string	line;

	(void) limit;
	if (secure_getline(f, line, 300, '\n'))
	{
		if (line.find(sep) == std::string::npos)
			throw InvalidFormat(line);
		std::string date_string = line.substr(0, line.find(sep));
		std::string num = line.substr(line.find(sep) + sep.length(), line.length() - 1);
		is_num(num);
		is_date(date_string, &date->date);
		date->date_string = date_string;
		valid_date(*date);
		double number = std::atof(num.c_str());
		if (number > limit || number < 0)
			throw InvalidAmount(num);
		return (number);
	}
	else
	{
		if (f.eof())
			throw BitcoinExchange::EndOfFileException();
		if (f.fail())
			throw BitcoinExchange::BadReadException();
		return (0);
	}
	return (0);
}

BitcoinExchange::BitcoinExchange( void )
{
	double	value;
	t_date	date;
	try
	{
		load_file("data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw std::exception();
	}
	try
	{
		check_header(db, ",", "exchange_rate");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		throw std::exception();
	}
	while (1)
	{
		try
		{
			value = parse_line(db, ",", &date);
			values[date] = value;
		}
		catch (const EndOfFileException &e)
		{
			break ;
		}
		catch (const DataException &e2)
		{
			std::cerr << e2.what() << '\n';
		}
	}
	db.close();
}

void	BitcoinExchange::convert(std::string filename)
{
	t_date	date;
	double	value;

	try
	{
		load_file(filename);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return;
	}
	try
	{
		check_header(file, " | ", "value");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	while (1)
	{
		try
		{
			value = parse_line(file, " | ", &date, 1000);
			if (values.count(date))
				std::cout << date.date_string << " => " << value << " = " << value * values[date] << std::endl;
			else if (values.rbegin()->first < date || date < values.begin()->first)
				throw DateOutOfRange(date.date_string);
			else
				std::cout << date.date_string << " => " << value << " = "
				<< value * values.lower_bound(date)->second << std::endl;
		}
		catch (const EndOfFileException &e)
		{
			break;
		}
		catch (const DataException &e2)
		{
			std::cerr << e2.what() << '\n';
		}
	}
	file.close();
}

BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(BitcoinExchange &other): values(std::map<t_date, double>(other.values))
{}
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &other)
{
	if (this != &other)
		values = other.values;
	return (*this);

}

const char *BitcoinExchange::FileException::what() const throw()
{
	return "Issue with file";
}
BitcoinExchange::FileException::~FileException() throw () {}

const char* BitcoinExchange::InexistingFileException::what() const throw()
{
	return "FileException: File does not exist.";
}

const char* BitcoinExchange::NoPermissionException::what() const throw()
{
	return "FileException: No permission to open file.";
}

const char* BitcoinExchange::BadReadException::what() const throw()
{
	return "FileException: Error reading file.";
}

const char* BitcoinExchange::EndOfFileException::what() const throw()
{
	return "FileException: Unexpected end of file.";
}

const char* BitcoinExchange::BadHeaderException::what() const throw()
{
	return "FileException: Bad/missing header in file.";
}

const char *BitcoinExchange::DataException::what() const throw()
{
	return "Issue with data";
}
BitcoinExchange::DataException::~DataException() throw() {}

BitcoinExchange::InvalidFormat::~InvalidFormat() throw() {}

BitcoinExchange::InvalidFormat::InvalidFormat(std::string m) : message(m) {}

const char* BitcoinExchange::InvalidFormat::what() const throw()
{
	static std::string error_message;
	error_message = "DataException: Invalid format => " + message;
	return error_message.c_str();
}

BitcoinExchange::InvalidDate::~InvalidDate() throw() {}

BitcoinExchange::InvalidDate::InvalidDate(std::string m) : message(m) {}

const char* BitcoinExchange::InvalidDate::what() const throw()
{
	static std::string error_message;
	error_message = "DataException: Invalid date => " + message;
	return error_message.c_str();
}

BitcoinExchange::InvalidAmount::~InvalidAmount() throw() {}

BitcoinExchange::InvalidAmount::InvalidAmount(std::string m) : message(m) {}

const char* BitcoinExchange::InvalidAmount::what() const throw()
{
	static std::string error_message;
	error_message = "DataException: Invalid amount => " + message;
	return error_message.c_str();
}

BitcoinExchange::DateOutOfRange::~DateOutOfRange() throw() {}

BitcoinExchange::DateOutOfRange::DateOutOfRange(std::string m) : message(m) {}

const char *BitcoinExchange::DateOutOfRange::what() const throw()
{
	static std::string error_message;
	error_message = "DataException: Date out of range => " + message;
	return error_message.c_str();
}
