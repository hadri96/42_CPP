/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:57:07 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/02 13:57:07 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde;

	horde = new (std::nothrow) Zombie[N];
	if (!horde)
		return (NULL);
	for (int i = 0; i < N; i++)
		new (&horde[i]) Zombie(name);
	return (horde);
}
