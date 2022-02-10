/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:00:53 by mservage          #+#    #+#             */
/*   Updated: 2022/02/10 14:11:15 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(""), _HitPoint(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap default constructeur called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _HitPoint(10), _EnergyPoints(10), _AttackDamage(0)
{
	std::cout << "ClapTrap " << name << " Name constructeur called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &src)
{
	std::cout << "ClapTrap " << this->get_name() << " copy constructeur called" << std::endl;
	src._name = this->_name;
	src._HitPoint = this->_HitPoint;
	src._EnergyPoints = this->_EnergyPoints;
	src._AttackDamage = this->_AttackDamage;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->get_name() << " destructor called" << std::endl;

}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs._name;
	this->_HitPoint = rhs._HitPoint;
	this->_EnergyPoints = rhs._EnergyPoints;
	this->_AttackDamage = rhs._AttackDamage;
	return (*this);
}

const	std::string	ClapTrap::get_name() const
{
	return (this->_name);
}

int	ClapTrap::get_HitPoint(void) const
{
	return (this->_HitPoint);
}

int	ClapTrap::get_EnergyPoint(void) const
{
	return (this->_EnergyPoints);
}

int	ClapTrap::get_AttackDamage(void) const
{
	return (this->_AttackDamage);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_EnergyPoints <= 1)
	{
		std::cout << "Not enouth energy to attack " << target << std::endl;
		return ;
	}
	this->_EnergyPoints--;
	std::cout << "ClapTrap " << this->get_name() << " attacks " << target << ", causing " << this->get_AttackDamage() << "damages." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amout)
{
	if (this->_EnergyPoints <= 1)
	{
		std::cout << "Not enouth energy to repair yourself" << std::endl;
		return ;
	}
	this->_EnergyPoints--;
	std::cout << "ClapTrap " << this->get_name() << "repaired himself and gains " << amout << " HP" << std::endl;
	this->_HitPoint += amout;
}

void	ClapTrap::takeDamage(unsigned int amout)
{
	std::cout << "ClapTrap " << this->get_name() << " took " << amout << " damages" << std::endl;
	this->_HitPoint -= amout;
	if (this->_HitPoint < 1)
	{
		std::cout << "ClapTrap " << this->get_name() << "got destroyed" << std::endl;
		this->~ClapTrap();
	}
}

