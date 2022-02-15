/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:14:44 by matthieu          #+#    #+#             */
/*   Updated: 2022/02/14 22:30:32 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructer called" << std::endl;
	_name = "";
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_HitPoint = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 30;
	std::cout << "DiamondTrap " << _name << " named constructer called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	this->_name = src._name;
	std::cout << "DiamondTrap " << this->_name << " copy constructer called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destructer called" << std::endl;
}

std::string	DiamondTrap::get_Diamond_name()
{
	return (_name);
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs)
{
	this->_name = rhs._name;
	this->_HitPoint = rhs._HitPoint;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

std::string const &DiamondTrap::get_Diam_name()
{
	return (this->_name);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am both " << this->get_name() << " and " << _name << std::endl;
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}
