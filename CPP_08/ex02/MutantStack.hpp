/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:43:40 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/23 16:49:40 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		class iterator
		{
			private:
				typename std::stack<T>::container_type::iterator it;

			public:
				iterator(typename std::stack<T>::container_type::iterator it) : it(it) {}
				iterator(const iterator& other) : it(other.it) {}

				T& operator*() const { return *it; }

				iterator& operator++()
				{
					++it;
					return *this;
				}
				iterator operator++(int)
				{
					iterator temp = *this;
					++(*this);
					return temp;
				}

				iterator& operator--()
				{
					--it;
					return *this;
				}
				iterator operator--(int) { iterator temp = *this; --(*this); return temp; }

				bool operator==(const iterator& other) const { return it == other.it; }
				bool operator!=(const iterator& other) const { return it != other.it; }
		};

		iterator begin() { return iterator(this->c.begin()); }
		iterator end() { return iterator(this->c.end()); }
};

#endif
