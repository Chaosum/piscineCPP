/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:55:32 by mservage          #+#    #+#             */
/*   Updated: 2022/02/28 15:10:59 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): nb_stocked(0), max_nbr(0)
{
}

Span::Span(unsigned int n): nb_stocked(0), max_nbr(n)
{
	tab.clear();
}

Span::Span(Span &src)
{
	max_nbr = src.max_nbr;
	nb_stocked = src.nb_stocked;
	tab.clear();
	for (std::vector<int>::iterator it = src.tab.begin(); it != src.tab.end(); it++)
	{
		tab.push_back(*it);
	}
}

Span	&Span::operator=(Span const &src)
{
	max_nbr = src.max_nbr;
	nb_stocked = src.nb_stocked;
	tab.clear();
	for (std::vector<int>::const_iterator it = src.tab.begin(); it != src.tab.end(); it++)
	{
		tab.push_back(*it);
	}
	return (*this);
}

Span::~Span(void)
{
	tab.clear();
}
