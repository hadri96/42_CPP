/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:25:41 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 15:37:50 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	size = 0;
}

PhoneBook::~PhoneBook() {}

bool PhoneBook::valid_number(const std::string number) const
{
	if (number.empty() || (number[0] != '+' && !std::isdigit(number[0])))
		return (false);
	for (int i = 0; number[i]; i++)
	{
		if (i == 0 && number[i] == '+')
			continue ;
		if (!std::isdigit(number[i]))
			return (false);
	}
	return (true);
}

void	PhoneBook::search() const
{
	std::string	index;

	if (size == 0)
	{
		std::cout << "There are no contacts in the phonebook, please create a contact before doing a search" << std::endl;
		return ;
	}
	std::cout << "o" << std::string(43, '-') << "o" << std::endl
			  << "|Index     |First name|Last name |Nickname  |" << std::endl
			  << "o" << std::string(43, '-') << "o" << std::endl;
	for(int i = 0; i < size; i++)
		contacts[i].truncated_display();
	std::cout << "o" << std::string(43, '-') << "o" << std::endl;
	std::cout << "Please enter the index of the relevant contact: ";

	std::getline(std::cin, index);
	if (std::cin.eof())
		return;
	while (index.empty() || index.size() > 1 || !std::isdigit(index[0]) || std::stoi(index) > size - 1 || std::stoi(index) < -1)
	{
		std::cout << "Invalid index, please enter a valid choice!" << std::endl;
		std::cout << "Please enter the index of the relevant contact: ";
		std::getline(std::cin, index);
		if (std::cin.eof())
			return;
	}
	contacts[std::stoi(index)].display();
}

void	PhoneBook::add_contact()
{
	std::string	input;
	std::string	fields[5];
	int			index;

	if (size == 8)
		index = 0;
	else
		index = size++;
	std::cout << "o " << std::string(49, '-') << " o" << std::endl;
	std::cout << "First Name:\t";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return;
	while (input.empty())
	{
		std::cout << "Invalid input, please enter a valid value!" << std::endl;
		std::cout << "First Name:\t";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return;
	}
	fields[0] = input;

	std::cout << "Last Name:\t";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return;
	while (input.empty())
	{
		std::cout << "Invalid input, please enter a valid value!" << std::endl;
		std::cout << "Last Name:\t";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return;
	}
	fields[1] = input;

	std::cout << "Nickname:\t";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return;
	while (input.empty())
	{
		std::cout << "Invalid input, please enter a valid value!" << std::endl;
		std::cout << "Nickname:\t";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return;
	}
	fields[2] = input;

	std::cout << "Darkest secret:\t";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return;
	while (input.empty())
	{
		std::cout << "Invalid input, please enter a valid value!" << std::endl;
		std::cout << "Darkest secret:\t";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return;
	}
	fields[3] = input;

	std::cout << "Phone number (no spaces allowed):\t";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return;
	while (!valid_number(input))
	{
		std::cout << "Invalid input, please enter a valid value!" << std::endl;
		std::cout << "Phone number (no spaces allowed):\t";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return;
	}
	fields[4] = input;
	contacts[index] = Contact(fields, index);
}

void	PhoneBook::run()
{
	std::string	input;

	std::cout << "Welcome to the 80s Phonebook!" << std::endl;
	while (true)
	{
		std::cout << "Please enter the action of your choice (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		else if (!input.compare("EXIT"))
			break ;
		else if (!input.compare("ADD"))
			add_contact();
		else if (!input.compare("SEARCH"))
			search();
		else
			std::cout << "Invalid command, please try again!" << std::endl;
	}
	return ;
}

int	main(void)
{
	PhoneBook	book;

	book = PhoneBook();
	book.run();
	return 0;
}
