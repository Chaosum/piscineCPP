/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:45:41 by mservage          #+#    #+#             */
/*   Updated: 2022/02/10 14:50:45 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string name);
	ScavTrap(ScavTrap &src);
	~ScavTrap();
	
	void	attack(const std::string &target);
	void	guardGate(void);
	ScavTrap	&operator=(ScavTrap const &rhs);
	
private:
	int	_GateKeeper;
	ScavTrap(void);
};

#endif