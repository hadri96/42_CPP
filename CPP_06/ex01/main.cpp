/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:27:49 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/17 13:29:10 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of parameters!" << std::endl;
		return (1);
	}
	Data *data = new Data;
	data->data = static_cast <void *> (argv[1]);
	std::cout << "Value before deserialization: \t" << static_cast<char*> (data->data) << std::endl;
	std::cout << "Pointer before serialization: \t" << data << std::endl;
	uintptr_t serial = Serializer::serialize(data);
	std::cout << "After serialization: \t\t" << serial << std::endl;
	Data *after = Serializer::deserialize(serial);
	std::cout << "Pointer after deserialization: \t" << after << std::endl;
	std::cout << "Value after deserialization: \t" << static_cast<char*> (after->data) << std::endl;
	delete data;
	return (0);
}
