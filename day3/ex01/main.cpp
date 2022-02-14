/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:00:53 by mservage          #+#    #+#             */
/*   Updated: 2022/02/14 14:21:20 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	a("Pouet");
	std::cout << "1 :" << a.get_name() << " HP = " << a.get_HitPoint() << " " << a.get_name() << " Energy = " << a.get_EnergyPoint() << " Attack damages = " << a.get_AttackDamage() << std::endl;
	ScavTrap	b(a);
	ScavTrap	c("paul");

	c = b;
	c.guardGate();
	c.guardGate();
	c.attack(a.get_name());
	c.beRepaired(10);
	std::cout << c.get_name() << " HP = " << c.get_HitPoint() << std::endl;

	return (0);
}
