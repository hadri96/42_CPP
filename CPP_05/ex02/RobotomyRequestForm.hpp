/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:49:26 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/16 11:49:30 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(std::string n);
		RobotomyRequestForm(RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(RobotomyRequestForm &other);
		~RobotomyRequestForm();

		void actionForm( void ) const;
		void execute( Bureaucrat const &executor ) const;
};

#endif
