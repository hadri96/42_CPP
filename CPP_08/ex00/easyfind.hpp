/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:35:36 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/23 13:35:36 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <deque>
# include <vector>
# include <list>
# include <array>

class ValueNotFound: public std::exception
{
	public:
		const char *what() const throw()
		{
			return ("Value not found");
		}
};

template <typename T>
int	easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
		return (*it);
	else
		throw ValueNotFound();
}

#endif
