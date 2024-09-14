/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:25:17 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/14 17:25:17 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string na, const int ex, const int sign): \
to_execute(ex), to_sign(sign), is_signed(false), name(na)
{
	if (to_execute < 1)
		throw GradeTooHighException();
	else if (to_execute > 150)
		throw GradeTooLowException();
	else if (to_sign < 1)
		throw GradeTooHighException();
	else if (to_sign > 150)
		throw GradeTooLowException();
}

Form::Form(Form &other): \
to_execute(other.to_execute), to_sign(other.to_sign), is_signed(other.is_signed), name(other.name) {}

Form &Form::operator=(Form &other)
{
	if (this != &other)
		is_signed = other.is_signed;
	return (*this);
}

Form::~Form() {}

int			Form::getToExecute( void ) const { return (to_execute); }
int			Form::getToSign( void ) const { return (to_sign); }
bool		Form::getIsSigned( void ) const { return (is_signed); }
std::string	Form::getName( void ) const { return (name); }

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << f.getName() << ", to execute: " << f.getToExecute()
		<< ", to sign: " << f.getToSign();
	return (out);
}

void Form::beSigned(Bureaucrat &b)
{
	if (is_signed)
		throw AlreadySignedException();
	if (to_sign < b.getGrade())
		throw GradeTooLowException();
	is_signed = true;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("the grade entered is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("the grade entered is too low!");
}

const char *Form::AlreadySignedException::what() const throw()
{
	return ("the form is already signed!");
}

