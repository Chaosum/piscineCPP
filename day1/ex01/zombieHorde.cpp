/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:32:00 by mservage          #+#    #+#             */
/*   Updated: 2021/11/03 18:01:43 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int		i;
	Zombie	*horde;
	
	i = 0;
	horde = new Zombie[N];
	while (i < N)
		horde[i++].setName(name);
	return (horde);
}