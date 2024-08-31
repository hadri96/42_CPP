/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:10:43 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 16:15:04 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main(void)
{
	const Animal **animals = new const Animal *[20];

	for (int i = 0; i < 20; i++)
	{
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
	}
	for (int i = 0; i < 20; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}
	delete []animals;
}
