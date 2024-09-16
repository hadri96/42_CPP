/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:48:23 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/16 11:48:23 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string n): \
AForm(n, 5, 25) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &other): \
AForm(other) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute( Bureaucrat const &executor ) const
{
	AForm::execute(executor);
	actionForm();
}

void PresidentialPardonForm::actionForm( void ) const
{
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblerox." << std::endl;
}
