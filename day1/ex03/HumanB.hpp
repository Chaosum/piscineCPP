/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:10:58 by mservage          #+#    #+#             */
/*   Updated: 2021/11/03 23:23:50 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
public:
	HumanB(std::string name);
	~HumanB(void);
	void		attack() const;
	void		setWeapon(Weapon &weapon);
	void		setName(std::string name);
	Weapon		&getWeapon(void) const;
	std::string	getName(void) const;
private:
	Weapon		*_weapon;
	std::string	_name;
};

#endif