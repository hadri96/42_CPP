/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:49:48 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/16 11:49:48 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
	private:
		const int			to_execute, to_sign;
		bool				is_signed;
		const std::string	name;

	public:
		AForm(const std::string n, const int ex, const int sign);
		AForm(AForm &other);
		AForm &operator=(AForm &other);
		~AForm();

		int		getToExecute( void ) const;
		int			getToSign( void ) const;
		std::string	getName( void ) const;
		bool				getIsSigned( void ) const;

		void			beSigned(Bureaucrat &b);
		void virtual	execute(Bureaucrat const &executor) const;
		void virtual	actionForm( void ) const = 0;

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

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
