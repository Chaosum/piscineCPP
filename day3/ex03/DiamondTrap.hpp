/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:11:27 by matthieu          #+#    #+#             */
/*   Updated: 2022/02/14 15:11:37 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(std::string const name);
	DiamondTrap(const DiamondTrap &src);
	~DiamondTrap();
	std::string	get_Diamond_name(void);
	
	std::string const &get_Diam_name(void);
	void	diam_attack(std::string const &target);
	DiamondTrap	&operator=(DiamondTrap const &rhs);
	void	whoAmI(void);
private:
	std::string	_name;
};

#endif