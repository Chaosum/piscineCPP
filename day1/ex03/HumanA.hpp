/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:42:35 by mservage          #+#    #+#             */
/*   Updated: 2021/11/03 23:05:28 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);
	void		attack() const;
	void		setName(std::string name);
	Weapon		&getWeapon(void) const;
	std::string	getName(void) const;
private:
	Weapon		&_weapon;
	std::string	_name;
};

#endif
