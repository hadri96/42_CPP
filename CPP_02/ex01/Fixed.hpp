/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:47:26 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/22 15:48:01 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int int_value);
		Fixed(const float float_value);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

		Fixed &operator=(const Fixed &other) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif