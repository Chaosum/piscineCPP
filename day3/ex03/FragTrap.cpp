/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:36:47 by matthieu          #+#    #+#             */
/*   Updated: 2022/02/14 14:31:07 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap default constructeur called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	_HitPoint = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "FragTrap " << name << " name constructeur called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
	std::cout << "FragTrap copy constructeur called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->get_name() << " destructor called" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_EnergyPoints <= 1)
	{
		std::cout << "FragTrap Not enouth energy to attack " << target << std::endl;
		return ;
	}
	this->_EnergyPoints--;
	std::cout << "FragTrap " << this->get_name() << " attacks " << target << ", causing " << this->get_AttackDamage() << " damages." << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	this->_name = rhs._name;
	this->_HitPoint = rhs._HitPoint;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

void	FragTrap::hightFivesGuys()
{
		std::cout << "FragTrap want a hight fives ..." << std::endl;
}
