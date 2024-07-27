/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:17:41 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/27 15:17:41 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include <iostream>
# include <string>

std::string	truncate_field(std::string field);

class Contact
{
	private:
		std::string	first_name, last_name, nickname, darkest, number;
		int			index;

	public:
		Contact();
		Contact(std::string fields[5], int i);
		~Contact();

		void		decrement();
		void		display() const;
		void		truncated_display() const;
};

#endif
