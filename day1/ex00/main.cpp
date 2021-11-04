/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:21:51 by mservage          #+#    #+#             */
/*   Updated: 2021/11/03 18:07:08 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int	main()
{
	Zombie	*zombie;
	Zombie	zonzonbie;

	zonzonbie.setName("michel");
	zonzonbie.announce();
	zombie = newZombie("Pal");
	zombie->announce();
	randomChump("aref");
	delete(zombie);
	return (1);
}
