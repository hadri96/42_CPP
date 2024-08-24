/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 14:22:38 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/23 14:22:38 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string n);
		FragTrap(FragTrap &other);
		~FragTrap();

		FragTrap &operator=(FragTrap &other);

		void highFivesGuys(void);
};

#endif
