/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:18:28 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/10 16:19:39 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat bureaucrat1("John", 5);
	std::cout << bureaucrat1;

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
	std::cout << bureaucrat3;
	bureaucrat3.increment();
	std::cout << bureaucrat3 << "Grade incremented successfully!" << std::endl;
	bureaucrat3.decrement();
	std::cout << bureaucrat3 << "Grade decremented successfully!" << std::endl;

	try
	{
		Bureaucrat bureaucrat4("Eve", 1);
		bureaucrat4.increment();
		std::cout << bureaucrat4 << "Grade incremented successfully!" << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Error incrementing grade: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bureaucrat5("Adam", 150);
		bureaucrat5.decrement();
		std::cout << bureaucrat5 << "Grade decremented successfully!" << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Error decrementing grade: " << e.what() << std::endl;
	}

	return (0);
}
