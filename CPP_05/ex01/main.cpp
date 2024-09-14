/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:25:38 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/14 17:27:44 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	Bureaucrat bureaucrat3("Bob", 10);
	std::cout << bureaucrat3 << std::endl;
	Form form1("Boring", 10, 20);
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
	Form form2("More boring", 5, 5);
	std::cout << form2 << std::endl;
	try
	{
		bureaucrat3.signForm(form2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Form form3("Dead", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Form can't be created because "<< e.what() << '\n';
	}

	try
	{
		Form form3("Dead", 151, 1);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Form can't be created because " << e.what() << '\n';
	}

	return (0);
}
