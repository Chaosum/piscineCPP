/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:00:53 by mservage          #+#    #+#             */
/*   Updated: 2022/02/14 15:14:04 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	a("Pouet");
	std::cout << "1 :" << a.get_Diamond_name() << " HP = " << a.get_HitPoint() << " " << a.get_Diamond_name() << " Energy = " << a.get_EnergyPoint() << " Atk dmg = " << a.get_AttackDamage() << std::endl;
	DiamondTrap	b(a);

	a.whoAmI();
	a.diam_attack("pouet");
	a.beRepaired(10);
	a.guardGate();
	a.hightFivesGuys();
	return (0);
}
