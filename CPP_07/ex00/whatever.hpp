/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:58:06 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/22 17:58:18 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void	swap(T &x, T &y)
{
	std::swap(x, y);
}

template <typename T>
T	max(T x, T y)
{
	return (x > y) ? x : y;
}

template <typename T>
T	min(T x, T y)
{
	return (x < y) ? x : y;
}

#endif
