/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:36:31 by mservage          #+#    #+#             */
/*   Updated: 2022/02/23 14:19:22 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src)
{
	this->_type = src._type;
	std::cout << "Cat " << _type << " : Copy constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat " << _type << " : Destructor" << std::endl;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "Miaou !" << std::endl;
}