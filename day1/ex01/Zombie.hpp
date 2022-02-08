/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:40:43 by mservage          #+#    #+#             */
/*   Updated: 2022/02/06 17:57:40 by matthieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie
{
private:
	std::string _name;

public:
	Zombie(void);
	~Zombie(void);
	void		announce(void) const;
	void		setName(std::string name);
	std::string getName(void) const;
};

Zombie	*zombieHorde(int N, std::string name);
void randomChump(std::string name);
Zombie	*newZombie(std::string name);
int	main();

#endif