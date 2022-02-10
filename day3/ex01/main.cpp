/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:00:53 by mservage          #+#    #+#             */
/*   Updated: 2022/02/10 14:51:43 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	a("Pouet");
	std::cout << "1 :" << a.get_name() << " HP = " << a.get_HitPoint() << " " << a.get_name() << " Energy = " << a.get_EnergyPoint() << std::endl;
	ScavTrap	b(a);
	ScavTrap	c("paul");

	c = b;
	c.guardGate();
	c.guardGate();
	c.attack(a.get_name());
	c.beRepaired(10);
	return (0);
}
