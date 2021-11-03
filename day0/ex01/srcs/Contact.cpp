/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:56:24 by mservage          #+#    #+#             */
/*   Updated: 2021/11/02 18:48:52 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Phonebook.hpp"
#include "Contact.hpp"

Contact::Contact(): fname(""), lname(""), nname(""), number(""), secret("")
{
}

Contact::~Contact()
{
}

void	Contact::setFname(std::string str)
{
	fname = str;
}

void	Contact::setLname(std::string str)
{
	lname = str;
}

void	Contact::setNname(std::string str)
{
	nname = str;
}

void	Contact::setNumber(std::string str)
{
	number = str;
}

void	Contact::setSecret(std::string str)
{
	secret = str;
}

std::string Contact::getFname(void)
{
	return (Contact::fname);
}

std::string Contact::getLname(void)
{
	return (Contact::lname);
}

std::string Contact::getNname(void)
{
	return (Contact::nname);
}

std::string Contact::getNumber(void)
{
	return (Contact::number);
}

std::string Contact::getSecret(void)
{
	return (Contact::secret);
}