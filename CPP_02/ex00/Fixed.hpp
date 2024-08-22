/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:33:16 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/22 09:33:16 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

		Fixed &operator=(const Fixed &other);
};

#endif
