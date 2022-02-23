/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:57:53 by mservage          #+#    #+#             */
/*   Updated: 2022/02/23 14:20:10 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << std::endl;
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	delete j;
	std::cout << std::endl;
	delete i;
	std::cout << std::endl;
	delete meta;
	std::cout << std::endl;
	const WrongAnimal* wrongmeta = new WrongCat();
	const WrongAnimal* wrongi = new WrongAnimal();
	std::cout << std::endl;
	wrongmeta->makeSound();
	wrongi->makeSound();
	std::cout << std::endl;
	delete wrongi;
	std::cout << std::endl;
	delete wrongmeta;
	std::cout << std::endl;
	const WrongCat* wrong = new WrongCat();
	std::cout << std::endl;
	wrong->makeSound();
	std::cout << std::endl;
	delete wrong;
	return 0;
}