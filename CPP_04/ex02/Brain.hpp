/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:54:27 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/31 15:54:27 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string ideas[100];
	int n;

public:
	Brain();
	Brain(Brain &other);
	Brain &operator=(Brain &other);

	~Brain();

	std::string	*getIdeas(void) const;
	void		addIdea(std::string idea);
};

#endif
