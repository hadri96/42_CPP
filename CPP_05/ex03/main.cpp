/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:00:04 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/16 15:01:30 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm	*rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << *rrf << std::endl;

	Bureaucrat tim("Tim", 20);
	tim.executeForm(*rrf);
	delete rrf;
	try
	{
		rrf = someRandomIntern.makeForm("inexisting", "hello");
	}
	catch(const std::exception& e)
	{
		std::cerr <<"Form can't be created because " << e.what() << '\n';
	}

}

