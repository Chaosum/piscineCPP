/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:22:10 by mservage          #+#    #+#             */
/*   Updated: 2022/02/28 13:22:38 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
void	iter(T *tab, int size, void fnct(T &src))
{
	int i = 0;
	while (i < size)
	{
		fnct(tab[i]);
		i++;
	}
}

template< typename T >
void print(T &src)
{
	std::cout << src << std::endl;
}