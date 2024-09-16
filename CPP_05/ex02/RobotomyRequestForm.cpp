/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:49:35 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/16 13:52:09 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "sys/time.h"

RobotomyRequestForm::RobotomyRequestForm(std::string n): \
AForm(n, 45, 72) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &other): \
AForm(other) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute( Bureaucrat const &executor ) const
{
	AForm::execute(executor);
	actionForm();
}

void RobotomyRequestForm::actionForm( void ) const
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	std::srand(static_cast<unsigned int>(tv.tv_usec));
	if (rand() % 2 == 1)
		std::cout << this->getName() << " has been succesfully robotomized!" << std::endl;
	else
		std::cout << "The robotomization procedure has failed..." << std::endl;
}
