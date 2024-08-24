/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:52:48 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/23 08:52:48 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <cassert>

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	damage, health, energy;

	public:
		ClapTrap();
		ClapTrap(std::string n);
		ClapTrap(ClapTrap &other);
		~ClapTrap();

		ClapTrap	&operator=(const ClapTrap &other);

		void	setDamage(unsigned int value);
		void	setHealth(unsigned int value);
		void	setEnergy(unsigned int value);
		void	setName(std::string n);

		unsigned int	getDamage(void) const;
		unsigned int	getHealth(void) const;
		unsigned int	getEnergy(void) const;
		std::string		getName(void) const;

		virtual void attack(const std::string &target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);
};

#endif
