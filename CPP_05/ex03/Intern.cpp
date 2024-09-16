/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:56:13 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/16 14:58:14 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

unsigned int hashString(const std::string& str)
{
	unsigned int hash = 0;
	for(int i =0; str[i]; i++)
		hash = hash * 101 + str[i];
	return (hash);
}

Intern::Intern() {}

Intern::Intern(Intern &other) { (void) other;}

Intern &Intern::operator=(Intern &other)
{
	(void) other;
	return (*this);
}

Intern::~Intern() {}

const char *Intern::InexistingFormException::what() const throw()
{
	return ("form doesn't exist");
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	AForm *instance = NULL;
	switch (hashString(form))
	{
		case 0x273E554C:
			instance = new RobotomyRequestForm(target);
			return (instance);
		case 0x5DE74FCB:
			instance = new ShrubberyCreationForm(target);
			return (instance);
		case 0x47CA685C:
			instance = new PresidentialPardonForm(target);
			return (instance);
		default:
			throw InexistingFormException();
	}
	return (instance);
}
