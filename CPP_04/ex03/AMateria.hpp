/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:28:10 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 17:28:10 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "Character.hpp"

class AMateria
{
	protected:
		std::string name;
	public :
		AMateria(std::string const &type);
		AMateria(AMateria const &other);
		AMateria &operator=(AMateria const &other);
		~AMateria();

		std::string const &getType() const; // Returns the materia type
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};

#endif
