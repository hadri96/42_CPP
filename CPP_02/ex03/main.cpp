/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:04:11 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/03 12:06:42 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(0, 0), b(5, 0), c(0, 5);

	runTest(a, b, c, Point(2, 2), true, "Test Case 1");
	runTest(a, b, c, Point(2.5, 0), true, "Test Case 2");
	runTest(a, b, c, Point(0, 0), false, "Test Case 3");
	runTest(a, b, c, Point(5, 5), false, "Test Case 4");
	runTest(a, b, c, Point(4.999, 0.001), true, "Test Case 5");
	Point d(10, 0);
	runTest(Point(0, 0), Point(5, 0),
		d, Point(2.5, 0), false, "Test Case 6");
	runTest(Point(-1000, -1000), Point(1000, -1000),
			Point(0, 1000), Point(0, 0), true, "Test Case 7");
	runTest(Point(-1000, -1000), Point(1000, -1000),
			Point(0, 1000), Point(2000, 2000), false, "Test Case 8");
	return 0;
}
