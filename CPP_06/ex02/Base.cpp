/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:21:36 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/18 15:22:04 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *generate(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	std::srand(static_cast<unsigned int>(tv.tv_usec));
	Base *p = NULL;
	switch (rand() % 3)
	{
	case (0):
		p = new A;
		std::cout << "Type A created" << std::endl;
		return (p);
	case (1):
		p = new B;
		std::cout << "Type B created" << std::endl;
		return (p);
	case (2):
		p = new C;
		std::cout << "Type C created" << std::endl;
		return (p);
	}
	return (p);
}

void	identify(Base *p)
{
	if (A *a = dynamic_cast <A*>(p))
		std::cout << "A" << std::endl;
	else if (B *b = dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (C *c = dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::bad_cast &e1)
	{
		try
		{
			(void) dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (const std::bad_cast &e2)
		{
			(void) dynamic_cast<C&> (p);
			std::cout << "C" << std::endl;
		}
	}
}
