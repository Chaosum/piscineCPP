/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:14:43 by mservage          #+#    #+#             */
/*   Updated: 2021/11/02 21:56:19 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	Phonebook::contact_number = 0;
}

Phonebook::~Phonebook()
{
}

int		Phonebook::getContact_number()
{
	return(this->contact_number);
}

void	Phonebook::setContact_number(int nbr)
{
	this->contact_number = nbr;
	return ;
}

void	Phonebook::ft_add()
{
	int	contact_nbr;

	contact_nbr = getContact_number();
	if (contact_nbr >= 8)
	{
		std::cout << "\tThe phonebook is full" << std::endl;
		return ;
	}
	else
	{
		setContact(contact_number);
		contact_nbr++;
		setContact_number(contact_nbr);
	}
	return ;
}

void	ft_size_search(std::string str)
{
	int j;

	if (str.size() > 10)
	{
		str.resize(9);
		str.append(".");
		std::cout << str << "|";
	}
	else
	{
		j = 10 - str.size();
		while (j-- > 0)
			std::cout << " ";
		std::cout << str << "|";
	}
}

void	Phonebook::ft_search()
{
	int			i;
	int			index;
	std::string str;

	i = 0;
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|                 REPORTORY                 |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|     index|First name| Last name|   Nickame|" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;	
	while (i < getContact_number())
	{
		std::cout << "|         " << i << "|";
		str = this->contact[i].getFname();
		ft_size_search(str);
		str = this->contact[i].getLname();
		ft_size_search(str);
		str = this->contact[i].getNname();
		ft_size_search(str);
		std::cout << std::endl;
		i++;
	}
	std::cout << "|___________________________________________|" << std::endl;	
	i--;
	std::cout << "index: ";
	if (!std::getline(std::cin, str))
		return ;
	if (strcmp(str.c_str(), "EXIT") == 0)
		return ;
	std::cout << std::endl;
	if (!str.find_first_not_of("0123456789"))
		std::cout << "\tWrong index value" << std::endl;
	else
	{
		index = atoi(str.c_str());
		if (index >= getContact_number() || index < 0)
		{
			std::cout << "\tWrong index number" << std::endl;
			return ;
		}
		std::cout << "First name: " << this->contact[i].getFname() << std::endl;
		std::cout << "Last name: " << this->contact[i].getLname() << std::endl;
		std::cout << "Nickname: " << this->contact[i].getNname() << std::endl;
		std::cout << "Number: " << this->contact[i].getNumber() << std::endl;
		std::cout << "Darkest secret: " << this->contact[i].getSecret() << std::endl;
	}
}

void Phonebook::setContact(int i)
{
	std::string line;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|             ADDING NEW CONTACT            |" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "First name: ";
	if (!std::getline(std::cin, line))
		return ;
	this->contact[i].setFname(line);
	std::cout << "Last name: ";
	if (!std::getline(std::cin, line))
		return ;
	this->contact[i].setLname(line);
	std::cout << "nickname: ";
	if (!std::getline(std::cin, line))
		return ;
	this->contact[i].setNname(line);
	std::cout << "Phone number: ";
	if (!std::getline(std::cin, line))
		return ;
	this->contact[i].setNumber(line);
	std::cout << "Darkest secrect: ";
	if (!std::getline(std::cin, line))
		return ;
	this->contact[i].setSecret(line);
}