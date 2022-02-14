/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:59:57 by mservage          #+#    #+#             */
/*   Updated: 2022/02/11 14:59:53 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string const name);
	ClapTrap(ClapTrap const &src);
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