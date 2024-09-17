/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:14:15 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/17 13:14:22 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <iostream>

typedef struct s_data
{
	void *data;
}	Data;

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer &other);
		Serializer &operator=(Serializer &other);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif
