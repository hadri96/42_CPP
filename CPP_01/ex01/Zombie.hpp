/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:00:02 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 20:00:02 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iomanip>
# include <iostream>
# include <new>

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
Zombie	*zombieHorde(int N, std::string name);

#endif
