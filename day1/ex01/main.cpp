/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:21:51 by mservage          #+#    #+#             */
/*   Updated: 2021/11/03 18:07:15 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int	main()
{
	int i = 0;
	int N = 5;
	Zombie	*zombie;

	zombie = zombieHorde(5, "Titouan");
	while (i < N)
		zombie[i++].announce();
	delete [] zombie;
	return (1);
}
