/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:33:12 by mservage          #+#    #+#             */
/*   Updated: 2022/02/17 17:15:14 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		this->_learned[i] = 0;
	}
}
MateriaSource::MateriaSource(MateriaSource const &src)
{
	for (int i = 0; i < 4; i++)
	{
		this->_learned[i] = src._learned[i];
	}
}
MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learned[i] != 0)
			delete (this->_learned[i]);
	}
}
MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learned[i] != 0)
			delete (this->_learned[i]);
	}
	for (int i = 0; i < 4; i++)
	{
		this->_learned[i] = rhs._learned[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learned[i] != 0)
		{
			this->_learned[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 4; i >= 0; i--)
	{
		if (this->_learned[i]->getType() == type)
			return (this->_learned[i]->clone());
	}
	return (0);
}