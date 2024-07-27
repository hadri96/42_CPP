/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:40:02 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 19:40:02 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*tom;

	randomChump("Kevin");
	tom = newZombie("Tom");
	if (!tom)
		return 0;
	tom->announce();
	randomChump("Jimmy");
	tom->announce();
	delete tom;
	return 0;
}
