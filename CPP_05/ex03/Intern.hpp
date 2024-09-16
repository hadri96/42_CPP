/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:54:59 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/16 14:56:05 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		Intern(Intern &other);
		Intern &operator=(Intern &other);
		~Intern();

		AForm *makeForm(std::string form, std::string target);

		class InexistingFormException: public std::exception
		{
			const char *what() const throw();
		};
};

unsigned int hashString(const std::string& str);

#endif
