/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:44:21 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/28 11:44:21 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iomanip>
# include <iostream>

class Weapon
{
	private:
		std::string	type;
	public:
		Weapon();
		Weapon(std::string t);

		~Weapon();

		std::string	const &getType( void ) const;
		void		setType(std::string type);
};

#endif
