/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:08:21 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/10 16:08:21 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		int					grade;
		const std::string	name;

	public:
		Bureaucrat(const std::string n, int g);
		Bureaucrat(Bureaucrat &other);
		Bureaucrat &operator=(Bureaucrat &other);
		~Bureaucrat();

		const std::string getName( void ) const;
		int			getGrade( void ) const;

		void	increment( void );
		void	decrement( void );

		class GradeTooHighException
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException
		{
			public:
				const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &value);

#endif
