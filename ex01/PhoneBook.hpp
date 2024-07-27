/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:24:26 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 15:24:26 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <iostream>
# include <string>
# include <cctype>
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
