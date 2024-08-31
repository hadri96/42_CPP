/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:10:04 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 16:10:04 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"

class Animal
{
	protected:
		std::string	type;
		Brain		*brain;
	public:
		Animal();
		Animal(std::string t);
		Animal(Animal &other);
		Animal &operator=(Animal &other);

		virtual ~Animal();
		virtual void	makeSound( void ) const;
		std::string		getType( void ) const;
		void			setType(std::string t);
};

#endif
