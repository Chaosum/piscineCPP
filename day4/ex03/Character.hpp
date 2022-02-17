/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:51:00 by mservage          #+#    #+#             */
/*   Updated: 2022/02/17 18:00:43 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include <iostream>
# include <string>

class Character : public ICharacter
{
public:
	Character();
	Character(std::string name);
	Character(Character const &src);
	~Character(void);

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
	Character	&operator=(Character const &rhs);
protected:
	std::string _name;
	AMateria	*_inventory[4];
};

#endif