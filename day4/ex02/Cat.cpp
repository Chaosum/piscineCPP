/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:36:31 by mservage          #+#    #+#             */
/*   Updated: 2022/02/21 16:06:54 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_brain = new Brain();
	_type = "Cat";
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	this->_type = src._type;
	this->_brain = new  Brain(*src._brain);
	*(this->_brain) = *(src._brain);
	std::cout << "Cat " << _type << " : Copy constructor" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat " << _type << " : Destructor" << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	this->_type = rhs._type;
	delete this->_brain;
	this->_brain = new  Brain(*rhs._brain);
	this->_brain = new  Brain(*rhs._brain);
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Miaou !" << std::endl;
}