/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:06:51 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 18:06:57 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string n): name(n), amount(0), materials(nullptr) {}

Character::Character(Character &other): \
name(other.name), amount(other.amount)
{
	if (amount == 0)
		materials = nullptr;
	else
	{
		materials = new AMateria *[amount];
		if (!materials)
			return ;
		for (int i = 0; i < amount; i++)
			materials[i] = other.materials[i]->clone();
	}
}
Character &Character::operator=(Character &other)
{
	if (this != &other)
	{
		name = other.name;
		amount = other.amount;
		if (amount == 0)
			materials = nullptr;
		else
		{
			materials = new AMateria *[amount];
			if (!materials)
				return;
			for (int i = 0; i < amount; i++)
				materials[i] = other.materials[i]->clone();
		}
	}
}

Character::~Character() { delete []materials; }

std::string const &Character::getName() const { return (name); }

void Character::equip(AMateria *m)
{
	AMateria **new_mats;

	if (amount + 1 > 4)
	{
		std::cout << "Too many materials in inventory already" << std::endl;
		delete m;
		return ;
	}
	else
	{
		new_mats = new AMateria *[amount + 1];
		if (!new_mats)
		{
			std::cout << "Issue with equipment of new material" << std::endl;
			return ;
		}
		for (int i = 0; i < amount; i++)
			new_mats[i] = materials[i];
		delete []materials;
		new_mats[amount++] = m;
		materials = new_mats;
	}

}

void Character::unequip(int idx)
{
	AMateria	**new_mats;

	if (amount == 0)
	{
		std::cout << "Empty inventory, impossible to unequip" << std::endl;
		return ;
	}
	if (idx > amount - 1 && idx < 0)
	{
		std::cout << "Invalid index value to unequip" << std::endl;
		return ;
	}
	new_mats = new AMateria *[amount - 1];
	for (int i = 0; i < amount - 1; i++)
		new_mats[i] = materials[i];
	delete materials[--amount];
	delete []materials;
	materials = new_mats;
}

void Character::use(int idx, Character &target)
{
	if (amount == 0)
	{
		std::cout << "Empty inventory, impossible to use materia" << std::endl;
		return ;
	}
	if (idx > amount - 1 && idx < 0)
	{
		std::cout << "Invalid index value to use materia" << std::endl;
		return;
	}
	materials[idx]->use(target);
}
