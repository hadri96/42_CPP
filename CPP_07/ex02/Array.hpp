/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:41:24 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/23 11:46:41 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstring>

template <class A>
class Array
{
	private:
		unsigned long	s;
		A				*values;

	public:

		class MemoryAllocationFailure: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Failure during memory allocation");
				}
		};

		class IndexError: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Invalid value for index");
				}
		};


		Array()
		{
			values = new A[0];
			s = 0;
			if (!values)
				throw MemoryAllocationFailure();
		}

		Array(unsigned int n)
		{
			values = new A[n];
			s = n;
			if (!values)
				throw MemoryAllocationFailure();
			std::memset(values, 0, n);
		}

		Array(Array &other): s(other.s)
		{
			values = new A[s];
			if (!values)
				throw MemoryAllocationFailure();
			for (unsigned long i = 0; i < s; i++)
				values[i] = other.values[i];
		}

		Array &operator=(Array &other)
		{
			if (this != &other)
			{
				delete[] values;
				s = other.s;
				values = new A[s * sizeof(A)];
				if (!values)
					throw MemoryAllocationFailure();
				for (unsigned long i = 0; i < s; i++)
					values[i] = other.values[i];
			}
			return (*this);
		}

		~Array() { delete[] values; }

		A &operator[](unsigned long i)
		{
			if (i >= s)
				throw IndexError();
			return (values[i]);
		}

		unsigned long size( void ) { return (s); }

};

#endif
