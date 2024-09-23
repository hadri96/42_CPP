/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrong.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:42:58 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/23 16:43:26 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <stack>
# include <iterator>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename Container::iterator iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		class iterator
		{
			private:
				T	*ptr;

			public:

				iterator(T* ptr) : ptr(ptr) {}
				iterator(iterator &other): ptr(other.ptr) {}

				T &operator*() const { return *ptr; }

				iterator& operator++()
				{
					++ptr;
					return (*this);
				}

				iterator operator++(int)
				{
					iterator temp = *this;
					++(*this);
					return (temp);
				}

				iterator& operator--()
				{
					--ptr;
					return (*this);
				}

				iterator operator--(int)
				{
					iterator temp = *this;
					--(*this);
					return (temp);
				}

				bool operator==(const iterator& other) const { return (ptr == other.ptr); }

				bool operator!=(const iterator& other) const { return (ptr != other.ptr); }

			};
};
