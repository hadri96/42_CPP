/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:22:45 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/18 15:23:49 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main( void )
{
	Base **individuals = new (std::nothrow) Base*[20];
	if (!individuals)
		return (1);
	int num = 10;
	for (int i = 0; i < num; i++)
		individuals[i] = generate();
	std::cout << "Identify with reference" << std::endl;
	for (int i = 0; i < num; i++)
		identify(*individuals[i]);
	std::cout << "Identify with pointer" << std::endl;
	for (int i = 0; i < num; i++)
		identify(*individuals[i]);
	for (int i = 0; i < num; i++)
		delete individuals[i];
	delete[] individuals;
}
