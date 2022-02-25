/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 20:53:55 by mservage          #+#    #+#             */
/*   Updated: 2022/02/25 00:56:42 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


//Elle crée aléatoirement une instance de A, B ou C et la retourne en tant que pointeur sur
//Base. Utilisez ce que vous souhaitez pour l’implémentation du choix aléatoire.
Base * generate(void)
{
	Base*	tab[3];
	Base*	dest;
	
	tab[0] = new A();
	tab[1] = new B();
	tab[2] = new C();

	int random = rand() % 3;
	dest = tab[random];
	for (int i = 0; i < 3; i++)
	{
		if (dest != tab[i])
			delete tab[i];
	}
	return (dest);
}

//Elle affiche le véritable type de l’objet pointé par p : "A", "B" ou "C".
void identify(Base* p)
{
	Base *temp = NULL;

	temp = dynamic_cast<A *>(p);
	if (temp != NULL)
	{
		std::cout << "This pointer is a class type A" << std::endl;
		return ;
	}
	temp = dynamic_cast<B *>(p);
	if (temp != NULL)
	{
		std::cout << "This pointer is a class type B" << std::endl;
		return ;
	}
	temp = dynamic_cast<C *>(p);
	if (temp != NULL)
	{
		std::cout << "This pointer is a class type C" << std::endl;
		return ;
	}
}

// Elle affiche le véritable type de l’objet pointé par p : "A", "B" ou "C". Utiliser un pointeur
// dans cette fonction est interdit.
void identify(Base& p)
{
	try
	{
		A &temp = dynamic_cast<A &>(p);
		(void)temp;
		std::cout << "This reference is a class type A" << std::endl;
		return ;
	}
	catch(std::bad_cast &bc)
	{
	}
	try
	{
		B &temp = dynamic_cast<B &>(p);
		(void)temp;
		std::cout << "This reference is a class type A" << std::endl;
		return ;
	}
	catch(std::bad_cast &bc)
	{
	}
	try
	{
		C &temp = dynamic_cast<C &>(p);
		(void)temp;
		std::cout << "This reference is a class type A" << std::endl;
		return ;
	}
	catch(std::bad_cast &bc)
	{
	}
}

int main()
{
	srand(time(NULL));
	Base	*random ;
	for(int i = 0; i < 10; i++)
	{
		random = generate();
		identify(random);
		delete random;
	}
	return (0);
}