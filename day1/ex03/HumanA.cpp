/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:41:58 by mservage          #+#    #+#             */
/*   Updated: 2021/11/03 23:05:38 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon), _name(name)
{
}

HumanA::~HumanA()
{
}

Weapon	&HumanA::getWeapon() const
{
	return (this->_weapon);
}

std::string	HumanA::getName() const
{
	return (this->_name);
}

void	HumanA::setName(std::string name)
{
	this->_name = name;
}

void	HumanA::attack() const
{
	std::cout << this->getName() << " attacks with his " << this->getWeapon().getType() << std::endl;
}