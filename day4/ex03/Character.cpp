/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:53:24 by mservage          #+#    #+#             */
/*   Updated: 2022/02/18 01:01:04 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("")
{
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = 0;
	}
}

Character::Character(Character const &src)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i])
			this->_inventory[i] = src._inventory[i]->clone();
	}
	this->_name = src._name;
}
Character	&Character::operator=(Character const &rhs)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != 0)
			delete this->_inventory[i];
	}
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = rhs._inventory[i];
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != 0)
			delete this->_inventory[i];
	}
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == 0)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}
void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != 0)
		this->_inventory[idx] = 0;//attention leaks dans le main
}
void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != 0)
		this->_inventory[idx]->use(target);
}