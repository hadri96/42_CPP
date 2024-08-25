/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:52:54 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/24 18:53:10 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string	type;
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
