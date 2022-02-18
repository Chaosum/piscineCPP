/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:34:18 by mservage          #+#    #+#             */
/*   Updated: 2022/02/18 01:01:48 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->_type = "ice";
	//std::cout << "Ice default constructor" << std::endl;
}

Ice::Ice(Ice const &src): AMateria(src)
{
	this->_type = src._type;
	//std::cout << "Ice copy constructor" << std::endl;
}

Ice::~Ice()
{
	//std::cout << "Ice destructor" << std::endl;
}

Ice	&Ice::operator=(Ice const &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

AMateria *Ice::clone() const
{
	AMateria	*NewIce = new Ice();
	return (NewIce);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}
