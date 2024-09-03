/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:28:12 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/03 13:28:16 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private:
			Brain		*brain;
	public:
		Dog();
		Dog(Dog &other);
		Dog &operator=(Dog &other);
		~Dog();

		void makeSound(void) const;
};

#endif
