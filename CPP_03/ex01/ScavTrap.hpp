/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:07:57 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/03 12:07:57 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string n);
		ScavTrap(ScavTrap &other);
		~ScavTrap();

		ScavTrap &operator=(const ScavTrap &other);

		void attack(const std::string &target);
		void guardGate( void );
};

#endif
