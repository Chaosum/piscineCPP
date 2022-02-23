/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:36:17 by mservage          #+#    #+#             */
/*   Updated: 2022/02/23 14:19:40 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	this->_type = src._type;
	std::cout << "Dog " << _type << " : Copy constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog " << _type << " : Destructor" << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Waf Waf !" << std::endl;
}