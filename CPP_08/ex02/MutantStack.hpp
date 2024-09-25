/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:38:30 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/25 09:44:34 by hmorand          ###   ########.ch       */
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
		MutantStack<T>(): std::stack<T>() {}
		MutantStack<T>(MutantStack<T> &other): std::stack<T>(other) {}
		MutantStack	&operator=(MutantStack<T> &other)
		{
			if (this != &other)
				std::stack<T>::operator=;
			return (*this);
		}
		~MutantStack<T>() {}
		typedef typename std::stack<T>::container_type::iterator	iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin() { return iterator(this->c.begin()); }
		iterator end() { return iterator(this->c.end()); }
		iterator begin() const { return iterator(this->c.begin()); }
		iterator end() const { return iterator(this->c.end()); }
};

#endif
