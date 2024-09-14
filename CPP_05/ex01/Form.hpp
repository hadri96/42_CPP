/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:28:27 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/14 17:28:50 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		const int			to_execute, to_sign;
		bool				is_signed;
		const std::string	name;

	public:
		Form(const std::string n, const int ex, const int sign);
		Form(Form &other);
		Form &operator=(Form &other);
		~Form();

		int			getToExecute( void ) const;
		int			getToSign( void ) const;
		std::string	getName( void ) const;
		bool				getIsSigned( void ) const;

		void	beSigned(Bureaucrat &b);

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw();
		};

		class AlreadySignedException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
