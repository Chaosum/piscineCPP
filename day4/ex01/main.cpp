/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:49:33 by mservage          #+#    #+#             */
/*   Updated: 2022/02/23 14:25:27 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main()
{
	const Animal* tab[4];

	std::cout << std::endl;
	std::cout << "DOG" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 2; i++)
	{
		std::cout << i + 1 << std::endl;
		tab[i] = new Dog();
	}
	std::cout << std::endl;
	std::cout << "CAT" << std::endl;
	std::cout << std::endl;
	for (int i = 2; i < 4; i++)
	{
		std::cout << i + 1 << std::endl;
		tab[i] = new Cat();
	}
	std::cout << std::endl;
	std::cout << "DELETE" << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << i + 1 << std::endl;
		delete tab[i];
	}
	Dog basic;
	{
	Dog tmp = basic;
	}
}