/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:12:55 by mservage          #+#    #+#             */
/*   Updated: 2021/11/02 21:57:55 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# include <string>
#include "Phonebook.hpp"

int	main()
{
	Phonebook	Phonebook;
	std::string	line;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|                MY PHONEBOOK               |" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	while (1)
	{
		std::cout << std::endl << "Command: ";
		if (!std::getline(std::cin, line))
			return (1);
		if (std::strcmp(line.c_str(), "EXIT") == 0)
			break ;
		else if (std::strcmp(line.c_str(), "ADD") == 0)
			Phonebook.ft_add();
		else if (std::strcmp(line.c_str(), "SEARCH") == 0)
		{
			if (Phonebook.getContact_number() == 0)
			{
				std::cout << "No contacts in the repertory" << std::endl;
				std::cout << "\tuse the ADD command to create new contacts" << std::endl;
			}
			else
				Phonebook.ft_search();
		}	
		else
		{
			std::cout << "Unknown command" << std::endl;
			std::cout << "\tAllowed commands: ADD, SEARCH, EXIT" << std::endl;
		}
	}
	return (1);
}