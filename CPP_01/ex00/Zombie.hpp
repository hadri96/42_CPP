/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:34:36 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 19:34:36 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iomanip>
# include <iostream>

class	Zombie
{
	private:
		std::string	name;
	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie();

		void	announce( void );
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
