/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:02:56 by mservage          #+#    #+#             */
/*   Updated: 2022/02/24 20:34:31 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): data(0)
{
}

Data::Data(uintptr_t nbr): data(nbr)
{
}

Data::Data(Data const &src)
{
	this->data = src.data;
}

Data::~Data(void)
{
}

Data	&Data::operator=(Data &src)
{
	this->data = src.data;
	return (*this);
}

uintptr_t	Data::getValue() const
{
	return (data);
}

