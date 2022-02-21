/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:47:19 by mservage          #+#    #+#             */
/*   Updated: 2022/02/21 16:37:20 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void sub()
{
	IMateriaSource* src = new MateriaSource();
	IMateriaSource* copysrc = new MateriaSource();
	AMateria *manuallyDeletedMateria = new Ice();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	ICharacter* you = new Character("you");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->equip(manuallyDeletedMateria);

	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	// Commenting this line will produce a SIGABORT/SIGSEGV
	me->unequip(2);

	// me->unequip(0);

	
	*copysrc = *src;
	*you = *me;

	delete manuallyDeletedMateria;
	delete bob;
	delete me;
	delete you;
	delete src;
	delete copysrc;
}

int main()
{
	sub();
	return 0;
}