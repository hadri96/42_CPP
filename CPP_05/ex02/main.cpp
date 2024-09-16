/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:52:15 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/16 13:55:39 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "unistd.h"

int main(void)
{
	Bureaucrat bureaucrat1("John", 5);
	std::cout << bureaucrat1 << std::endl;

	try
	{
		Bureaucrat bureaucrat2("Alice", 151);
		std::cout << "Bureaucrat created successfully!" << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Error creating Bureaucrat: " << e.what() << std::endl;
	}
	Bureaucrat bureaucrat3("Bob", 4);
	std::cout << bureaucrat3 << std::endl;
	ShrubberyCreationForm form1("Boring");
	std::cout << form1 << std::endl;
	bureaucrat3.signForm(form1);
	try
	{
		bureaucrat3.signForm(form1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	bureaucrat3.executeForm(form1);
	RobotomyRequestForm form2("Anton");
	std::cout << form2 << std::endl;
	for (int i = 0; i < 10; i++)
		bureaucrat3.executeForm(form2);
	PresidentialPardonForm form3("Donald");
	std::cout << form3 << std::endl;
	bureaucrat3.executeForm(form3);
	return (0);
}
