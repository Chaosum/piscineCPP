/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:03:44 by mservage          #+#    #+#             */
/*   Updated: 2022/02/17 15:20:37 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>

class Animal
{
public:
	Animal(void);
	Animal(const Animal &src);
	virtual ~Animal(void);

	std::string const &getType(void) const;
	Animal	&operator=(Animal const &rhs);
	virtual void makeSound(void) const = 0;

protected:
	std::string _type;
};