/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:36:17 by mservage          #+#    #+#             */
/*   Updated: 2022/02/21 16:05:11 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_brain = new Brain();
	_type = "Dog";
	std::cout << "Dog default constructor" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src)
{
	this->_type = src._type;
	this->_brain = new  Brain(*src._brain);
	*(this->_brain) = *(src._brain);
	std::cout << "Dog " << _type << " : Copy constructor" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog " << _type << " : Destructor" << std::endl;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	this->_type = rhs._type;
	delete this->_brain;
	this->_brain = new  Brain(*rhs._brain);
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Waf Waf !" << std::endl;
}