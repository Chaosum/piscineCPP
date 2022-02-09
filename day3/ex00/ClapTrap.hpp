/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:59:57 by mservage          #+#    #+#             */
/*   Updated: 2022/02/09 15:07:03 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
public:
	ClapTrap(std::string name);
	ClapTrap(ClapTrap &src);
	~ClapTrap();

	std::string	get_name(void) const;
	int		get_HitPoint(void) const;
	int		get_EnergyPoint(void) const;
	int		get_AttackDamage(void) const;
	
	void	attack(const std::string &target);
	void	takeDamage(unsigned int amout);
	void	beRepaired(unsigned int amout);

	ClapTrap	&operator=(ClapTrap const &rhs);
	
private:
	std::string	_name;
	int			_HitPoint;
	int			_EnergyPoints;
	int			_AttackDamage;
};

#endif