/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:23:11 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/16 11:23:11 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string na, const int ex, const int sign): \
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

AForm::AForm(AForm &other): \
to_execute(other.to_execute), to_sign(other.to_sign), is_signed(other.is_signed), name(other.name) {}

AForm &AForm::operator=(AForm &other)
{
	if (this != &other)
		is_signed = other.is_signed;
	return (*this);
}

AForm::~AForm() {}

int			AForm::getToExecute( void ) const { return (to_execute); }
int			AForm::getToSign( void ) const { return (to_sign); }
bool		AForm::getIsSigned( void ) const { return (is_signed); }
std::string	AForm::getName( void ) const { return (name); }

std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << f.getName() << ", to execute: " << f.getToExecute()
		<< ", to sign: " << f.getToSign();
	return (out);
}

void AForm::beSigned(Bureaucrat &b)
{
	if (is_signed)
		throw AlreadySignedException();
	if (to_sign < b.getGrade())
		throw GradeTooLowException();
	is_signed = true;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("the grade entered is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("the grade entered is too low!");
}

const char *AForm::AlreadySignedException::what() const throw()
{
	return ("the form is already signed!");
}

void	AForm::execute( Bureaucrat const &executor ) const
{
	if (to_execute < executor.getGrade())
		throw GradeTooLowException();
}

