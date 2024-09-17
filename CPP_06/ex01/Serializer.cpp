/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:03:29 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/17 13:12:20 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer &other) { (void) other; }

Serializer &Serializer::operator=(Serializer &other)
{
	(void) other;
	return (*this);
}

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data	*Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
