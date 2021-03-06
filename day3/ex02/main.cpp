/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:00:53 by mservage          #+#    #+#             */
/*   Updated: 2022/02/14 14:28:40 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	a("Pouet");
	FragTrap	b(a);

	std::cout << "1 :" << a.get_name() << " HP = " << a.get_HitPoint() << " " << a.get_name() << " Energy = " << a.get_EnergyPoint() << " Atk dmg = " << a.get_AttackDamage() << std::endl;

	
	a.attack(b.get_name());
	a.hightFivesGuys();
	return (0);
}
