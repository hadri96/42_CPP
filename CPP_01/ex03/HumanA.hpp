/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:51:58 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 20:51:58 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <iomanip>

class HumanA
{
	private:
		std::string	name;
		Weapon		weapon;
	public:
		HumanA();
		HumanA(std::string n, Weapon w);

		~HumanA();

		void	attack( void );
};

#endif
