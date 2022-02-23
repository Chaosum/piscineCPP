/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:34:01 by mservage          #+#    #+#             */
/*   Updated: 2022/02/23 14:23:57 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog &src);
	virtual ~Dog(void);
	
	Dog	&operator=(Dog const &rhs);
	virtual void makeSound(void) const;
private:
	Brain*	_brain;
};