/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:53:50 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/22 17:53:50 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(Fixed(0), Fixed(0)), b(Fixed(5), Fixed(0)), c(Fixed(0), Fixed(5));

	runTest(a, b, c, Point(Fixed(2), Fixed(2)), true, "Test Case 1");
	runTest(a, b, c, Point(Fixed((float) 2.5), Fixed(0)), true, "Test Case 2");
	runTest(a, b, c, Point(Fixed(0), Fixed(0)), false, "Test Case 3");
	runTest(a, b, c, Point(Fixed(5), Fixed(5)), false, "Test Case 4");
	runTest(a, b, c, Point(Fixed((float)4.999), Fixed((float) 0.001)), true, "Test Case 5");
	Point d(Fixed(10), Fixed(0));
	runTest(Point(Fixed(0), Fixed(0)), Point(Fixed(5), Fixed(0)),
		d, Point(Fixed((float) 2.5), Fixed(0)), false, "Test Case 6");
	runTest(Point(Fixed(-1000), Fixed(-1000)), Point(Fixed(1000), Fixed(-1000)),
			Point(Fixed(0), Fixed(1000)), Point(Fixed(0), Fixed(0)), true, "Test Case 7");
	runTest(Point(Fixed(-1000), Fixed(-1000)), Point(Fixed(1000), Fixed(-1000)),
			Point(Fixed(0), Fixed(1000)), Point(Fixed(2000), Fixed(2000)), false, "Test Case 8");
	return 0;
}
