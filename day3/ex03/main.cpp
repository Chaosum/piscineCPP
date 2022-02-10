/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:00:53 by mservage          #+#    #+#             */
/*   Updated: 2022/02/09 15:14:32 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a("bob");
	ClapTrap	b("pierre");
	ClapTrap	c(a);

	
	b.attack(a.get_name());
	b.takeDamage(5);
	c = b;
	std::cout << c.get_name() << " HP = " << c.get_HitPoint() << " " << c.get_name() << " Energy = " << c.get_EnergyPoint() << " et " << b.get_name() << " HP = " << b.get_HitPoint() << std::endl;
	b.takeDamage(5);
	c.beRepaired(3);
	std::cout << c.get_name() << " HP = " << c.get_HitPoint() << " et " << c.get_name() << " Energy = " << c.get_EnergyPoint() << std::endl;
	
	return (0);
}