/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:44:35 by hmorand           #+#    #+#             */
/*   Updated: 2024/09/27 15:45:58 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


void	display_times(char **args)
{
	clock_t	start, end;
	double	duration;

	PmergeMe<std::deque<int> > deq(args);
	start = clock();
	std::deque<int> arr = deq.getNumbers();
	deq.merge_insert(arr);
	end = clock();
	duration = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of "<< deq.getNumbers().size()
			  << " elements with std::deque: " << duration << "sec" << std::endl;

	PmergeMe<std::vector<int> > vec(args);
	start = clock();
	std::vector<int> arr1 = vec.getNumbers();
	vec.merge_insert(arr1);
	end = clock();
	duration = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of "<< vec.getNumbers().size()
			  << " elements with std::vector: " << duration << "sec" << std::endl;
}

bool	is_positive_integer(char *str)
{
	for (unsigned long i = 0; str[i]; i ++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}
