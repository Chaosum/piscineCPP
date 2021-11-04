/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:12:55 by mservage          #+#    #+#             */
/*   Updated: 2021/11/03 16:48:57 by mservage         ###   ########.fr       */
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
	while (true)
	{
		std::cout << std::endl << "Command: ";
		if (!std::getline(std::cin, line))
			return (1);
		if (line == "EXIT")
			break ;
		else if (line == "ADD")
			Phonebook.ft_add();
		else if (line == "SEARCH")
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