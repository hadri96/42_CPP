/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:01:16 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 20:06:40 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(5, "Tom");

	for (int i = 0; i < 5; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}
