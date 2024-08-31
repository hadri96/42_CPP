/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:23:54 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 16:23:54 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public AAnimal
{
	public:
		Cat();
		Cat(Cat &other);
		Cat &operator=(Cat &other);
		~Cat();

		void	makeSound( void ) const;
};

#endif
