/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:27:17 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/25 18:27:17 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal(std::string t);
		WrongAnimal(WrongAnimal &other);
		WrongAnimal &operator=(WrongAnimal &other);

		~WrongAnimal();
		void	makeSound( void ) const;
		std::string		getType( void ) const;
		void			setType(std::string t);
};

#endif
