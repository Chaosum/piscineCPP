/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:51:22 by mservage          #+#    #+#             */
/*   Updated: 2022/02/10 14:49:53 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	_GateKeeper = 0;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " default constructeur called" << std::endl;
	_HitPoint = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	_GateKeeper = 0;
}

ScavTrap::ScavTrap(ScavTrap &src): ClapTrap(src)
{
	std::cout << "ScavTrap copy constructeur called" << std::endl;
	src._GateKeeper = this->_GateKeeper;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->get_name() << " destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_EnergyPoints <= 1)
	{
		std::cout << "ScavTrap Not enouth energy to attack " << target << std::endl;
		return ;
	}
	this->_EnergyPoints--;
	std::cout << "ScavTrap " << this->get_name() << " attacks " << target << ", causing " << this->get_AttackDamage() << "damages." << std::endl;
}

void	ScavTrap::guardGate()
{
	if (_GateKeeper == 0)
	{
		_GateKeeper = 1;
		std::cout << "ScavTrap " << this->get_name() << " enter in gatekeeper mode" << this->get_AttackDamage() << std::endl;
	}
	else
	{
		_GateKeeper = 0;
		std::cout << "ScavTrap " << this->get_name() << " leaves the gatekeeper mode" << this->get_AttackDamage() << std::endl;
	}
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	this->_name = rhs._name;
	this->_HitPoint = rhs._HitPoint;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;
	this->_GateKeeper = rhs._GateKeeper;
	return (*this);
}
