/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:26:40 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/02 14:13:00 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	funcs[0] = (t_function_map){ "DEBUG", &Harl::debug };
	funcs[1] = (t_function_map){ "INFO", &Harl::info };
	funcs[2] = (t_function_map){ "WARNING", &Harl::warning };
	funcs[3] = (t_function_map){ "ERROR", &Harl::error };
}

Harl::~Harl() {}

void	Harl::complain( std::string name )
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (!name.compare(funcs[i].name))
			break ;
	}
	switch (i)
	{
		case (0):
		{
			debug();
			info();
			warning();
			error();
			break ;
		}
		case (1):
		{
			info();
			warning();
			error();
			break ;
		}
		case (2):
		{
			warning();
			error();
			break ;
		}
		case (3):
		{
			error();
			break ;
		}
		default:
			undefined();

	}
}

void	Harl::debug( void )
{
	std::cout << BOLD_GREEN "[DEBUG]" << std::endl
			  << BOLD_WHITE "I love having extra bacon for my\n\
7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n" RESET << std::endl;
}

void	Harl::info( void )
{
	std::cout << BOLD_YELLOW "[INFO]" << std::endl
			  << BOLD_WHITE "I cannot believe adding extra bacon costs more money.\n\
You didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!\n" RESET << std::endl;
}

void	Harl::warning( void )
{
	std::cout << BOLD_ORANGE "[WARNING]" << std::endl
			  << BOLD_WHITE "I think I deserve to have some extra bacon for free.\n\
I've been coming for years whereas you started working here since last month.\n" RESET << std::endl;
}

void	Harl::error( void )
{
	std::cout << BOLD_RED "[ERROR]" << std::endl
			  << BOLD_WHITE "This is unacceptable!\n\
I want to speak to the manager now!" RESET << std::endl;
}

void Harl::undefined(void)
{
	std::cout << BOLD_WHITE "[ Probably complaining about \
 insignificant problems ]" RESET
			  << std::endl;
}
