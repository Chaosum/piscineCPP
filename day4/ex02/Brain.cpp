/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:34:03 by mservage          #+#    #+#             */
/*   Updated: 2022/02/21 15:51:49 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor" << std::endl;
}

Brain::Brain(const Brain &src)
{
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = src._ideas[i];
	}
	std::cout << "Brain : Copy constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain : Destructor" << std::endl;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	int i = 0;
	while (i < 100)
	{
		this->_ideas[i] = rhs._ideas[i];
		i++;
	}
	return (*this);
}
