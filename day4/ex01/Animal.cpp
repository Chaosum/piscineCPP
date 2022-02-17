/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:08:49 by mservage          #+#    #+#             */
/*   Updated: 2022/02/17 14:18:02 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	_type = "Default_Animal";
	std::cout << "Animal default constructor" << std::endl;
}

Animal::Animal(const Animal &src)
{
	this->_type = src._type;
	std::cout << "Animal " << _type << " : Copy constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal " << _type << " : Destructor" << std::endl;
}

Animal	&Animal::operator=(Animal const &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "ANIMAL !" << std::endl;
}

std::string const &Animal::getType() const
{
	return (this->_type);
}