/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:06:38 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 18:06:38 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: ICharacter
{
	private:
		std::string		name;
		AMateria		**materials;
		int				amount;

	public:
		Character(std::string n);
		Character(Character &other);
		Character &operator=(Character &other);
		~Character();

		std::string	const &getName() const;
		void 		equip(AMateria *m);
		void 		unequip(int idx);
		void		use(int idx, Character &target);
};

#endif
