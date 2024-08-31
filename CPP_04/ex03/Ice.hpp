/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:27:23 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 17:27:23 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &other);
		Ice &operator=(Ice const &other);
		~Ice();

		virtual AMateria	*clone() const ;
		void				use(ICharacter &target);
};

#endif
