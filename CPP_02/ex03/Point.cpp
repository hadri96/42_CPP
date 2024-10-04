/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 15:26:11 by hmorand           #+#    #+#             */
/*   Updated: 2024/10/04 15:26:15 by hmorand          ###   ########.ch       */
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

Point &Point::operator=(const Point &other)
{
	(void) other;
	return (*this);
}
