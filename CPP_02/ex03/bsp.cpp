/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:51:42 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/22 17:52:03 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void runTest(Point const &a, Point const &b, Point const &c,
	Point const &p, bool expected, const std::string &testName)
{
	bool result = bsp(a, b, c, p);
	if (result == expected)
		std::cout << testName << " passed." << std::endl;
	else
		std::cout << testName << " failed." << std::endl;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	lambda_1, lambda_2, lambda_3;

	lambda_1 = ((b.getY() - c.getY() * (point.getX() - c.getX())) \
				+ ((c.getX() - b.getX()) * (point.getY() - c.getY()))) \
				/ ((b.getY() - c.getY() * (a.getX() - c.getX())) \
				+ (c.getX() - b.getX() * (a.getY() - c.getY())));

	lambda_2 = ((c.getY() - a.getY() * (point.getX() - c.getX())) \
				+ ((a.getX() - c.getX()) * (point.getY() - c.getY()))) \
				/ ((b.getY() - c.getY() * (a.getX() - c.getX())) \
				+ (c.getX() - b.getX() * (a.getY() - c.getY())));
	lambda_3 = Fixed(1) - lambda_1 - lambda_2;
	if (lambda_1 > Fixed(1) || lambda_1 < Fixed() \
		|| lambda_2 > Fixed(1) || lambda_2 < Fixed() \
		|| lambda_3 > Fixed(1) || lambda_3 < Fixed())
		return (false);
	if ((a.getX() == b.getX() && a.getX() == c.getX()) \
		|| (a.getY() == b.getY() && a.getY() == c.getY()))
		return (false);
	if (lambda_1 + lambda_2 + lambda_3 == Fixed(1))
		return (true);
	return (false);
}
