/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:34:41 by mservage          #+#    #+#             */
/*   Updated: 2022/02/18 01:01:57 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->_type = "cure";
	//std::cout << "Cure default constructor" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria(src)
{
	this->_type = src._type;
	//std::cout << "Cure copy constructor" << std::endl;
}

Cure::~Cure()
{
	//std::cout << "Cure destructor" << std::endl;
}

Cure	&Cure::operator=(Cure const &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

AMateria *Cure::clone() const
{
	AMateria	*NewCure = new Cure();
	return (NewCure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
