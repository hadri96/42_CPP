/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:20:11 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/10 16:20:11 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string n, int g): grade(g), name(n)
{
	if (g > 150)
		throw GradeTooLowException();
	else if (g < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat &other): grade(other.grade), name(other.name) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &other)
{
	if (this != &other)
	{
		Bureaucrat temp(other);
		std::swap(grade, temp.grade);
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName( void ) const { return (name); }
int			Bureaucrat::getGrade( void ) const { return (grade) ;}

void	Bureaucrat::increment( void )
{
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}
void	Bureaucrat::decrement( void )
{
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is higher than 1!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is lower than 150!");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &value)
{
	out << value.getName() << ", bureaucrat grade " << value.getGrade() << ".\n";
	return out;
}
