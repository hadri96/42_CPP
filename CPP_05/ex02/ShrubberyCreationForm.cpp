/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:06:53 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/16 12:07:22 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string n): \
AForm(n, 137, 145) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other): \
AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const
{
	AForm::execute(executor);
	actionForm();
}

void ShrubberyCreationForm::actionForm( void ) const
{
	std::string outfilename(this->getName());
	outfilename += "_shrubbery";
	std::ofstream outfile(outfilename.c_str());
	if (!outfile.is_open())
	{
		std::cout << "Unable to write the file "<< outfilename;
	}
	outfile << "               ,@@@@@@@," << std::endl
			<< "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
			<< "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
			<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
			<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
			<< "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
			<< "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
			<< "       |o|        | |         | |" << std::endl
			<< "       |.|        | |         | |" << std::endl
			<< "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

	outfile.close();
}
