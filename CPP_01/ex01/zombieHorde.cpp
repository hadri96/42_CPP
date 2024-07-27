/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:07:43 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 20:07:43 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde;

	horde = new (std::nothrow) Zombie[N];
	if (!horde)
		return (nullptr);
	for (int i = 0; i < N; i++)
		new (&horde[i]) Zombie(name);
	return (horde);
}
