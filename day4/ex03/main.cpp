/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matthieu <matthieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:47:19 by mservage          #+#    #+#             */
/*   Updated: 2022/02/18 16:06:20 by matthieu         ###   ########.fr       */
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
	AMateria *manuallyDeletedMateria = new Ice();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
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

	// Uncommenting this line should produce a leak (or not. Fuck off my code)
	// me->unequip(0);

	delete manuallyDeletedMateria;
	delete bob;
	delete me;
	delete src;
}

int main()
{
	sub();
	return 0;
}