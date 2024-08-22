/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:01:28 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/28 15:02:50 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iomanip>
# include <iostream>

# define BOLD_WHITE		"\033[1;37m"
# define BOLD_RED		"\033[1;31m"
# define BOLD_GREEN		"\033[1;32m"
# define BOLD_YELLOW	"\033[1;33m"
# define BOLD_ORANGE	"\033[38;5;208m"
# define RESET			"\033[0m"


class Harl
{
	private:

		typedef void	(Harl::* func)(void);

		typedef	struct s_function_map
		{
			std::string	name;
			func	function;
		}	t_function_map;

		void			debug( void );
		void			info( void );
		void			warning( void );
		void			error( void );

		t_function_map	funcs[4];

	public:
		Harl();

		~Harl();

		void	complain( std::string level );

};


#endif
