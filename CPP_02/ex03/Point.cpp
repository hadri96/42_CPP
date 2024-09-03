/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:03:10 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/03 12:03:59 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(Fixed()), y(Fixed()) {}

Point::Point(const Fixed x_0, const Fixed y_0) : x(x_0), y(y_0) {}

Point::Point(const float x_0, const float y_0): x(Fixed(x_0)), y(Fixed(y_0)) {}

Point::Point(Point const &other): x(other.x), y(other.y) {}

Point::~Point() {}

const Fixed Point::getX(void) const { return (x); }

const Fixed Point::getY(void) const { return (y); }

void	Point::setX(Fixed value) { x = value; }

void	Point::setY(Fixed value) { y = value; }

Point &Point::operator=(const Point &other)
{
	if (this != &other)
	{
		x = other.getX();
		y = other.getY();
	}
	return (*this);
}
