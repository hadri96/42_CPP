/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.json                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:25:10 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/23 10:25:15 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T> void print(T ele)
{
	std::cout << ele << std::endl;
}

int main(void)
{
	const int arr[5] = {1, 2, 3, 4, 5};
	int arr2[4] = {6, 7, 8, 9};
	iter<const int>(arr, 5, print);
	iter<int>(arr2, 4, print);

	return 0;
}
