/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:03:37 by hmorand           #+#    #+#             */
/*   Updated: 2024/07/28 13:03:54 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

bool	no_error_infile(std::ifstream &file, std::string name, std::string to)
{
	if (!file.is_open())
	{
		std::cout << "Unable to open the file " << name << std::endl;
		return (false);
	}
	if (to.empty())
	{
		std::cout << "Please make sure to enter a non-empty pattern to replace" << std::endl;
		return (false);
	}
	return (true);
}

bool	no_error_outfile(std::ofstream &file, std::string name)
{
	if (!file.is_open())
	{
		std::cout << "Unable to open the file " << name << " for writing"<< std::endl;
		return (false);
	}
	return (true);
}


int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments, please enter only 3 arguments!" << std::endl;
		return 1;
	}
	std::string infilename(argv[1]);
	std::string to(argv[2]);
	std::ifstream	infile(infilename.c_str());
	if (!no_error_infile(infile, infilename, argv[2]))
	{
		infile.close();
		return (1);
	}
	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string content = buffer.str();
	infile.close();
	std::string outfilename(argv[1]);
	outfilename += ".replace";
	std::ofstream outfile(outfilename.c_str());
	if (!no_error_outfile(outfile, argv[1]))
	{
		outfile.close();
		return (1);
	}
	int	size_to = to.size();
	for (int i = 0; content[i]; i++)
	{
		if (!content.substr(i, size_to).compare(argv[2]))
		{
			outfile << argv[3];
			i += size_to - 1;
		}
		else
			outfile << content[i];
	}
	outfile.close();
	return (0);
}
