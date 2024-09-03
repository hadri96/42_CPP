/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:24:17 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/03 13:24:21 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
	private:
		Brain		*brain;
	public:
		Cat();
		Cat(Cat &other);
		Cat &operator=(Cat &other);
		~Cat();

		void	makeSound( void ) const;
};

#endif
