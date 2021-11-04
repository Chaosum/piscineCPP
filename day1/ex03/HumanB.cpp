/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:56:06 by mservage          #+#    #+#             */
/*   Updated: 2021/11/03 23:26:21 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
}
HumanB::~HumanB()
{
}

void	HumanB::attack() const
{
	if (this->_weapon)
		std::cout << this->getName() << " attacks with his " << this->getWeapon().getType() << std::endl;
	else
		std::cout << this->getName() << " is looking for some weapons" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::setName(std::string name)
{
	this->_name = name;
	return ;
}

Weapon	&HumanB::getWeapon(void) const
{
	return (*(this->_weapon));
}

std::string	HumanB::getName(void) const
{
	return(this->_name);
}