/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:05:20 by mservage          #+#    #+#             */
/*   Updated: 2022/02/17 14:06:11 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	this->_type = src._type;
	std::cout << "WrongCat " << _type << " : Copy constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat " << _type << " : Destructor" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "coin coin !" << std::endl;
}