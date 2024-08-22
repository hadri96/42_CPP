/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:35:21 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/22 17:35:21 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
	private:
		Fixed	x,y;
	public:
		Point();
		Point(const Fixed x_0, const Fixed y_0);
		Point(const Point &other);

		~Point();

		Point &operator=(const Point &other);

		const Fixed	getX(void) const;
		const Fixed	getY(void) const;
		void		setX(Fixed value);
		void		setY(Fixed value);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
void	runTest(Point const &a, Point const &b, Point const &c, Point const &p,
			bool expected, const std::string &testName);
