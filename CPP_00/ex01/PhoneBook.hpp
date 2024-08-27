/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:03:40 by hmorand           #+#    #+#             */
/*   Updated: 2024/08/27 15:03:40 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <cctype>
# include <cstdlib>
# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	contacts[8];
		int		size;

	public:
		PhoneBook();
		~PhoneBook();

		void	search() const;
		void	add_contact();
		void	run();
		bool	valid_number(std::string const num) const;
};

#endif
