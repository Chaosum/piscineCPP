/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:00:53 by mservage          #+#    #+#             */
/*   Updated: 2022/02/14 14:07:12 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a("bob");
	ClapTrap	b(a);
	ClapTrap	c(a);

	std::cout << a.get_name() << " HP = " << a.get_HitPoint() << " " << c.get_name() << " Energy = " << c.get_EnergyPoint() << " attack damage = " << a.get_AttackDamage() << std::endl;
	b.attack(a.get_name());
	b.takeDamage(5);
	c = b;
	std::cout << c.get_name() << " HP = " << c.get_HitPoint() << " " << c.get_name() << " Energy = " << c.get_EnergyPoint() << " et " << b.get_name() << " HP = " << b.get_HitPoint() << std::endl;
	b.takeDamage(5);
	c.beRepaired(3);
	std::cout << c.get_name() << " HP = " << c.get_HitPoint() << " et " << c.get_name() << " Energy = " << c.get_EnergyPoint() << std::endl;
	
	return (0);
}
