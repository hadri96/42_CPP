/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:19:15 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 16:21:42 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string	type;
		Brain		*brain;
	public:
		AAnimal();
		AAnimal(std::string t);
		AAnimal(AAnimal &other);
		AAnimal &operator=(AAnimal &other);

		virtual ~AAnimal();
		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const;
		void			setType(std::string t);
};

#endif
