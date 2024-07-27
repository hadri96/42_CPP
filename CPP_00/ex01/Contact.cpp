/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:21:02 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 15:21:02 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(std::string fields[5], int i)
{
	first_name = fields[0];
	last_name = fields[1];
	nickname = fields[2];
	darkest = fields[3];
	number = fields[4];
	index = i;
}

Contact::~Contact() {}

void	Contact::decrement()
{
	index--;
}

void Contact::truncated_display() const
{
	std::cout << "|" << index << std::string(9, ' ')
			  << "|" << truncate_field(first_name)
			  << "|" << truncate_field(last_name)
			  << "|" << truncate_field(nickname) << "|" << std::endl;
}

void	Contact::display() const
{
	std::cout << "First name:\t" << first_name << std::endl
			  << "Last name:\t" << last_name << std::endl
			  << "Nickname:\t" << nickname << std::endl
			  << "Phone number:\t" << number << std::endl
			  << "Darkest secret:\t" << darkest << std::endl;
}
