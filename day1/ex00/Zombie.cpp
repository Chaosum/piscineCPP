/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:46:20 by mservage          #+#    #+#             */
/*   Updated: 2021/11/03 17:46:02 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>

std::string	Zombie::getName() const
{
	return (Zombie::_name);
}

void	Zombie::setName(std::string name)
{
	Zombie::_name = name;
	return ;
}

void	Zombie::announce() const
{
	std::cout << getName() << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	this->_name = "";
}

Zombie::~Zombie()
{
	std::cout << getName() << " vanished away" << std::endl;
}