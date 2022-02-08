/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:29:33 by mservage          #+#    #+#             */
/*   Updated: 2022/02/06 16:33:06 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int	main(int ac, char **av)
{
	std::string	s1;
	std::string	s2;
	std::string	file;
	std::string	file_content;
	std::string	dest;
	std::stringstream	read;
	int	i = 0;
	int	j = 0;

	if (ac != 4)
	{
		std::cout << "Wrong args" << std::endl;
		return (1);
	}
	file = av[1];
	s1 = av[2];
	s2 = av[3];
	if (s1.empty() || s2.empty())
	{
		std::cout << "Wrong args, enpty string" << std::endl;
		return (1);
	}
	std::ifstream	ifs(av[1]);
	if (!ifs.good())
	{
		std::cout << "Error, can't open \" \"" << av[1] << std::endl;
		return (1);
	}
	std::ofstream	ofs(file + ".replace");
	read << ifs.rdbuf();
	file_content = read.str();
	while (file_content[i])
	{
		j = 0;
		if (file_content[i + j] == s1[j])
		{
			while (file_content[i + j] == s1[j])
			{
				j++;
				if (s1[j] == 0)
				{
					dest = dest + s2;
					i = i + j - 1;
					break ;
				}
			}
		}
		if (s1[j])
			dest = dest + file_content[i];
		i++;
	}
	ofs << dest;
	return (0);
}
