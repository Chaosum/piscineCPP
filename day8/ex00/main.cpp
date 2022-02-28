/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mservage <mservage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 01:09:45 by mservage          #+#    #+#             */
/*   Updated: 2022/02/28 13:29:01 by mservage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>
#include <array>
#include "easyfind.hpp"

int main(int ac, char **av)
{
	if (!ac)
		return (1);
	std::array<int, 10> A = {-1, 1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
	std::array<int, 10>::iterator it;
	if (ac == 2)
	{
		try
		{
			it = easyfind< std::array<int, 10> >(A, atoi(av[1]));
			std::cout << *it << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	try
	{
		it = easyfind< std::array<int, 10> >(A, 5);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		it = easyfind< std::array<int, 10> >(A, 10);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}